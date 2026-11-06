# Copyright 2026 SAMURAI https://github.com/xesdoog
# License: GPL-3.0. Do whatever you want with this code.


# [[Summary]]
# Parses annotated C++ Lua bindings to generate Lua Language Server (LuaLS) stubs
# and Markdown documentation.
#
# The current configuration is project-specific. Change the paths below or add
# command-line arguments to make the generator fully project-agnostic.
#
# Annotations must use multiline comments beginning with '/*@projectName' and
# ending with '@*/'.
#
# Why parse comments instead of C++ itself using something like clang? Well,
# first and foremost, zero dependencies. More importantly, projects can expose
# Lua APIs in a multitude of different ways, making a single C++ parsing strategy
# highly impractical. This little gremlin has generated approximately 40k combined
# lines of LuaLS stubs and Markdown documentation across 3 projects: 2 using
# sol and one using Lua C API.
#
# [Supported API Types]:
#   - Tables with fields and functions.
#   - Classes with constructors, operators, fields, and methods.
#   - Enums.
#   - Loose functions, which are treated as globals and collected in the
#     Global Table documentation.
#
# [Function Overloads]
# Functions and methods can be overloaded in two ways:
#
# 1. Multiple annotations:
#
#   /*@myproject.function my_lua_function A function that does some stuff.
#   * param requiredInt<integer> A required integer.
#   * param optionalInt<integer?> An optional integer.
#   @*/
#
#   /*@myproject.function my_lua_function A function that does some stuff.
#   * param requiredInt<integer> A required integer.
#   * param nowAlsoRequired<integer> This parameter is now required.
#   * param p2<table> Blah blah blah.
#   * return boolean
#   @*/
#
# 2. The 'overload' keyword:
#
#   The overload signature is parsed as written.
#
#   /*@myproject.function my_lua_function A function that does some stuff.
#   * param requiredInt<integer> A required integer.
#   * param optionalInt<integer?> An optional integer.
#   * overload fun(requiredInt: integer, nowAlsoRequired: integer, p2: table): boolean
#   @*/
#
# [Enums]
# Lua does not have native enum types but LuaLS supports enum annotations.
# The generator distinguishes between generic enum stubs and typed enums based
# on the field annotations.
#
# 1. Generic enums:
#
#   Fields annotated with a generic 'integer' type produce a `class : integer` stub
#
#   /*@myproject.enum eExampleEnum
#   * field ZERO<integer> Zero.
#   * field ONE<integer> One.
#   * field TWO<integer> Two.
#   * field THREE<integer> Three.
#   * field SIXTY_NINE<integer> Hehe.
#   @*/
#
# 2. Typed enums:
#
#   Fields annotated with their actual integer values produce a fully defined
#   LuaLS enum with named constants. Although these definitions are stubs rather
#   than runtime implementations, they enable more precise type hints and
#   autocompletion for functions that accept the enum as an argument.
#
#   /*@myproject.enum eExampleEnum
#   * field ZERO<0> Zero.
#   * field ONE<1> One.
#   * field TWO<2> Two.
#   * field THREE<3> Three.
#   * field SIXTY_NINE<69> Hehe.
#   @*/
#
# [Descriptions]
# Description placement depends on the type of definition being annotated.
#
# Tables, classes, and enums can contain multiple members so their annotations
# use member keywords such as 'field', 'method', and 'function' to associate
# descriptions with individual members. Container-level descriptions can be
# declared separately using the 'description' keyword.
#
# Other definitions such as standalone functions take their descriptions
# directly from the definition line and do not require a separate keyword.
#
# Example:
#
#   /*@myProject.table MyFunctionTable
#   * description
#       A table containing some useful functions.
#   @*/
#
#   /*@myProject.function do_the_thing Does the most important thing ever.
#   *
#   @*/
#


import re, os, shutil
from dataclasses import dataclass, field
from pathlib import Path


@dataclass
class Parameter:
	name: str
	type: str
	description: str = ""


