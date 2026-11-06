import re
from pathlib import Path

ROOT = Path(__file__).parent.resolve()
TXT  = ROOT / "input.txt"
OUT  = ROOT / "output.txt"

if not TXT.is_file():
	print("Create an input.txt file next to this file and paste an ImGui enum in it (just the members, no need to include the full cpp declaration)")
	exit(0)

if TXT.stat().st_size == 0:
	print("Input file is empty! Quitting...")
	exit(0)


name_re    = re.compile(r"^(ImGui\w+)_")
member_re  = re.compile(r"^ImGui\w+_(\w+)")
comment_re = re.compile(r"^ImGui\w+_\w+.*//(.*)")

with TXT.open(encoding="utf-8", mode="r") as f:
	lines = [line.strip() for line in f if line.strip()]

	if not lines:
		exit(0)

	match = name_re.match(lines[0])
	if not match:
		raise ValueError(f"Could not determine enum name from: {lines[0]!r}")

	enum_name = match.group(1)
	members: dict[str, str] = {}

	for line in lines:
		member_match = member_re.match(line)
		comment_match = comment_re.match(line)
		if not match:
			raise ValueError(f"Could not parse enum member: {line!r}")

		member: str     = member_match.group(1)
		comment: str    = comment_match.group(1) or "" if comment_match is not None else ""
		members[member] = comment.strip().replace("*/", "* /")


# TODO: directly append to bindings/ImGuiEnums.hpp
try:
	with OUT.open("w", encoding="utf-8", newline="\n") as f:
		f.write(f"/*@terminus.enum {enum_name}")
		f.write("\n* " + "\n* ".join(f"field {field}<integer> {comment}" for field, comment in members.items()))
		f.write("\n@*/\n")
		f.write(f'L.new_enum("{enum_name}",\n\t')
		f.write(",\n\t".join(f'"{field}", {enum_name}_{field}' for field in members.keys()))
		f.write(");")
	print(f"Generated binding for {enum_name} enum at '{str(OUT)}'")
except Exception as e:
	print(f"Failed to generate enum binding. Error: {e}")
