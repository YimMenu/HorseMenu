#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static float LUA_NATIVE_FLOCK_GET_SPECIES_TUNING_FLOAT_PARAM(Hash p0, int p1, int p2)
	{
		auto retval = FLOCK::GET_SPECIES_TUNING_FLOAT_PARAM(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_FLOCK_SET_SPECIES_TUNING_FLOAT_PARAM(Hash p0, int p1, int p2, float p3)
	{
		FLOCK::SET_SPECIES_TUNING_FLOAT_PARAM(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_FLOCK_SET_SPECIES_TUNING_BOOL_PARAM(Hash p0, int p1, int p2, bool p3)
	{
		FLOCK::SET_SPECIES_TUNING_BOOL_PARAM(p0, p1, p2, p3);
	}

	static float LUA_NATIVE_FLOCK_GET_ANIMAL_TUNING_FLOAT_PARAM(Ped animal, int index)
	{
		auto retval = FLOCK::GET_ANIMAL_TUNING_FLOAT_PARAM(animal, index);
		return retval;
	}

	static void LUA_NATIVE_FLOCK_SET_ANIMAL_TUNING_FLOAT_PARAM(Ped animal, int index, float value)
	{
		FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(animal, index, value);
	}

	static void LUA_NATIVE_FLOCK_RESET_ANIMAL_TUNING_FLOAT_PARAM(Ped animal, int index)
	{
		FLOCK::RESET_ANIMAL_TUNING_FLOAT_PARAM(animal, index);
	}

	static bool LUA_NATIVE_FLOCK_GET_ANIMAL_TUNING_BOOL_PARAM(Ped animal, int index)
	{
		auto retval = (bool)FLOCK::GET_ANIMAL_TUNING_BOOL_PARAM(animal, index);
		return retval;
	}

	static void LUA_NATIVE_FLOCK_SET_ANIMAL_TUNING_BOOL_PARAM(Ped animal, int index, bool value)
	{
		FLOCK::SET_ANIMAL_TUNING_BOOL_PARAM(animal, index, value);
	}

	static void LUA_NATIVE_FLOCK_RESET_ANIMAL_TUNING_BOOL_PARAM(Ped animal, int index)
	{
		FLOCK::RESET_ANIMAL_TUNING_BOOL_PARAM(animal, index);
	}

	static Any LUA_NATIVE_FLOCK__0x8049B17BEC937662(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = FLOCK::_0x8049B17BEC937662(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static Any LUA_NATIVE_FLOCK__0xE93415B3307208E5(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8)
	{
		auto retval = FLOCK::_0xE93415B3307208E5(p0, p1, p2, p3, p4, p5, p6, p7, p8);
		return retval;
	}

	static Any LUA_NATIVE_FLOCK__0x19870C40C7EE15BE(Any p0, Any p1)
	{
		auto retval = FLOCK::_0x19870C40C7EE15BE(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0x0816C31480764AB0(Any p0, Any p1, Any p2, Any p3)
	{
		FLOCK::_0x0816C31480764AB0(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_FLOCK__0xC3D581A34BC0A1F0(Any p0, Any p1)
	{
		FLOCK::_0xC3D581A34BC0A1F0(p0, p1);
	}

	static void LUA_NATIVE_FLOCK__0xF2CCA7B68CFAB2B9(Hash species, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float p10, float p11, float p12, float p13)
	{
		FLOCK::_0xF2CCA7B68CFAB2B9(species, x1, y1, z1, x2, y2, z2, x3, y3, z3, p10, p11, p12, p13);
	}

	static void LUA_NATIVE_FLOCK__0xFB16F08F47B83B4C(Any p0)
	{
		FLOCK::_0xFB16F08F47B83B4C(p0);
	}

	static bool LUA_NATIVE_FLOCK__GET_ANIMAL_IS_WILD(Ped ped)
	{
		auto retval = (bool)FLOCK::_GET_ANIMAL_IS_WILD(ped);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__SET_ANIMAL_IS_WILD(Ped ped, bool toggle)
	{
		FLOCK::_SET_ANIMAL_IS_WILD(ped, toggle);
	}

	static int LUA_NATIVE_FLOCK__GET_ANIMAL_RARITY(Ped ped)
	{
		auto retval = FLOCK::_GET_ANIMAL_RARITY(ped);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__SET_ANIMAL_RARITY(Ped ped, int rarityLevel)
	{
		FLOCK::_SET_ANIMAL_RARITY(ped, rarityLevel);
	}

	static void LUA_NATIVE_FLOCK__0xFF1E339CE40EAAAF(Any p0, Any p1)
	{
		FLOCK::_0xFF1E339CE40EAAAF(p0, p1);
	}

	static bool LUA_NATIVE_FLOCK__IS_HERD_VALID(ScrHandle herdHandle)
	{
		auto retval = (bool)FLOCK::_IS_HERD_VALID(herdHandle);
		return retval;
	}

	static ScrHandle LUA_NATIVE_FLOCK__CREATE_HERD()
	{
		auto retval = FLOCK::_CREATE_HERD();
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0xE0961AED72642B80(Any p0)
	{
		FLOCK::_0xE0961AED72642B80(p0);
	}

	static void LUA_NATIVE_FLOCK__ADD_PED_TO_FLOCK(Any p0, Ped ped)
	{
		FLOCK::_ADD_PED_TO_FLOCK(p0, ped);
	}

	static void LUA_NATIVE_FLOCK__0x408D1149C5E39C1E(Any p0, Any p1)
	{
		FLOCK::_0x408D1149C5E39C1E(p0, p1);
	}

	static Any LUA_NATIVE_FLOCK__0x9E13ACC38BA8F9C3(Any p0, Any p1)
	{
		auto retval = FLOCK::_0x9E13ACC38BA8F9C3(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_FLOCK__0x34B9C4D86DF2C2F3(Any p0)
	{
		auto retval = FLOCK::_0x34B9C4D86DF2C2F3(p0);
		return retval;
	}

	static Vector3 LUA_NATIVE_FLOCK__0x1DA6CB02071055D5(Any p0)
	{
		auto retval = FLOCK::_0x1DA6CB02071055D5(p0);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0xC95611869E14F8AF(Any p0, Any p1, Any p2, Any p3)
	{
		FLOCK::_0xC95611869E14F8AF(p0, p1, p2, p3);
	}

	static Any LUA_NATIVE_FLOCK__0x09EE00B8F858E0BE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = FLOCK::_0x09EE00B8F858E0BE(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0xE36D2CB540597EF7(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		FLOCK::_0xE36D2CB540597EF7(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static Any LUA_NATIVE_FLOCK__0xD95F04A4E73BE85E(Any p0, Any p1)
	{
		auto retval = FLOCK::_0xD95F04A4E73BE85E(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0x17E3E5C46ECCD308(Any p0, Any p1, Any p2)
	{
		FLOCK::_0x17E3E5C46ECCD308(p0, p1, p2);
	}

	static void LUA_NATIVE_FLOCK__0xC72CE37081DAE625(Any p0, Any p1, Any p2, Any p3)
	{
		FLOCK::_0xC72CE37081DAE625(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_FLOCK__0x67A43EA3F6FE0076(Any p0)
	{
		FLOCK::_0x67A43EA3F6FE0076(p0);
	}

	static Any LUA_NATIVE_FLOCK__0x36486AF7DA93A464(Any p0)
	{
		auto retval = FLOCK::_0x36486AF7DA93A464(p0);
		return retval;
	}

	static void LUA_NATIVE_FLOCK__0x6C57BEA886A20C6B(Any p0, Any p1)
	{
		FLOCK::_0x6C57BEA886A20C6B(p0, p1);
	}

	static void LUA_NATIVE_FLOCK__0x1520626FFAFFFA8F(Any p0, Any p1)
	{
		FLOCK::_0x1520626FFAFFFA8F(p0, p1);
	}

	static void LUA_NATIVE_FLOCK__0xFA821997794F48E7(Any p0, Any p1, Any p2)
	{
		FLOCK::_0xFA821997794F48E7(p0, p1, p2);
	}

	static void LUA_NATIVE_FLOCK__0xCC6B5AAFC87BFC7B(Any p0, Any p1, Any p2)
	{
		FLOCK::_0xCC6B5AAFC87BFC7B(p0, p1, p2);
	}

	static void LUA_NATIVE_FLOCK__0xFDB008B3BCF5992F(Any p0, Any p1, Any p2)
	{
		FLOCK::_0xFDB008B3BCF5992F(p0, p1, p2);
	}

	static void LUA_NATIVE_FLOCK__0x2DF3D457D86F8E57(Any p0, Any p1)
	{
		FLOCK::_0x2DF3D457D86F8E57(p0, p1);
	}

	static void LUA_NATIVE_FLOCK__0x706B434FEFAD6A24(Any p0)
	{
		FLOCK::_0x706B434FEFAD6A24(p0);
	}

	static void LUA_NATIVE_FLOCK__0xA881F5C77A560906(Any p0)
	{
		FLOCK::_0xA881F5C77A560906(p0);
	}

	static Any LUA_NATIVE_FLOCK__0x53187E563F938E76(Any p0)
	{
		auto retval = FLOCK::_0x53187E563F938E76(p0);
		return retval;
	}

	void RegisterNatives_FLOCK(sol::state& L)
	{
		auto FLOCK = L["FLOCK"].get_or_create<sol::table>();
		FLOCK.set_function("GET_SPECIES_TUNING_FLOAT_PARAM", LUA_NATIVE_FLOCK_GET_SPECIES_TUNING_FLOAT_PARAM);
		FLOCK.set_function("SET_SPECIES_TUNING_FLOAT_PARAM", LUA_NATIVE_FLOCK_SET_SPECIES_TUNING_FLOAT_PARAM);
		FLOCK.set_function("SET_SPECIES_TUNING_BOOL_PARAM", LUA_NATIVE_FLOCK_SET_SPECIES_TUNING_BOOL_PARAM);
		FLOCK.set_function("GET_ANIMAL_TUNING_FLOAT_PARAM", LUA_NATIVE_FLOCK_GET_ANIMAL_TUNING_FLOAT_PARAM);
		FLOCK.set_function("SET_ANIMAL_TUNING_FLOAT_PARAM", LUA_NATIVE_FLOCK_SET_ANIMAL_TUNING_FLOAT_PARAM);
		FLOCK.set_function("RESET_ANIMAL_TUNING_FLOAT_PARAM", LUA_NATIVE_FLOCK_RESET_ANIMAL_TUNING_FLOAT_PARAM);
		FLOCK.set_function("GET_ANIMAL_TUNING_BOOL_PARAM", LUA_NATIVE_FLOCK_GET_ANIMAL_TUNING_BOOL_PARAM);
		FLOCK.set_function("SET_ANIMAL_TUNING_BOOL_PARAM", LUA_NATIVE_FLOCK_SET_ANIMAL_TUNING_BOOL_PARAM);
		FLOCK.set_function("RESET_ANIMAL_TUNING_BOOL_PARAM", LUA_NATIVE_FLOCK_RESET_ANIMAL_TUNING_BOOL_PARAM);
		FLOCK.set_function("_0x8049B17BEC937662", LUA_NATIVE_FLOCK__0x8049B17BEC937662);
		FLOCK.set_function("_0xE93415B3307208E5", LUA_NATIVE_FLOCK__0xE93415B3307208E5);
		FLOCK.set_function("_0x19870C40C7EE15BE", LUA_NATIVE_FLOCK__0x19870C40C7EE15BE);
		FLOCK.set_function("_0x0816C31480764AB0", LUA_NATIVE_FLOCK__0x0816C31480764AB0);
		FLOCK.set_function("_0xC3D581A34BC0A1F0", LUA_NATIVE_FLOCK__0xC3D581A34BC0A1F0);
		FLOCK.set_function("_0xF2CCA7B68CFAB2B9", LUA_NATIVE_FLOCK__0xF2CCA7B68CFAB2B9);
		FLOCK.set_function("_0xFB16F08F47B83B4C", LUA_NATIVE_FLOCK__0xFB16F08F47B83B4C);
		FLOCK.set_function("_GET_ANIMAL_IS_WILD", LUA_NATIVE_FLOCK__GET_ANIMAL_IS_WILD);
		FLOCK.set_function("_SET_ANIMAL_IS_WILD", LUA_NATIVE_FLOCK__SET_ANIMAL_IS_WILD);
		FLOCK.set_function("_GET_ANIMAL_RARITY", LUA_NATIVE_FLOCK__GET_ANIMAL_RARITY);
		FLOCK.set_function("_SET_ANIMAL_RARITY", LUA_NATIVE_FLOCK__SET_ANIMAL_RARITY);
		FLOCK.set_function("_0xFF1E339CE40EAAAF", LUA_NATIVE_FLOCK__0xFF1E339CE40EAAAF);
		FLOCK.set_function("_IS_HERD_VALID", LUA_NATIVE_FLOCK__IS_HERD_VALID);
		FLOCK.set_function("_CREATE_HERD", LUA_NATIVE_FLOCK__CREATE_HERD);
		FLOCK.set_function("_0xE0961AED72642B80", LUA_NATIVE_FLOCK__0xE0961AED72642B80);
		FLOCK.set_function("_ADD_PED_TO_FLOCK", LUA_NATIVE_FLOCK__ADD_PED_TO_FLOCK);
		FLOCK.set_function("_0x408D1149C5E39C1E", LUA_NATIVE_FLOCK__0x408D1149C5E39C1E);
		FLOCK.set_function("_0x9E13ACC38BA8F9C3", LUA_NATIVE_FLOCK__0x9E13ACC38BA8F9C3);
		FLOCK.set_function("_0x34B9C4D86DF2C2F3", LUA_NATIVE_FLOCK__0x34B9C4D86DF2C2F3);
		FLOCK.set_function("_0x1DA6CB02071055D5", LUA_NATIVE_FLOCK__0x1DA6CB02071055D5);
		FLOCK.set_function("_0xC95611869E14F8AF", LUA_NATIVE_FLOCK__0xC95611869E14F8AF);
		FLOCK.set_function("_0x09EE00B8F858E0BE", LUA_NATIVE_FLOCK__0x09EE00B8F858E0BE);
		FLOCK.set_function("_0xE36D2CB540597EF7", LUA_NATIVE_FLOCK__0xE36D2CB540597EF7);
		FLOCK.set_function("_0xD95F04A4E73BE85E", LUA_NATIVE_FLOCK__0xD95F04A4E73BE85E);
		FLOCK.set_function("_0x17E3E5C46ECCD308", LUA_NATIVE_FLOCK__0x17E3E5C46ECCD308);
		FLOCK.set_function("_0xC72CE37081DAE625", LUA_NATIVE_FLOCK__0xC72CE37081DAE625);
		FLOCK.set_function("_0x67A43EA3F6FE0076", LUA_NATIVE_FLOCK__0x67A43EA3F6FE0076);
		FLOCK.set_function("_0x36486AF7DA93A464", LUA_NATIVE_FLOCK__0x36486AF7DA93A464);
		FLOCK.set_function("_0x6C57BEA886A20C6B", LUA_NATIVE_FLOCK__0x6C57BEA886A20C6B);
		FLOCK.set_function("_0x1520626FFAFFFA8F", LUA_NATIVE_FLOCK__0x1520626FFAFFFA8F);
		FLOCK.set_function("_0xFA821997794F48E7", LUA_NATIVE_FLOCK__0xFA821997794F48E7);
		FLOCK.set_function("_0xCC6B5AAFC87BFC7B", LUA_NATIVE_FLOCK__0xCC6B5AAFC87BFC7B);
		FLOCK.set_function("_0xFDB008B3BCF5992F", LUA_NATIVE_FLOCK__0xFDB008B3BCF5992F);
		FLOCK.set_function("_0x2DF3D457D86F8E57", LUA_NATIVE_FLOCK__0x2DF3D457D86F8E57);
		FLOCK.set_function("_0x706B434FEFAD6A24", LUA_NATIVE_FLOCK__0x706B434FEFAD6A24);
		FLOCK.set_function("_0xA881F5C77A560906", LUA_NATIVE_FLOCK__0xA881F5C77A560906);
		FLOCK.set_function("_0x53187E563F938E76", LUA_NATIVE_FLOCK__0x53187E563F938E76);
	}
}
