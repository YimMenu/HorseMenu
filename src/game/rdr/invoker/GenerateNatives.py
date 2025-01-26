from enum import global_enum_repr
import json

natives = {}
current_idx = 0
hash_list = []

class Arg:
    def __init__(self, name: str, type: str):
        self.name = name.replace("...", "varargs")
        self.type = type.replace("Any*", "void*")

        if (self.type == ""):
            self.type = "Args&&..."

    def __str__(self) -> str:
        return str(self.type) + " " + str(self.name)

class NativeFunc:
    def __init__(self, namespace: str, name: str, hash: int, args: list[dict], return_type: str):
        global current_idx, hash_list

        self.namespace = namespace
        self.name = name
        self.hash = hash
        self.args: list[Arg] = []
        self.return_type = return_type.replace("Any*", "void*")
        self.native_index = current_idx
        self.variadic = False
        current_idx += 1
        hash_list.append(hash)

        self.fix_vectors = "false"

        for arg in args:
            if (arg["name"] == "..."):
                self.variadic = True
            if arg["type"] == "Vector3*":
                self.fix_vectors = "true"
            self.args.append(Arg(arg["name"], arg["type"]))
    
    def get_native_def_str(self) -> str:
        assert self.native_index != -1

        param_decl = ""
        param_pass = ""
        if len(self.args) > 0:
            for arg in self.args:
                param_decl += str(arg) + ", "
                if arg.name == "varargs":
                    param_pass += arg.name + "..., "
                else:
                    param_pass += arg.name + ", "
            param_decl = param_decl[:-2]
            param_pass = param_pass[:-2]
        
        var_template = ""
        if self.variadic:
            var_template = "template <typename... Args> "

        return f"{var_template}FORCEINLINE constexpr {self.return_type} {self.name}({param_decl}) {{ return YimMenu::NativeInvoker::Invoke<{self.native_index}, {self.return_type}, {self.fix_vectors}>({param_pass}); }}"
    
def load_natives_data():
    global natives

    data = json.load(open("natives.json"))
    for ns, natives_list in data.items():
        natives[ns] = []
        for hash_str, native_data in natives_list.items():
            natives[ns].append(NativeFunc(ns, native_data["name"], int(hash_str, 16), native_data["params"], native_data["return_type"]))

def write_crossmap_header():
        open("Crossmap.hpp", "w+").write(f"""#pragma once
#include <script/scrNativeHandler.hpp>

namespace YimMenu
{{
	constexpr std::array<rage::scrNativeHash, {len(hash_list)}> g_Crossmap = {{{",".join([f"0x{x:X}" for x in hash_list])}}};
}}
""")

def write_natives_header():
    natives_buf = ""
    natives_index_buf = ""

    for ns, nvs in natives.items():
        natives_buf += f"namespace {ns}\n{{\n"
        for nat_data in nvs:
            if nat_data.native_index == -1:
                continue

            natives_buf += f"\t{nat_data.get_native_def_str()}\n"
            natives_index_buf += f"\t{nat_data.name} = {nat_data.native_index},\n"
        natives_buf += "}\n\n"
    
    natives_buf = natives_buf[:-2]

    open("../Natives.hpp", "w+").write(f"""#pragma once
#include "invoker/invoker.hpp"

// clang-format off
enum class NativeIndex
{{
{natives_index_buf}}};

{natives_buf}
// clang-format on
""")
    
if __name__ == "__main__":
    load_natives_data()
    write_crossmap_header()
    write_natives_header()