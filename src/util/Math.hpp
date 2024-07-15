#pragma once
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp" 

namespace YimMenu::Math
{
	inline float DegToRad(float deg)
	{
		double radian = (3.14159265359 / 180) * deg;
		return static_cast<float>(radian);
	}

	inline Vector3 RotationToDirection(Vector3 rotation)
	{
		float x = DegToRad(rotation.x);
		float z = DegToRad(rotation.z);

		float num = abs(cos(x));

		return Vector3{-sin(z) * num, cos(z) * num, sin(x)};
	}
}