@dataclass
class ReturnValue:
	type: str
	description: str = ""


@dataclass
class ApiMember:
	kind: str
	name: str
	owner: str | None = None
	description: str = ""
	type: str | None = None
	parameters: list[Parameter] = field(default_factory=list)
	returns: list[ReturnValue] = field(default_factory=list)
	overloads: list[str] = field(default_factory=list)


@dataclass
class ApiLibrary:
	name: str
	kind: str  # "class" | "table" | "enum"
	base_class: str = None
	description: str = ""
	is_typed_enum: bool = False
	members: list[ApiMember] = field(default_factory=list)


@dataclass
class ApiModel:
	libraries: list[ApiLibrary] = field(default_factory=list)


NAMESPACES: list[str] = []
UNRESOLVED_MEMBERS: list[ApiMember] = []
GLOBAL_TABLE: ApiLibrary = ApiLibrary(name="Global Table", kind="table") # _G / _ENV we can define loose global functions in any file. see bindings/log.cpp for an example
ANNOTATION_RE = re.compile(r"/\*\s?@terminus\.(?P<header>.+?)[\r\n](?P<body>.*?)[\r\n]\s*@\*/", re.DOTALL,)
HEADER_RE = re.compile(r"^(?P<kind>\w+)\s+(?P<name>\S+)(?:\s+?\:\s+(?P<baseclass>\w+))?(?:\s+(?P<description>.*))?.*$")
PARAM_RE = re.compile(r"^(?P<name>[^<\s]+)<(?P<type>[^>]+)>(?:\s+(?P<description>.*))?$")
LUA_REF_RE = re.compile(r"(lua://(\w+))")

GROUPED_DEFS = {
	"LuaImDrawList" : "ImGui",
	"LuaImGui" : "ImGui",
	"ImGuiEnums" : "ImGui/Enums",
}


def clear_dir(dir: Path, ignoreNames: tuple[str] = None):
	for p in dir.iterdir():
		if ignoreNames and p.name in ignoreNames:
			continue

		shutil.rmtree(str(p), ignore_errors=True) # don't care, this is just to keep the docs clean on Github


def clean_line(line: str) -> str:
	line = line.strip()
	if line.startswith("*"):
		line = line[1:].lstrip()

	return line


def split_member_name(name: str) -> tuple[str | None, str, str | None]:
	if "." not in name:
		return None, name

	owner, member = name.rsplit(".", 1)
	if not owner or not member:
		raise ValueError(f"Invalid member name: {name!r}")

	return owner, member


def parse_field(value: str, owner: ApiLibrary = None) -> ApiMember:
	match = PARAM_RE.match(value.strip())
	if not match:
		raise ValueError(f"Invalid field declaration: {value!r}")

	name = match.group("name")
	type = match.group("type")
	if owner and owner.kind == "enum":
		try:
			int(type)
			owner.is_typed_enum = True
		except:
			pass

	return ApiMember(
		kind="field",
		name=name,
		type=type,
		description=(match.group("description") or "").strip(),
	)


def parse_param(value: str) -> Parameter:
	match = PARAM_RE.match(value.strip())
	if not match:
		raise ValueError(f"Invalid parameter declaration: {value!r}")

	return Parameter(
		name=match.group("name"),
		type=match.group("type"),
		description=(match.group("description") or "").strip(),
	)


def parse_return(value: str) -> ReturnValue:
	"""
	Return syntax is currently:

		return Pointer
		return integer address The memory address.

		Notice the word address between the type and the description, 
		that's because LuaLS uses the first word after the type as the name of the return.
	"""

	parts = value.strip().split(maxsplit=1)
	if not parts:
		raise ValueError("Return declaration has no type")

	return ReturnValue(
		type=parts[0],
		description=parts[1].strip() if len(parts) > 1 else "",
	)


