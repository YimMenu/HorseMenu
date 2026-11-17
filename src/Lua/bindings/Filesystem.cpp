#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "../LuaPath.hpp"


namespace Terminus::LuaJIT
{
	class LuaFsLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		static inline fs::path GetModuleRoot(sol::state_view L)
		{
			if (auto mod = GetModuleFromLuaState(L))
				return mod->GetRoot();

			return {};
		}

		static std::tuple<bool, std::string> RemovePath(const sol::state_view& s, const LuaPath& path, bool emptyOnly = false)
		{
			if (!path.Exists())
				return std::make_tuple(false, "File not found");

			auto modRoot  = GetModuleRoot(s);
			auto modEntry = modRoot / "main.lua";
			auto& pathFs  = path.Get();

			if (pathFs == modRoot || pathFs == modEntry)
				return std::make_tuple(false, "Can not remove module's root path or entry point!");

			std::error_code ec{};
			bool success;
			if (emptyOnly)
				success = fs::remove(path.Get(), ec);
			else
				success = fs::remove_all(path.Get(), ec) > 0;

			return std::make_tuple(success, success ? "" : "An error has occured.");
		}

		static inline auto Iterator(const sol::state_view& s, const LuaPath& path)
		{
			auto iterator = std::make_shared<std::filesystem::recursive_directory_iterator>(path.Get(), fs::directory_options::skip_permission_denied);
			auto end      = std::filesystem::recursive_directory_iterator{};
			auto modRoot  = GetModuleRoot(s);

			return [iterator, end, modRoot, s]() mutable -> sol::object {
				if (*iterator == end)
					return sol::make_object(s, sol::nil);

				try
				{
					LuaPath result(modRoot, (*iterator)->path());
					++(*iterator);
					return sol::make_object(s, result);
				}
				catch (const LuaPathError& e)
				{
					luaL_error(s.lua_state(), e.what());
					return sol::make_object(s, sol::nil);
				}
			};
		};

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table Filesystem
			* description
				Provides file system functions. Paths are limited to the `scripts/` folder only.
			
			* function MyRoot Returns the module's root path.
			* return Path

			* function IterDir Recursive directory iterator.
			* param path<Path>
			* return fun(): Path

			* function Rename
			* param oldPath<Path>
			* param newPath<Path>
			* return boolean successOrFailure
			* return string failReason

			* function Remove
			* param path<Path>
			* param emptyOnly<boolean?> If true, non-empty folders will not be removed. Defaults to `true`.
			* return boolean successOrFailure
			* return string failReason
			@*/
			auto luaFs = L["Filesystem"].get_or_create<sol::table>();

			luaFs["MyRoot"] = [](sol::this_state s)
			{
				sol::state_view lua(s);
				auto modRoot = GetModuleRoot(lua);
				return LuaPath(modRoot, modRoot);
			};

			luaFs["IterDir"] = [](const LuaPath& path, sol::this_state s)
			{
				sol::state_view lua(s);
				return Iterator(lua, path);
			};

			luaFs["Rename"] = [](const LuaPath& oldPath, const LuaPath& newPath, sol::this_state s)
			{
				if (!oldPath.Exists())
					return std::make_tuple(false, "File not found");

				sol::state_view lua(s);
				auto modRoot  = GetModuleRoot(lua);
				auto modEntry = modRoot / "main.lua";
				auto& oldFs   = oldPath.Get();
				auto& newFs   = newPath.Get();

				if (oldFs == modRoot || oldFs == modEntry || newFs == modRoot || newFs == modEntry)
					return std::make_tuple(false, "Can not rename module's root path or entry point!");

				try
				{
					fs::rename(oldPath.Get(), newPath.Get());
					return std::make_tuple(true, "");
				}
				catch (const std::exception& e)
				{
					return std::make_tuple(false, e.what());
				}
			};

			luaFs["Remove"] = sol::overload(
			    [](const LuaPath& path, sol::this_state s) {
				    sol::state_view lua(s);
				    return RemovePath(lua, path, false);
			    },
			    [](const LuaPath& path, bool emptyOnly, sol::this_state s) {
				    sol::state_view lua(s);
				    return RemovePath(lua, path, emptyOnly);
			    });

			/*@terminus.class Path
			* description
				A path object limited to the `scripts/` folder

			* constructor __call
			* param path<string>
			
			* operator div
			* param other<string>
			* return Path

			* method Exists
			* return boolean

			* method IsFile
			* return boolean

			* method IsDir
			* return boolean

			* method MakeDir Creates a directory if it doesn't exist
			*

			* method MakeDirs Creates a directory and any missing parent directories
			*

			* method GetFilename
			* return string

			* method GetStem
			* return string stem The file name without the extension.

			* method GetExtension
			* return string ext The file extension including the leading dot. Ex: `.json`. Returns empty string for folders.

			* method GetFileSize
			* return integer filesz The file size in bytes.

			* method GetParent
			* return Path parentDir The parent directory. Note: This will throw if the path is outside the module's root directory.

			* method Join Joins the path with a sub-path. Does the same thing as the division operator *(__div)*: `myPath / "somefile.txt"`
			* param subPath<string>
			* return Path

			* method Open
			* param mode<openmode?>
			* return file*? File handle or nil
			* return string failReason An error message if the operation fails.

			* method ToString Returns the string representation of the path. `myPath:ToString()`, `myPath:__tostring()`, and `tostring(myPath)` all achieve the same thing.
			* return string strPath

			* method IterDir Recursive directory iterator.
			* return fun(): Path
			@*/
			auto pathCls = L.new_usertype<LuaPath>("Path",
			    sol::call_constructor, sol::factories([](const std::string& path, sol::this_state s) {
				sol::state_view Lua(s);
				    try
				    {
					    return LuaPath(GetModuleRoot(Lua), path);
				    }
				    catch (const LuaPathError& e)
				    {
					    throw sol::error(e.what());
				    }
				})
			);

			pathCls["GetExtension"] = &LuaPath::Extension;
			pathCls["GetFilename"]  = &LuaPath::Filename;
			pathCls["GetFileSize"]  = &LuaPath::Size;
			pathCls["GetParent"]    = &LuaPath::Parent;
			pathCls["GetStem"]      = &LuaPath::Stem;
			pathCls["Exists"]       = &LuaPath::Exists;
			pathCls["IsFile"]       = &LuaPath::IsFile;
			pathCls["IsDir"]        = &LuaPath::IsDir;
			pathCls["MakeDir"]      = &LuaPath::MakeDir;
			pathCls["MakeDirs"]     = &LuaPath::MakeDirs;
			pathCls["Join"]         = &LuaPath::Join;

			pathCls["Open"] = [](const LuaPath& self, std::string_view mode, sol::this_state s) {
				sol::state_view Lua(s);
				auto io                        = Lua["io"];
				sol::protected_function ioOpen = io["open"];
				return ioOpen(self.Get().filename().u8string().c_str(), mode);
			};

			pathCls["ToString"] = [](const LuaPath& self) {
				return self.Get().string();
			};

			pathCls["IterDir"] = [](const LuaPath& self, sol::this_state s) {
				sol::state_view Lua(s);
				return Iterator(Lua, self);
			};

			pathCls["__tostring"] = [](const LuaPath& self) {
				return self.Get().string();
			};

			pathCls["__eq"] = [](const LuaPath& self, const LuaPath& other) {
				return self == other;
			};

			pathCls["__div"] = [](const LuaPath& self, const std::string& sub) {
				return self.Join(sub);
			};
		}
	};

	LuaFsLib _LuaFsLib;
}
