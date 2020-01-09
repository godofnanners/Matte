#include "pch.h"
#include "CppUnitTest.h"
#include "PlaneVolume.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Planef = CommonUtilities::Plane<float>;
using Planed = CommonUtilities::Plane<double>;
using PVf = CommonUtilities::PlaneVolume<float>;
using PVd = CommonUtilities::PlaneVolume<double>;
using Vector3f = CommonUtilities::Vector3<float>;
using Vector3d = CommonUtilities::Vector3<double>;

namespace TestPlane
{
	TEST_CLASS(TestPlane)
	{
		TEST_METHOD(TestPlaneConstruct)
		{

		}
	};
}