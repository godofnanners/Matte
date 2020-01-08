#include "pch.h"
#include "CppUnitTest.h"
#include "Line.hpp"
#include "Vector2.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Uppgift3LinjerOchPlan
{
	TEST_CLASS(Uppgift3LinjerOchPlan)
	{
	public:
		
		TEST_METHOD(TestLine)
		{
			CommonUtilities::Line<float>(CommonUtilities::Vector2<float>(1.f,1.f), CommonUtilities::Vector2<float>(1.f, 2.f));
		}	
	};

	
}
