
#ifndef ALIB_MATH_VECTOR_COMMON
#define ALIB_MATH_VECTOR_COMMON

// Do not include this file manually.
//#include "../../../alib/common.hpp"
#include "../../core/memory.hpp"
#include "../common.hpp"

//#include <emmintrin.h>




namespace alib
{
	namespace Math
	{
		/*template<typename Type, int vector_length, int alignment = 0>
		struct alignas(alignment) Vector
		{
			Type data[vector_length];
		};
*/

		template<typename Type, int alignment = 0>
		struct Vector2;

		template<typename Type, int alignment = 0>
		struct Vector3;

		template<typename Type, int alignment = 0>
		struct Vector4;

		template<typename Type, int Offset1, int Offset2, int alignment = 0>
		struct Vector2Swizzle
		{

			union
			{
				Memory::Map<Type, (int)sizeof(Type) * Offset1> x;
				Memory::Map<Type, (int)sizeof(Type) * Offset2> y;

				struct
				{
					strong_inline operator Vector2<Type, alignment> &()
					{
						return Memory::Cast<Vector2<Type, alignment> >(this, (-(int)sizeof(Type)));
					}
				}vector;
			};

			strong_inline Vector2<Type, alignment>& operator = (const Vector2<Type, alignment> &aAssignment)
			{
				Type assignedX = aAssignment.x;
				Type assignedY = aAssignment.y;
				x = assignedX;
				y = assignedY;
				return Memory::Cast<Vector2<Type, alignment>>(this);
			}

			strong_inline operator Vector2<Type, alignment>()
			{
				return Vector2<Type, alignment>(x, y);
			}

			strong_inline Vector2<Type, alignment> operator ()()
			{
				return Vector2<Type, alignment>(x, y);
			}

			friend Vector2<Type, alignment>;
			friend Vector3<Type, alignment>;
			friend Vector4<Type, alignment>;

		private:
			strong_inline Vector2Swizzle() {}
		};


		template<typename Type, int Offset1, int Offset2, int Offset3, int alignment = 0>
		struct Vector3Swizzle
		{
			union
			{
				Memory::Map<Type, (int)sizeof(Type) * Offset1> x;
				Memory::Map<Type, (int)sizeof(Type) * Offset2> y;
				Memory::Map<Type, (int)sizeof(Type) * Offset3> z;

				struct
				{
					strong_inline operator Vector3<Type, alignment>& ()
					{
						return Memory::Cast<Vector3<Type, alignment> >(this, (-((int)sizeof(Type)*2)));
					}
				}vector;
			};

			strong_inline Vector3<Type, alignment>& operator = (const Vector3<Type, alignment>& aAssignment)
			{
				Type assignedX = aAssignment.x;
				Type assignedY = aAssignment.y;
				Type assignedZ = aAssignment.z;
				x = assignedX;
				y = assignedY;
				z = assignedZ;
				return vector;
			}

			strong_inline Vector3<Type, alignment>& operator = (const Type aAssignment)
			{
				x = aAssignment;
				y = aAssignment;
				z = aAssignment;
				return vector;
			}

			strong_inline operator Vector3<Type, alignment>()
			{
				return Vector3<Type, alignment>(x, y, z);
			}

			strong_inline Vector3<Type, alignment> operator ()()
			{
				return Vector3<Type, alignment>(x, y, z);
			}

			friend Vector2<Type, alignment>;
			friend Vector3<Type, alignment>;
			friend Vector4<Type, alignment>;

		private:
			strong_inline Vector3Swizzle() {}
		};


		template<typename Type, int Offset1, int Offset2, int Offset3, int Offset4, int alignment = 0>
		struct Vector4Swizzle
		{
			union
			{
				Memory::Map<Type, (int)sizeof(Type) * Offset1> x;
				Memory::Map<Type, (int)sizeof(Type) * Offset2> y;
				Memory::Map<Type, (int)sizeof(Type) * Offset3> z;
				Memory::Map<Type, (int)sizeof(Type) * Offset4> w;

				struct
				{
					strong_inline operator Vector4<Type, alignment>& ()
					{
						return Memory::Cast<Vector4<Type, alignment> >(this, (-((int)sizeof(Type) * 3)));
					}
				}vector;
			};

			strong_inline Vector4<Type, alignment>& operator = (const Vector4<Type, alignment>& aAssignment)
			{
				Type assignedX = aAssignment.x;
				Type assignedY = aAssignment.y;
				Type assignedZ = aAssignment.z;
				Type assignedW = aAssignment.w;
				x = assignedX;
				y = assignedY;
				z = assignedZ;
				w = assignedW;
				return Memory::Cast<Vector4<Type, alignment>>(this);
			}

			strong_inline operator Vector4<Type, alignment>()
			{
				return Vector4<Type, alignment>(x, y, z);
			}

			strong_inline Vector4<Type, alignment> operator ()()
			{
				return Vector4<Type, alignment>(x, y, z);
			}


			friend Vector2<Type, alignment>;
			friend Vector3<Type, alignment>;
			friend Vector4<Type, alignment>;

		private:
			strong_inline Vector4Swizzle() {}
		};
	}
}

#endif