def parse_annotation(header: str, body: str) -> ApiMember | ApiLibrary:
	header_match = HEADER_RE.match(header.strip())
	if not header_match:
		raise ValueError(f"Invalid annotation header: {header!r}")

	kind = header_match.group("kind")
	name = header_match.group("name")
	base = header_match.group("baseclass")
	owner = None

	if kind not in {"class", "table", "enum"}:
		owner, name = split_member_name(name)
		result = ApiMember(kind=kind, name=name, owner=owner, description=header_match.group("description"))
	else:
		result = ApiLibrary(name=name, kind=kind, base_class=base)

	lines = [clean_line(line) for line in body.splitlines()]
	description_lines = []
	in_description = False
	current_owner = result if isinstance(result, ApiLibrary) else None
	current_member = result if isinstance(result, ApiMember) else None

	for line in lines:
		if not line:
			if in_description:
				description_lines.append("")
			continue

		if line == "description":
			in_description = True
			continue

		if in_description:
			if re.match(r"^(constructor|operator|method|function|table|class|field|param|return|type)\b", line):
				in_description = False
			else:
				description_lines.append(line)
				continue

		member_match = re.match(r"^(constructor|operator|method|function|field)\s+?(.*?)$", line)
		if member_match:
			kind = member_match.group(1)
			declaration = (member_match.group(2) or "").strip()

			if kind == "field":
				current_member = parse_field(declaration, current_owner)
			else:
				member_name, _, maybe_desc = declaration.partition(" ")
				current_member = ApiMember(
					kind=kind,
					name=member_name,
					description=maybe_desc,
				)

			result.members.append(current_member)
			continue

		if current_member:
			if line.startswith("param "):
				current_member.parameters.append(parse_param(line[6:]))
				continue

			if line.startswith("return "):
				current_member.returns.append(parse_return(line[7:]))
				continue

			if line.startswith("overload ") and kind in ("function", "method"):
				current_member.overloads.append(line[9:])
				continue

	if kind in {"class", "table", "enum"}:
		result.description = "\n".join(description_lines).strip()
	return result


def resolve_members(model: ApiModel) -> None:
	libraries = { lib.name: lib for lib in model.libraries }

	for member in UNRESOLVED_MEMBERS:
		library = libraries.get(member.owner) or GLOBAL_TABLE
		library.members.append(member)

	UNRESOLVED_MEMBERS.clear()


def parse_source(source: str) -> ApiModel:
	model = ApiModel()

	for match in ANNOTATION_RE.finditer(source):
		header = match.group("header")
		body   = match.group("body")
		item   = parse_annotation(header, body)

		if isinstance(item, ApiLibrary):
			model.libraries.append(item)

		elif isinstance(item, ApiMember):
			UNRESOLVED_MEMBERS.append(item)

	resolve_members(model)
	return model


def parse_typed_enum(lib: ApiLibrary):
	if not lib.is_typed_enum:
		raise ValueError("Library is not a typed enum!")

	out = f"---@enum {lib.name}\n{lib.name} = {{"
	for member in lib.members:
		if member.kind != "field":
			continue
		
		out += f"\n\t{member.name} = {member.type}"
		if member.description:
			out += f", -- {member.description}"
		else:
			out += ","

	out += "\n}\n"
	return out


