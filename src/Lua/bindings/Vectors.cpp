#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include <script/types.hpp>


namespace Terminus::LuaJIT
{
	class LuaVecLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			// clang-format off

			/* @terminus.class Vector2
			* description
				A 2D Vector class.

			* constructor __call
			
			* constructor __call
			* param x<number>
			* param y<number>

			* field x<number> The X component of the vector.
			* field y<number> The Y component of the vector.
			
			* operator len
			* return number

			* operator add
			* param other<Vector2|number>
			* return Vector2

			* operator sub
			* param other<Vector2|number>
			* return Vector2

			* operator mul
			* param other<Vector2|number>
			* return Vector2

			* operator div
			* param other<Vector2|number>
			* return Vector2

			* method IsZero Returns true if all components of the vector are zero.
			* return boolean
			
			* method Magnitude Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
			* return number mag The magnitude of the vector.
			
			* method Distance Returns the distance between this vector and another.
			* param other<Vector2>
			* return number dist The distance between the two vectors.
			
			* method Lerp Linearly interpolates this vector to target vector over delta time.
			* param other<Vector2>
			* param dt<number> Delta
			* return Vector2
			@*/
			L.new_usertype<ImVec2>("Vector2",
			    sol::call_constructor, sol::constructors<ImVec2(), ImVec2(float, float)>(),

			    "x", &ImVec2::x,
			    "y", &ImVec2::y,

				sol::meta_function::length, [](const ImVec2& self) {
				    return sqrt(self.x * self.x + self.y * self.y);
			    },

				sol::meta_function::to_string, [](const ImVec2& self) {
				    return std::format("({:.3f}, {:.3f})", self.x, self.y);
			    },

				sol::meta_function::equal_to, [](const ImVec2& self, const ImVec2& other) {
				    return self.x == other.x && self.y == other.y;
			    },

				sol::meta_function::addition, sol::overload(
					[](const ImVec2& self, const ImVec2& other) { 
						return ImVec2(self.x + other.x, self.y + other.y); 
					},
					[](const ImVec2& self, const float& other) { 
						return ImVec2(self.x + other, self.y + other);
					}
				),

				sol::meta_function::subtraction, sol::overload(
					[](const ImVec2& self, const ImVec2& other) { 
						return ImVec2(self.x - other.x, self.y - other.y); 
					},
					[](const ImVec2& self, const float& other) { 
						return ImVec2(self.x - other, self.y - other);
					}
				),

				sol::meta_function::multiplication, sol::overload(
					[](const ImVec2& self, const ImVec2& other) {
						return ImVec2(self.x * other.x, self.y * other.y); 
					},
					[](const ImVec2& self, const float& other) { 
						return ImVec2(self.x * other, self.y * other); 
					}
				),

				sol::meta_function::division, sol::overload(
					[](const ImVec2& self, const ImVec2& other) { 
						return ImVec2(self.x / other.x, self.y / other.y); 
					},
					[](const ImVec2& self, const float& other) { 
						return ImVec2(self.x / other, self.y / other);
					}
				),

			    "IsZero", [](const ImVec2& self) {
				    return self.x == 0 && self.y == 0;
			    },

			    "Magnitude", [](const ImVec2& self) {
					return sqrt(self.x * self.x + self.y * self.y);
				},

				"Distance", [](const ImVec2& self, const ImVec2& other) {
					ImVec2 sub = ImVec2(self.x - other.x, self.y - other.y);
					return sqrt(sub.x * sub.x + sub.y * sub.y);
				},

				"Lerp", [](const ImVec2& self, const ImVec2& other, const float& dt) {
					return ImVec2(self.x + (other.x - self.x) * dt, self.y + (other.y - self.y) * dt);
				}
			);

