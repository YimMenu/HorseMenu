#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "core/memory/PointerCalculator.hpp"
#include "game/rdr/ScriptLocal.hpp"

#include <rage/vector.hpp>
#include <script/types.hpp>
#include <script/scrVector.hpp>


namespace Terminus::LuaJIT
{
	class LuaScriptLocalLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.class ScriptLocal
			* description
				Reads / writes script locals

			* constructor __call
			* param scriptName<string>
			* param index<integer>
			
			* constructor __call
			* param scriptHash<integer>
			* param index<integer>
			
			* operator add
			* param offset<integer>
			* return ScriptLocal
			
			* operator sub
			* param offset<integer>
			* return ScriptLocal
			
			* method At
			* param offset<integer>
			* return ScriptLocal
			
			* method At
			* param offset<integer>
			* param size<integer>
			* return ScriptLocal
			
			* method GetPointer
			* return Pointer
			
			* method ReadBool Returns false if the value interpreted as integer equals zero, otherwise true.
			* return boolean
			
			* method ReadInt
			* return integer
			
			* method ReadFloat
			* return number
			
			* method ReadVector3
			* return Vector3
			
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
			auto scrLocal = L.new_usertype<ScriptLocal>(
			    "ScriptLocal",
			    // clang-format off
				sol::call_constructor, sol::constructors<ScriptLocal(std::string_view, size_t), ScriptLocal(joaat_t, size_t)>(),

				sol::meta_method::addition, [](ScriptLocal& self, int offset) {
					return self.At(offset);
				},

				sol::meta_method::subtraction, [](ScriptLocal& self, int offset) {
					return self.At(-offset);
				},

				sol::meta_method::to_string, [](ScriptLocal& self) {
					return std::format("Local_{}", static_cast<int>(self.GetIndex()));
				},

				"At", sol::overload(
					[](ScriptLocal& self, int offset){ return self.At(offset); },
					[](ScriptLocal& self, int offset, int size){ return self.At(offset, size); }
				)
			    // clang-format on
			);

			scrLocal["GetPointer"] = [](ScriptLocal& self) {
				return PointerCalculator(self.As<void*>());
			};

			scrLocal["ReadBool"] = [](ScriptLocal& self) {
				return *self.As<int*>() == 0;
			};

			scrLocal["ReadInt"] = [](ScriptLocal& self) {
				return *self.As<int*>();
			};

			scrLocal["ReadFloat"] = [](ScriptLocal& self) {
				return *self.As<float*>();
			};

			scrLocal["ReadVector3"] = [](ScriptLocal& self) {
				return *self.As<Vector3*>();
			};

			scrLocal["WriteInt"] = [](ScriptLocal& self, int value) {
				*self.As<int*>() = value;
				return true;
			};

			scrLocal["WriteFloat"] = [](ScriptLocal& self, float value) {
				*self.As<float*>() = value;
				return true;
			};

			scrLocal["WriteVector3"] = [](ScriptLocal& self, const Vector3& value) {
				*self.As<Vector3*>() = value;
				return true;
			};
		}
	};

	LuaScriptLocalLib _LuaScriptLocalLib;
}
