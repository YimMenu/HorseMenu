#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "core/memory/PointerCalculator.hpp"

#include <rage/vector.hpp>
#include <script/types.hpp>
#include <script/scrVector.hpp>


namespace Terminus::LuaJIT
{
	class LuaScriptGlobalLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.class ScriptGlobal
			* description
				Reads / writes script globals

			* constructor __call
			* param index<integer>
			
			* operator add
			* param offset<integer>
			* return ScriptGlobal
			
			* operator sub
			* param offset<integer>
			* return ScriptGlobal
			
			* method CanAccess
			* param muliplayer<boolean?>
			* return boolean
			
			* method At
			* param offset<integer>
			* return ScriptGlobal
			
			* method At
			* param offset<integer>
			* param size<integer>
			* return ScriptGlobal
			
			* method GetPointer
			* return Pointer
			
			* method ReadString
			* return string
			
			* method ReadBool Returns false if the value interpreted as integer equals zero, otherwise true.
			* return boolean
			
			* method ReadInt
			* return integer
			
			* method ReadFloat
			* return number
			
			* method ReadVector3
			* return Vector3
			
			* method WriteString
			* param value<string>
			* param maxLength<integer?> Optional maximum length. If provided and the string's size is less than this value, the difference will be padded with null terminators.
			* return boolean success
			
			* method WriteInt
			* param value<integer>
			* return boolean success
			
			* method WriteFloat
			* param value<number>
			* return boolean success
			
			* method WriteVector3
			* param value<Vector3>
			* return boolean success
			@*/
			auto scriptGlobal = L.new_usertype<ScriptGlobal>(
			    "ScriptGlobal",
			    // clang-format off
				sol::call_constructor, sol::constructors<ScriptGlobal(size_t)>(),

				sol::meta_method::addition, [](ScriptGlobal& self, int offset) {
					return self.At(offset);
				},

				sol::meta_method::subtraction, [](ScriptGlobal& self, int offset) {
					return self.At(-offset);
				},

				sol::meta_method::to_string, [](ScriptGlobal& self) {
					return std::format("Global_{}", static_cast<int>(self.GetIndex()));
				},

				"CanAccess", &ScriptGlobal::CanAccess,

				"At", sol::overload(
					[](ScriptGlobal& self, int offset){ return self.At(offset); },
					[](ScriptGlobal& self, int offset, int size){ return self.At(offset, size); }
				)
				// clang-format on
			);

			scriptGlobal["GetPointer"] = [](ScriptGlobal& self) {
				return PointerCalculator(self.CanAccess() ? self.As<void*>() : nullptr);
			};

			scriptGlobal["ReadString"] = [](ScriptGlobal& self) {
				return self.CanAccess() ? *self.As<std::string*>() : std::string();
			};

			scriptGlobal["ReadBool"] = [](ScriptGlobal& self) {
				return self.CanAccess() ? (*self.As<int*>() == 0) : false;
			};

			scriptGlobal["ReadInt"] = [](ScriptGlobal& self) {
				return self.CanAccess() ? *self.As<int*>() : 0;
			};

			scriptGlobal["ReadFloat"] = [](ScriptGlobal& self) {
				return self.CanAccess() ? *self.As<float*>() : 0.f;
			};

			scriptGlobal["ReadVector3"] = [](ScriptGlobal& self) {
				return self.CanAccess() ? *self.As<Vector3*>() : Vector3(0, 0, 0);
			};

			scriptGlobal["WriteString"] = [](ScriptGlobal& self, const std::string& value, sol::optional<int> maxLength) {
				if (!self.CanAccess())
					return false;

				if (maxLength && maxLength.value() <= 0)
					return false;

				const size_t mx = maxLength ? static_cast<size_t>(maxLength.value()) : value.size() + 1;
				char* dst       = self.As<char*>();
				const size_t sz = std::min(value.size(), mx - 1);
				if (sz > 0)
					memcpy(dst, value.data(), sz);

				dst[sz] = '\0';

				if (sz + 1 < mx)
					memset(dst + sz + 1, 0, mx - sz - 1);

				return true;
			};

			scriptGlobal["WriteInt"] = [](ScriptGlobal& self, int value) {
				if (!self.CanAccess())
					return false;

				*self.As<int*>() = value;
				return true;
			};

			scriptGlobal["WriteFloat"] = [](ScriptGlobal& self, float value) {
				if (!self.CanAccess())
					return false;

				*self.As<float*>() = value;
				return true;
			};

			scriptGlobal["WriteVector3"] = [](ScriptGlobal& self, const Vector3& value) {
				if (!self.CanAccess())
					return false;

				*self.As<Vector3*>() = value;
				return true;
			};
		}
	};

	LuaScriptGlobalLib _LuaScriptGlobalLib;
}
