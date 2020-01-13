
#pragma once

#include <math.h>
#include <functional>

#include "..\\core\memory.hpp"



namespace Number
{
	template<typename Type>
	struct NumberSystemComponent
	{
		Type data;
	};
}










template<typename DataType>
__forceinline DataType SquareRoot(DataType input_value)
{
	static_assert(false, "DataType has no supported square root.");
}

template<>
__forceinline float SquareRoot<float>(float input_value)
{
	return sqrtf(input_value);
}

template<>
__forceinline double SquareRoot<double>(double input_value)
{
	return sqrt(input_value);
}

template<>
__forceinline int SquareRoot<int>(int input_value)
{
	if (input_value == 0 || input_value == 1)
	{
		return input_value;
	}

	int start = 1;
	int end = input_value;
	int result;

	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (middle * middle == input_value)
		{
			return middle;
		}

		if (middle * middle < input_value)
		{
			start = middle + 1;
			result = middle;
		}
		else 
		{
			end = middle - 1;
		}
	}

	return result;
}

template<typename Type>
__forceinline Type DefaultInitializationValue()
{
	static_assert(false, "DataType has no supported default initialization value.");
}

template<>
__forceinline float DefaultInitializationValue<float>()
{
	return 0.0f;
}

template<>
__forceinline double DefaultInitializationValue<double>()
{
	return 0.0;
}

template<>
__forceinline int DefaultInitializationValue<int>()
{
	return 0;
}



