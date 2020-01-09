#include "pch.h"
#include "CppUnitTest.h"
#include "Plane.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Planef = CommonUtilities::Plane<float>;
using Planed = CommonUtilities::Plane<double>;
using Vector3f = CommonUtilities::Vector3<float>;
using Vector3d = CommonUtilities::Vector3<double>;

namespace TestPlane
{
	TEST_CLASS(TestPlane)
	{
		TEST_METHOD(TestPlaneConstruct) 
		{

		}
		TEST_METHOD(P_IsInside)
		{
			// Testing points with 6 different Plane<float> (normals along x, y and z axes, positive and negative).
			Planef xPlaneF(Vector3f(5.0f, 0.0f, 0.0f), Vector3f(1.0f, 0.0f, 0.0f));
			Planef xNegPlaneF(Vector3f(-5.0f, 0.0f, 0.0f), Vector3f(-1.0f, 0.0f, 0.0f));
			Planef yPlaneF(Vector3f(0.0f, 5.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));
			Planef yNegPlaneF(Vector3f(0.0f, -5.0f, 0.0f), Vector3f(0.0f, -1.0f, 0.0f));
			Planef zPlaneF(Vector3f(0.0f, 0.0f, 5.0f), Vector3f(0.0f, 0.0f, 1.0f));
			Planef zNegPlaneF(Vector3f(0.0f, 0.0f, -5.0f), Vector3f(0.0f, 0.0f, -1.0f));

			Vector3f pointF(0.0f, 0.0f, 0.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointF), L"Point (0.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointXF(6.0f, 0.0f, 0.0f);
			Assert::IsFalse(xPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should not be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointXF), L"Point (6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointXNegF(-6.0f, 0.0f, 0.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsFalse(xNegPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should not be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointXNegF), L"Point (-6.0f, 0.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointYF(0.0f, 6.0f, 0.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsFalse(yPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should not be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointYF), L"Point (0.0f, 6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointYNegF(0.0f, -6.0f, 0.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsFalse(yNegPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should not be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointYNegF), L"Point (0.0f, -6.0f, 0.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointZF(0.0f, 0.0f, 6.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsFalse(zPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should not be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsTrue(zNegPlaneF.IsInside(pointZF), L"Point (0.0f, 0.0f, 6.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			Vector3f pointZNegF(0.0f, 0.0f, -6.0f);
			Assert::IsTrue(xPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should be inside of Plane<float> with the normal (1.0f, 0.0f, 0.0f) and that contains the point (5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(xNegPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should be inside of Plane<float> with the normal (-1.0f, 0.0f, 0.0f) and that contains the point (-5.0f, 0.0f, 0.0f).");
			Assert::IsTrue(yPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should be inside of Plane<float> with the normal (0.0f, 1.0f, 0.0f) and that contains the point (0.0f, 5.0f, 0.0f).");
			Assert::IsTrue(yNegPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should be inside of Plane<float> with the normal (0.0f, -1.0f, 0.0f) and that contains the point (0.0f, -5.0f, 0.0f).");
			Assert::IsTrue(zPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should be inside of Plane<float> with the normal (0.0f, 0.0f, 1.0f) and that contains the point (0.0f, 0.0f, 5.0f).");
			Assert::IsFalse(zNegPlaneF.IsInside(pointZNegF), L"Point (0.0f, 0.0f, -6.0f) should not be inside of Plane<float> with the normal (0.0f, 0.0f, -1.0f) and that contains the point (0.0f, 0.0f, -5.0f).");

			// Testing points with 6 different Plane<double> (normals along x, y and z axes, positive and negative).
			Planed xPlaneD(Vector3d(5.0, 0.0, 0.0), Vector3d(1.0, 0.0, 0.0));
			Planed xNegPlaneD(Vector3d(-5.0, 0.0, 0.0), Vector3d(-1.0, 0.0, 0.0));
			Planed yPlaneD(Vector3d(0.0, 5.0, 0.0), Vector3d(0.0, 1.0, 0.0));
			Planed yNegPlaneD(Vector3d(0.0, -5.0, 0.0), Vector3d(0.0, -1.0, 0.0));
			Planed zPlaneD(Vector3d(0.0, 0.0, 5.0), Vector3d(0.0, 0.0, 1.0));
			Planed zNegPlaneD(Vector3d(0.0, 0.0, -5.0), Vector3d(0.0, 0.0, -1.0));

			Vector3d pointD(0.0, 0.0, 0.0);
			Assert::IsTrue(xPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointD), L"Point (0.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointXD(6.0, 0.0, 0.0);
			Assert::IsFalse(xPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should not be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointXD), L"Point (6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointXNegD(-6.0, 0.0, 0.0);
			Assert::IsTrue(xPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsFalse(xNegPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should not be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointXNegD), L"Point (-6.0, 0.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointYD(0.0, 6.0, 0.0);
			Assert::IsTrue(xPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsFalse(yPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should not be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointYD), L"Point (0.0, 6.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointYNegD(0.0, -6.0, 0.0);
			Assert::IsTrue(xPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsFalse(yNegPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should not be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointYNegD), L"Point (0.0, -6.0, 0.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointZD(0.0, 0.0, 6.0);
			Assert::IsTrue(xPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsFalse(zPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should not be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsTrue(zNegPlaneD.IsInside(pointZD), L"Point (0.0, 0.0, 6.0) should be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");

			Vector3d pointZNegD(0.0, 0.0, -6.0);
			Assert::IsTrue(xPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should be inside of Plane<double> with the normal (1.0, 0.0, 0.0) and that contains the point (5.0, 0.0, 0.0).");
			Assert::IsTrue(xNegPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should be inside of Plane<double> with the normal (-1.0, 0.0, 0.0) and that contains the point (-5.0, 0.0, 0.0).");
			Assert::IsTrue(yPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should be inside of Plane<double> with the normal (0.0, 1.0, 0.0) and that contains the point (0.0, 5.0, 0.0).");
			Assert::IsTrue(yNegPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should be inside of Plane<double> with the normal (0.0, -1.0, 0.0) and that contains the point (0.0, -5.0, 0.0).");
			Assert::IsTrue(zPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should be inside of Plane<double> with the normal (0.0, 0.0, 1.0) and that contains the point (0.0, 0.0, 5.0).");
			Assert::IsFalse(zNegPlaneD.IsInside(pointZNegD), L"Point (0.0, 0.0, -6.0) should not be inside of Plane<double> with the normal (0.0, 0.0, -1.0) and that contains the point (0.0, 0.0, -5.0).");
		}
	};
}