			/*@terminus.class Vector3
			* description
				A 3D vector class.

			* constructor __call
			
			* constructor __call
			* param x<number>
			* param y<number>
			* param z<number>
	
			* field x<number> The X component of the vector.
			* field y<number> The Y component of the vector.
			* field z<number> The Z component of the vector.
			
			* operator len
			* return number
			
			* operator add
			* param other<Vector3|number>
			* return Vector3

			* operator sub
			* param other<Vector3|number>
			* return Vector3

			* operator mul
			* param other<Vector3|number>
			* return Vector3

			* operator div
			* param other<Vector3|number>
			* return Vector3
			
			* method IsZero Returns true if all components of the vector are zero.
			* return boolean
			
			* method Magnitude Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
			* return number mag The magnitude of the vector.
			
			* method Distance Returns the distance between this vector and another.
			* param other<Vector3>
			* return number dist The distance between the two vectors.
			
			* method Lerp Linearly interpolates this vector to target vector over delta time.
			* param other<Vector3>
			* param dt<number> Delta
			* return Vector3
			@*/
			auto vec3 = L.new_usertype<Vector3>("Vector3", 
				sol::call_constructor, sol::constructors<Vector3(), Vector3(float, float, float)>(),

				sol::meta_function::equal_to, &Vector3::operator==,

				"x", &Vector3::x, 
				"y", &Vector3::y, 
				"z", &Vector3::z,

				sol::meta_function::length,   [](const Vector3& self) {
					return sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
				},

				sol::meta_function::to_string, [](const Vector3& self) {
				    return std::format("({:.3f}, {:.3f}, {:.3f})", self.x, self.y, self.z);
			    },

				sol::meta_function::addition, sol::overload(
					[](const Vector3& self, const Vector3& other) { 
						return Vector3(self.x + other.x, self.y + other.y, self.z + other.z); 
					},
					[](const Vector3& self, const float& other) { 
						return Vector3(self.x + other, self.y + other, self.z + other);
					}
				),

				sol::meta_function::subtraction, sol::overload(
					[](const Vector3& self, const Vector3& other) { 
						return Vector3(self.x - other.x, self.y - other.y, self.z - other.z); 
					},
					[](const Vector3& self, const float& other) { 
						return Vector3(self.x - other, self.y - other, self.z - other);
					}
				),

				sol::meta_function::multiplication, sol::overload(
					[](const Vector3& self, const Vector3& other) { 
						return Vector3(self.x * other.x, self.y * other.y, self.z * other.z); 
					},
					[](const Vector3& self, const float& other) { 
						return Vector3(self.x * other, self.y * other, self.z * other);
					}
				),

				sol::meta_function::division, sol::overload(
					[](const Vector3& self, const Vector3& other) { 
					return Vector3(self.x / other.x, self.y / other.y, self.z / other.z); 
					},
					[](const Vector3& self, const float& other) { 
						return Vector3(self.x / other, self.y / other, self.z / other);
					}
				),

				"IsZero", [](const Vector3& self) {
					return self.x == 0 && self.y == 0 && self.z == 0;
				},

				"Magnitude", [](const Vector3& self) {
					return sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
				},

				"IsZero", [](const Vector3& self) {
					return self.x == 0 && self.y == 0 && self.z == 0;
				},

				"Lerp", [](const Vector3& self, const Vector3& other, const float& dt) {
					return Vector3(
						self.x + (other.x - self.x) * dt,
						self.y + (other.y - self.y) * dt,
						self.z + (other.z - self.z) * dt
					);
				}
			);

