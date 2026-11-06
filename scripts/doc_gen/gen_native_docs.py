import re
from dataclasses import dataclass, field
from pathlib import Path


@dataclass
class Param:
	name: str
	type: str


@dataclass
class Native:
	name: str
	args: list[Param] = field(default_factory=list)
	returns: list[str] = field(default_factory=list)


ROOT = Path(__file__).parent.parent.parent.resolve()
DOCS = ROOT / "docs" / "Lua API" / "LuaLS" / "Natives"

decl_re = re.compile(r"^static\s+(?P<ret>.*)\s+LUA_NATIVE_(?P<name>.*)\((?P<args>.*)\)$")
tuple_re = re.compile(r"std\:\:tuple\<(.*)\>")
lua_types = {
	"AnimScene": "integer",
	"Any": "any",
	"Blip": "integer",
	"bool": "boolean",
	"Bool": "boolean",
	"Cam": "integer",
	"char": "string",
	"Entity": "integer",
	"FireId": "integer",
	"float": "number",
	"Object": "integer",
	"Hash": "integer",
	"int": "integer",
	"Interior": "integer",
	"ItemSet": "integer",
	"Ped": "integer",
	"PersChar": "integer",
	"Pickup": "integer",
	"Player": "integer",
	"PopZone": "integer",
	"Prompt": "integer",
	"PropSet": "integer",
	"Vehicle": "integer",
	"ScrHandle": "integer",
	"sol::stack_object": "any",
	"std::string": "string",
	"uintptr_t": "integer",
	"Volume": "integer",
}


def normalize_type(_type: str) -> str:
	_type = _type.replace("const", "").replace("*", "").replace("&", "").strip()
	return lua_types.get(_type, _type)


def parse_params(params: str, native: Native):
	if not params:
		return
	
	params = params.split(sep=",")
	for p in params:
		type, _, name = p.strip().partition(" ")
		native.args.append(Param(name=name, type=normalize_type(type)))


def parse_returns(rets: str, native: Native):
	if not rets or rets == "void":
		return
	
	if rets.startswith("std::tuple"):
		re_match = tuple_re.match(rets)
		if not re_match:
			raise ValueError(f"Could not deduce return types from std::tuple: {rets}")

		retlist = re_match.group(1).split(",")
		for ret in retlist:
			native.returns.append(normalize_type(ret.strip()))
	else:
		native.returns.append(normalize_type(rets.strip()))


def parse_data() -> dict[str, list[Native]]:
	bindings = ROOT / "src" / "Lua" / "natives"
	if not bindings.is_dir():
		raise ValueError("Invalid bindings path!")

	out: dict[str, list[Native]] = {}
	for subpath in bindings.iterdir():
		if not subpath.is_file() or subpath.suffix != ".cpp":
			continue

		filename = subpath.stem
		if filename == "NativeBinding":
			continue

		out[filename] = []
		with subpath.open("r") as f:
			for line in f.readlines():
				decl = line.strip()
				if not decl.startswith("static"):
					continue

				re_match = decl_re.match(decl)
				if not re_match:
					continue

				name = re_match.group("name").strip()
				if not name:
					continue

				name   = name.removeprefix(filename + "_")	
				native = Native(name)
				args   = re_match.group("args")
				rets   = re_match.group("ret")

				parse_params(args, native)
				parse_returns(rets, native)
				out[filename].append(native)

	return out


def generate_native_docs():
	data = parse_data()
	DOCS.mkdir(exist_ok=True)

	for ns, natives in data.items():
		docpath = DOCS / (ns + ".d.lua")
		with docpath.open("w", encoding="utf-8", newline="\n") as f:
			f.write("---@meta\n\n")
			f.write(f"---@class {ns}\n")
			f.write(ns + " = {}")

			for native in natives:
				f.write("\n\n")
				
				if native.args:
					for arg in native.args:
						f.write(f"---@param {arg.name} {arg.type}\n")

				if native.returns:
					for ret in native.returns:
						f.write(f"---@return {ret}\n")

				f.write(f"function {ns}.{native.name}({", ".join(arg.name for arg in native.args)}) end")
			f.write("\n")	


generate_native_docs()