def parse_lib(lib: ApiLibrary):
	methods: list[ApiMember] = []
	out = ""

	if lib.name != "Global Table":
		if lib.description:
			out += f"-- {"\n-- ".join(line for line in lib.description.split("\n"))}\n"
		
		out += f"---@class {lib.name}"
		if lib.base_class:
			out += f" : {lib.base_class}"
		elif lib.kind == "enum":
			out += " : integer"

		out += "\n"

	for member in lib.members:
		if member.kind in ("function", "method"):
			methods.append(member)
		elif member.kind == "operator":
			out += f"---@operator {member.name}({"| ".join(p.type for p in member.parameters)}): {member.returns[0].type}\n"
		elif member.kind == "field":
			field_type = member.type or "any"
			description = member.description or ""
			out += f"---@field {member.name} {field_type} {description}\n"
		elif member.kind == "constructor":
			if member.name == "__call":
				out += f"---@overload fun({", ".join(f"{p.name}: {p.type}" for p in member.parameters)}): {lib.name}\n"
			else:
				methods.append(member)

	if lib.name != "Global Table":
		out += f"{lib.name} = {{}}\n\n"

	index_char = ":" if lib.kind == "class" else "."
	for method in methods:
		if method.description:
			out += f"-- {"\n--\n-- ".join(l for l in method.description.split("~~"))}\n"

		for sig in method.overloads:
			out += f"---@overload {sig}\n"

		for p in method.parameters:
			out += f"---@param {p.name} {p.type} {p.description}\n"

		for r in method.returns:
			out += f"---@return {r.type} {r.description}\n"

		prefix = lib.name + index_char if lib.name != "Global Table" else ""
		out += f"function {prefix}{method.name}({", ".join(p.name for p in method.parameters)}) end\n\n"

	return out


def parse_lua(lib: ApiLibrary, write_path: Path):
	docstring = "---@meta\n\n"

	if lib.is_typed_enum:
		docstring += parse_typed_enum(lib)
	else:
		docstring += parse_lib(lib)

	libpath = write_path / (lib.name + ".d.lua")
	with libpath.open(mode="w", encoding="utf-8", newline="\n") as f:
		f.write(docstring.strip() + "\n")


def gen_luals_stubs(model: ApiModel, docs_path: Path):
	libs = model.libraries
	if not libs:
		return

	docs_path.mkdir(parents=True, exist_ok=True)

	for lib in libs:
		parse_lua(lib, docs_path)


def md_fix_ref(value: str) -> str:
	return re.sub(LUA_REF_RE, r"./\2.md", value)


def md_escape(value: str) -> str:
	return md_fix_ref(value).replace("|", "\\|").replace("\n", " ")


def md_description(description: str) -> str:
	if not description:
		return ""

	paragraphs = [paragraph.strip() for paragraph in description.split("~~") if paragraph.strip()]
	return md_fix_ref("\n\n".join(paragraphs))


def md_type(type_name: str) -> str:
	return f"`{type_name}`"


def md_params(parameters: list[Parameter]) -> str:
	if not parameters:
		return ""

	output = [
		"### Parameters",
		"",
		"| Name | Type | Description |",
		"| --- | --- | --- |",
	]

	for param in parameters:
		description = md_escape(param.description)
		output.append(f"| `{param.name}` | {md_type(param.type)} | {description} |")

	return "\n".join(output)


def md_returns(returns: list[ReturnValue]) -> str:
	if not returns:
		return ""

	output = [
		"### Returns",
		"",
		"| Type | Description |",
		"| --- | --- |",
	]

	for ret in returns:
		description = md_escape(ret.description)
		output.append(f"| {md_type(ret.type)} | {description} |")

	return "\n".join(output)


def md_method(method: ApiMember, lib: ApiLibrary) -> str:
	index_char = ":" if lib.kind == "class" else "."
	params = ", ".join(f"{param.name}" for param in method.parameters)
	prefix = lib.name + index_char if lib.name != "Global Table" else ""
	signature = f"{prefix}{method.name}({params})"
	output = [
		f"## `{method.name}`",
		"",
		"```lua",
		f"function {signature} end",
		"```",
	]

	description = md_description(method.description)
	if description:
		output.extend(["", description])

	params_doc = md_params(method.parameters)
	if params_doc:
		output.extend(["", params_doc])

	returns_doc = md_returns(method.returns)
	if returns_doc:
		output.extend(["", returns_doc])

	return "\n".join(output)


def md_operator(operator: ApiMember) -> str:
	params = " | ".join(param.type for param in operator.parameters)

	return_type = (operator.returns[0].type if operator.returns else "any")
	output = [
		f"### `{operator.name}`",
		"",
		"```lua",
		f"---@operator __{operator.name}({params}): {return_type}",
		"```",
	]

	description = md_description(operator.description)
	if description:
		output.extend(["", description])

	return "\n".join(output)


