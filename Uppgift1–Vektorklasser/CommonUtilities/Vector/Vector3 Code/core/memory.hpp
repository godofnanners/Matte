
#pragma once

#include "../common.hpp"

#include <cstdint>

namespace alib
{
	namespace Memory
	{
		/*template<typename Type, uint64_t byte_offset = 0, bool nullified = false>
		struct Abstract
		{

			strong_inline Type& operator ()() const
			{
				return (*reinterpret_cast<Type*>(reinterpret_cast<char*>(const_cast<Abstract*>(this)) + byte_offset));
			}

			strong_inline operator Type& () const
			{
				return (*reinterpret_cast<Type*>(reinterpret_cast<char*>(const_cast<Abstract*>(this)) + byte_offset));
			}

			strong_inline operator Map& () = delete;


		};*/

/*
		template<typename Type, uint64_t byte_offset = 0, bool nullified = false>
		struct AbstractPointer
		{

		};
*/

		template<typename To, typename From>
		strong_inline To& Cast(From *aAddress, int aByteOffset = 0)
		{
			return *((To*)(((char*)aAddress) + aByteOffset));
		}

		/*
		template<typename Type, typename From>
		strong_inline Type &As(void *aAddress, int aByteOffset)
		{
			return *reinterpret_cast<Type*>(reinterpret_cast<char*>(aAddress) + aByteOffset);
		}
		*/

		// A data type that should eliminate all direct or indirect interactions made with it.
		struct Void
		{
		private:

		public:

			template<typename DataType>
			strong_inline operator DataType() const
			{
				return DataType();
			}

			template<typename DataType>
			strong_inline Void operator = (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator + (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator - (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator * (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator / (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator % (const DataType a) const
			{
				return *this;
			}


			template<typename DataType>
			strong_inline Void operator += (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator -= (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator *= (const DataType a) const
			{
				return *this;
			}

			template<typename DataType>
			strong_inline Void operator /= (const DataType a) const
			{
				return *this;
			}


			Void() {}
		};



		// Wrapper for treating variables as if they're in a different position in memory.
		// Warning, use with extreme care!
		template<typename DataType, uint64_t byte_offset = 0>
		struct Map
		{
		private:

		public:

			strong_inline DataType& operator ()() const
			{
				return (*reinterpret_cast<DataType*>(reinterpret_cast<char*>(const_cast<Map*>(this)) + byte_offset));
			}

			strong_inline operator DataType& () const
			{
				return (*reinterpret_cast<DataType*>(reinterpret_cast<char*>(const_cast<Map*>(this)) + byte_offset));
			}

			strong_inline operator Map& () = delete; // todo: test what the consequences of this actually are.

			//template<typename AssignedDataType>
			strong_inline DataType& operator = (const DataType &new_value)
			{
				return (*this)() = new_value;
			}

			strong_inline DataType& operator = (const Map &new_value)
			{
				return (*this)() = new_value();
			}

			/*
			template<typename SecondaryDataType, int secondary_byte_offset>
			__forceinline DataType& operator = (Map< SecondaryDataType, secondary_byte_offset> new_value)
			{
				(*reinterpret_cast<DataType*>(reinterpret_cast<char*>(this) + byte_offset)) = (*reinterpret_cast<DataType*>((reinterpret_cast<char*>(&new_value)) + secondary_byte_offset));
				return (*reinterpret_cast<DataType*>(reinterpret_cast<char*>(this) + byte_offset));
			}
			*/

			strong_inline Memory::Void &operator = (Memory::Void new_value)
			{
				return new_value;
			}




			strong_inline DataType operator + (DataType &memory_b)
			{
				return ((*this)() + memory_b);
			}

			strong_inline DataType operator - (DataType memory_b)
			{
				return ((*this)() - memory_b);
			}

			strong_inline DataType operator * (DataType memory_b)
			{
				return ((*this)() * memory_b);
			}

			strong_inline DataType operator / (DataType memory_b)
			{
				return ((*this)() / memory_b);
			}

			strong_inline DataType operator % (DataType memory_b)
			{
				return ((*this)() % memory_b);
			}





			strong_inline DataType& operator += (DataType memory_b)
			{
				return ((*this)() += memory_b);
			}

			strong_inline DataType& operator -= (DataType memory_b)
			{
				return ((*this)() -= memory_b);
			}

			strong_inline DataType& operator *= (DataType memory_b)
			{
				return ((*this)() *= memory_b);
			}

			strong_inline DataType& operator /= (DataType memory_b)
			{
				return ((*this)() /= memory_b);
			}

			strong_inline DataType& operator %= (DataType memory_b)
			{
				return ((*this)() %= memory_b);
			}


			Map(DataType initial_value) { (*this) = initial_value; }
		};



	}
}
