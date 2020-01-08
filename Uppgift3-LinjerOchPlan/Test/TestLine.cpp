#include "pch.h"
#include "CppUnitTest.h"
#include "Line.hpp"
#include "Vector2.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLine
{
	TEST_CLASS(TestLine)
	{
	public:
		TEST_METHOD(TestLineCreation)
		{
			CommonUtilities::Line<float>(CommonUtilities::Vector2<float>(1.f, 1.f), CommonUtilities::Vector2<float>(1.f, 2.f));
			Assert::
		}
	};


}