def md_field(field: ApiMember) -> str:
	field_type = field.type or "any"

	return (
		f"| `{field.name}` | {md_type(field_type)} | "
		f"{md_escape(field.description)} |"
	)


def parse_markdown(lib: ApiLibrary, write_path: Path):
	docstring = f"<!-- markdownlint-disable -->\n\n# {lib.name}\n\n"
	description = md_description(lib.description)
	if description:
		docstring += description + "\n\n"

	methods: list[ApiMember] = []
	operators: list[ApiMember] = []
	fields: list[ApiMember] = []
	constructors: list[ApiMember] = []

	for member in lib.members:
		if member.kind in ("function", "method"):
			methods.append(member)
		elif member.kind == "operator":
			operators.append(member)
		elif member.kind == "field":
			fields.append(member)
		elif member.kind == "constructor":
			constructors.append(member)

	if constructors and lib.name != "Global Table":
		docstring += "## Constructors\n\n"
		for constructor in constructors:
			if constructor.name == "__call":
				params = ", ".join(param.name for param in constructor.parameters)
				docstring += ("```lua\n" f"{lib.name}({params})\n" "```\n")
			else:
				docstring += md_method(constructor, lib) + "\n"

			description = md_description(constructor.description)
			if description:
				docstring += f"\n{description}\n"

			params_doc = md_params(constructor.parameters)
			if params_doc:
				docstring += f"\n{params_doc}\n"

	if operators:
		docstring += "## Operators\n\n"
		for operator in operators:
			docstring += md_operator(operator)
			docstring += "\n\n"

	if fields:
		docstring += "## Fields\n\n"
		docstring += (
			"| Name | Type | Description |\n"
			"| --- | --- | --- |\n"
		)

		for field in fields:
			docstring += md_field(field) + "\n"

		docstring += "\n"

	if methods:
		docstring += "## Methods\n\n"
		for method in methods:
			docstring += md_method(method, lib)
			docstring += "\n\n"

	libpath = write_path / f"{lib.name}.md"
	with libpath.open(mode="w", encoding="utf-8", newline="\n") as f:
		f.write(docstring.strip() + "\n")


def gen_markdown_docs(model: ApiModel, docs_path: Path):
	if not model.libraries:
		return

	docs_path.mkdir(parents=True, exist_ok=True)

	for lib in model.libraries:
		parse_markdown(lib, docs_path)


if __name__ == "__main__":
	root = Path(__file__).parent.parent.parent.resolve()
	headers = root / "src" / "Lua" / "bindings"
	if not headers.exists() or not headers.is_dir():
		print(f"Invaid headers path: '{headers}'")
		exit(1)

	api_root   = root / "docs" / "Lua API"
	luals_root = api_root / "LuaLS"
	md_root    = api_root / "Docs"
	
	if not luals_root.exists() or not luals_root.is_dir():
		try:
			luals_root.mkdir(parents=True, exist_ok=True)
		except Exception as e:
			print(f"Failed to create language definitions folder: {e}")
			exit(1)

	if not md_root.exists() or not md_root.is_dir():
		try:
			md_root.mkdir(parents=True, exist_ok=True)
		except Exception as e:
			print(f"Failed to create markdown docs folder: {e}")
			exit(1)

	clear_dir(luals_root, ignoreNames=("Natives"))
	clear_dir(md_root)

	for p in headers.iterdir():
		if not p.is_file() or p.suffix != ".cpp":
			continue

		lua_out = luals_root
		md_out  = md_root
		sub     = GROUPED_DEFS.get(p.stem)
		if sub:
			lua_out /= sub
			md_out /= sub

		api = parse_source(p.read_text())
		gen_luals_stubs(api, lua_out)
		gen_markdown_docs(api, md_out)

	_G = ApiModel()
	_G.libraries.append(GLOBAL_TABLE)
	gen_luals_stubs(_G, luals_root)
	gen_markdown_docs(_G, md_root)
