#include "pch.h"
#include "CppUnitTest.h"
#include "Line.hpp"
#include "LineVolume.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Linef = CommonUtilities::Line<float>;
using Lined = CommonUtilities::Line<double>;
using LVf = CommonUtilities::LineVolume<float>;
using LVd = CommonUtilities::LineVolume<double>;
using Vector2f = CommonUtilities::Vector2<float>;
using Vector2d = CommonUtilities::Vector2<double>;


namespace TestLineVolume1
{
	TEST_CLASS(TestLineVolume)
	{
	public:
		TEST_METHOD(TestLineVolumeCreation)
		{
			
			CommonUtilities::LineVolume<float> lineVolume;
			lineVolume.AddLine(CommonUtilities::Line<float>(CommonUtilities::Vector2<float>(1,2), CommonUtilities::Vector2<float>(1, 3)));
		}
		TEST_METHOD(LV_IsInside)
		{
			// Test the LineVolume<float> IsInside() function.
			LVf lineVolumeF({ Linef(Vector2f(-4.5f, -3.0f), Vector2f(0.0f, 6.0f))
							, Linef(Vector2f(0.0f, 6.0f), Vector2f(4.5f, -3.0f))
							, Linef(Vector2f(4.5f, -3.0f), Vector2f(-4.5f, -3.0f)) });
			std::wstring lvfDescription(L"LineVolume<float> with the following lines:\n" \
				"1] { (-4.5f, -3.0f), (0.0f, 6.0f) }\n" \
				"2] { (0.0f, 6.0f), (4.5f, -3.0f) }\n" \
				"3] { (4.5f, -3.0f), (-4.5f, -3.0f) }");

			Vector2f pointF(0.0f, 0.0f);
			Vector2f point1F(-4.0f, 0.0f);
			Vector2f point2F(4.0f, 0.0f);
			Vector2f point3F(0.0f, -4.0f);

			Assert::IsTrue(lineVolumeF.IsInside(pointF), (L"Point (0.0f, 0.0f) should be inside of the " + lvfDescription).c_str());
			Assert::IsFalse(lineVolumeF.IsInside(point1F), (L"Point (-4.0f, 0.0f) should not be inside of the " + lvfDescription).c_str());
			Assert::IsFalse(lineVolumeF.IsInside(point2F), (L"Point (4.0f, 0.0f) should not be inside of the " + lvfDescription).c_str());
			Assert::IsFalse(lineVolumeF.IsInside(point3F), (L"Point (0.0f, -4.0f) should not be inside of the " + lvfDescription).c_str());

			// Test the LineVolume<double> IsInside() function.
			LVd lineVolumeD({ Lined(Vector2d(-4.5f, -3.0f), Vector2d(0.0f, 6.0f))
							, Lined(Vector2d(0.0f, 6.0f), Vector2d(4.5f, -3.0f))
							, Lined(Vector2d(4.5f, -3.0f), Vector2d(-4.5f, -3.0f)) });
			std::wstring lvdDescription(L"LineVolume<double> with the following lines:\n" \
				"{ (-4.5, -3.0), (0.0, 6.0) }\n" \
				"{ (0.0, 6.0), (4.5, -3.0) }\n" \
				"{ (4.5, -3.0), (-4.5, -3.0) }");

			Vector2d pointD(0.0, 0.0);
			Vector2d point1D(-4.0, 0.0);
			Vector2d point2D(4.0, 0.0);
			Vector2d point3D(0.0, -4.0);

			Assert::IsTrue(lineVolumeD.IsInside(pointD), (L"Point (0.0, 0.0) should be inside of the " + lvdDescription).c_str());
			Assert::IsFalse(lineVolumeD.IsInside(point1D), (L"Point (-4.0, 0.0) should not be inside of the " + lvdDescription).c_str());
			Assert::IsFalse(lineVolumeD.IsInside(point2D), (L"Point (4.0, 0.0) should not be inside of the " + lvdDescription).c_str());
			Assert::IsFalse(lineVolumeD.IsInside(point3D), (L"Point (0.0, -4.0) should not be inside of the " + lvdDescription).c_str());
		}
	};


}