			/*@terminus.class Vector4
			* description
				A 4D vector class.

			* constructor __call
			
			* constructor __call
			* param x<number>
			* param y<number>
			* param z<number>
			* param w<number>
	
			* field x<number> The X component of the vector.
			* field y<number> The Y component of the vector.
			* field z<number> The Z component of the vector.
			* field w<number> The W component of the vector.
			
			* operator len
			* return number
			
			* operator add
			* param other<Vector4|number>
			* return Vector4

			* operator sub
			* param other<Vector4|number>
			* return Vector4

			* operator mul
			* param other<Vector4|number>
			* return Vector4

			* operator div
			* param other<Vector4|number>
			* return Vector4
			
			* method IsZero Returns true if all components of the vector are zero.
			* return boolean
			
			* method Magnitude Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
			* return number mag The magnitude of the vector.
			
			* method Distance Returns the distance between this vector and another.
			* param other<Vector4>
			* return number dist The distance between the two vectors.
			
			* method Lerp Linearly interpolates this vector to target vector over delta time.
			* param other<Vector4>
			* param dt<number> Delta
			* return Vector4
			@*/
			auto vec4 = L.new_usertype<ImVec4>("Vector4",
				sol::call_constructor, sol::constructors<ImVec4(), ImVec4(float, float, float, float)>(),

				"x", &ImVec4::x, 
				"y", &ImVec4::y, 
				"z", &ImVec4::z,
				"w", &ImVec4::w,

				sol::meta_function::length, [](const ImVec4& self) {
				    return sqrt(self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w);
			    },

				sol::meta_function::to_string, [](const ImVec4& self) {
				    return std::format("({:.3f}, {:.3f}, {:.3f}, {:.3f})", self.x, self.y, self.z, self.w);
			    },

				sol::meta_function::equal_to, [](const ImVec4& self, const ImVec4& other) {
				    return self.x == other.x && self.y == other.y && self.z == other.z && self.w == other.w;
			    },

				sol::meta_function::addition, sol::overload(
					[](const ImVec4& self, const ImVec4& other) { 
						return ImVec4(self.x + other.x, self.y + other.y, self.z + other.z, self.w + other.w); 
					},
					[](const ImVec4& self, const float& other) { 
						return ImVec4(self.x + other, self.y + other, self.z + other, self.w + other);
					}
				),

				sol::meta_function::subtraction, sol::overload(
					[](const ImVec4& self, const ImVec4& other) { 
						return ImVec4(self.x - other.x, self.y - other.y, self.z - other.z, self.w - other.w); 
					},
					[](const ImVec4& self, const float& other) { 
						return ImVec4(self.x - other, self.y - other, self.z - other, self.w - other);
					}
				),

				sol::meta_function::multiplication, sol::overload(
					[](const ImVec4& self, const ImVec4& other) {
						return ImVec4(self.x * other.x, self.y * other.y, self.z * other.z, self.w * other.w); 
					},
					[](const ImVec4& self, const float& other) { 
						return ImVec4(self.x * other, self.y * other, self.z * other, self.w * other); 
					}
				),

				sol::meta_function::division, sol::overload(
					[](const ImVec4& self, const ImVec4& other) { 
						return ImVec4(self.x / other.x, self.y / other.y, self.z / other.z, self.w / other.w); 
					},
					[](const ImVec4& self, const float& other) { 
						return ImVec4(self.x / other, self.y / other, self.z / other, self.w / other);
					}
				),

				"IsZero", [](const ImVec4& self) {
					return self.x == 0 && self.y == 0 && self.z == 0 && self.w == 0;
				},

				"Magnitude", [](const ImVec4& self) {
					return sqrt(self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w);
				},

				"Distance", [](const ImVec4& self, const ImVec4& other) {
					ImVec4 sub = ImVec4(self.x - other.x, self.y - other.y, self.z - other.z, self.w - other.w);
					return sqrt(sub.x * sub.x + sub.y * sub.y + sub.z * sub.z + sub.w * sub.w);
				},

				"Lerp", [](const ImVec4& self, const ImVec4& other, const float& dt) {
					return ImVec4(
						self.x + (other.x - self.x) * dt,
						self.y + (other.y - self.y) * dt,
						self.z + (other.z - self.z) * dt,
						self.w + (other.w - self.w) * dt
					);
				}
			);
		};
	};

	LuaVecLib _LuaVecLib;
}
