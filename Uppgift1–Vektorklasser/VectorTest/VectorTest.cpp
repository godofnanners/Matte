#include "pch.h"
#include "CppUnitTest.h"
#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTest
{
	TEST_CLASS(VectorTest)
	{
	public:

		TEST_METHOD(TestNullVector)
		{
			CommonUtilities::Vector3<int> myDefaultVector = CommonUtilities::Vector3<int>();
			Assert::IsTrue(myDefaultVector.x == NULL && myDefaultVector.y == NULL && myDefaultVector.z == NULL, L"Vector isnt NULL");
		}

		TEST_METHOD(TestCreatingVector)
		{
			int a = 1;
			int b = 2;
			int c = 3;

			CommonUtilities::Vector3<int> myDefaultVector = CommonUtilities::Vector3<int>(a, b, c);
			Assert::IsTrue(myDefaultVector.x == a && myDefaultVector.y == b && myDefaultVector.z == c, L"Vector isnt created with correct numbers");
		}
		TEST_METHOD(TestLenghtOfVector)
		{
			int a = 2;
			int b = 1;
			int c = 2;

			CommonUtilities::Vector3<int> myDefaultVector = CommonUtilities::Vector3<int>(a, b, c);
			Assert::IsTrue(myDefaultVector.Length() == 3, L"Lenght is not correct");

		}

		TEST_METHOD(TestSqrLenghtOfVector)
		{
			int a = 2;
			int b = 1;
			int c = 2;

			CommonUtilities::Vector3<int> myDefaultVector = CommonUtilities::Vector3<int>(a, b, c);
			Assert::IsTrue(myDefaultVector.LengthSqr() == 9, L"Sqr Lenght is not correct");
		}

		TEST_METHOD(TestAdditionOfVectors)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector = myDefaultVector + myDefaultVector2;
			Assert::IsTrue(myDefaultVector.x == a + a && myDefaultVector.y == b + b && myDefaultVector.z == c + c, L"addition of vector doesnt work");
		}
		TEST_METHOD(TestAdditionOfVectorsWithRef)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector += myDefaultVector2;
			Assert::IsTrue(myDefaultVector.x == a + a && myDefaultVector.y == b + b && myDefaultVector.z == c + c, L"addition of vector doesnt work");
		}
		TEST_METHOD(TestDifferenceOfVectors)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector = myDefaultVector - myDefaultVector2;
			Assert::IsTrue(myDefaultVector.x == a - a && myDefaultVector.y == b - b && myDefaultVector.z == c - c, L"addition of vector doesnt work");
		}
		TEST_METHOD(TestDifferenceOfVectorsWithRef)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector -= myDefaultVector2;
			Assert::IsTrue(myDefaultVector.x == a - a && myDefaultVector.y == b - b && myDefaultVector.z == c - c, L"addition of vector doesnt work");
		}

		TEST_METHOD(TestMultiWithScalar)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			float scalar = 3.0f;

			myDefaultVector = myDefaultVector * scalar;
			Assert::IsTrue(myDefaultVector.x == a * scalar && myDefaultVector.y == b * scalar && myDefaultVector.z == c * scalar, L"multiplie scalar with vector doesnt work");


			myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector = scalar * myDefaultVector;
			Assert::IsTrue(myDefaultVector.x == a * scalar && myDefaultVector.y == b * scalar && myDefaultVector.z == c * scalar, L"multiplie scalar with vector doesnt work");

			myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);

			myDefaultVector *= scalar;
			Assert::IsTrue(myDefaultVector.x == a * scalar && myDefaultVector.y == b * scalar && myDefaultVector.z == c * scalar, L"multiplie scalar with vector doesnt work");
		}

		TEST_METHOD(TestDivWithScalar)
		{
			float a = 2;
			float b = 1;
			float c = 2;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			float scalar = 3.0f;

			myDefaultVector = myDefaultVector / scalar;
			Assert::IsTrue(myDefaultVector.x == a / scalar && myDefaultVector.y == b / scalar && myDefaultVector.z == c / scalar, L"dividation with scalar with vector doesnt work");
		}
		TEST_METHOD(TestGetNormalize)
		{
			float a = 5;
			float b = 0;
			float c = 3;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);

			CommonUtilities::Vector3<float> myNormalizedVector = myDefaultVector.GetNormalized();

			Assert::AreEqual(myNormalizedVector.Length(), 1.f);
		}
		TEST_METHOD(TestNormalize)
		{
			float a = 5;
			float b = 0;
			float c = 3;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);
			myDefaultVector.Normalize();
			Assert::AreEqual(myDefaultVector.Length(), 1.f);
		}
		TEST_METHOD(TestCrossVector)
		{
			float a = 5;
			float b = 0;
			float c = 3;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);

			float d = 5;
			float e = 0;
			float f = 1;

			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(d, e, f);

			CommonUtilities::Vector3<float> myCrossVector = myDefaultVector.Cross(myDefaultVector2);



			Assert::AreEqual(myCrossVector.x, 0.f);
			Assert::AreEqual(myCrossVector.y, 10.f);
			Assert::AreEqual(myCrossVector.z, 0.f);
		}

		TEST_METHOD(TestDotProduct)
		{
			float a = 5;
			float b = 0;
			float c = 3;

			CommonUtilities::Vector3<float> myDefaultVector = CommonUtilities::Vector3<float>(a, b, c);

			float d = 5;
			float e = 0;
			float f = 1;

			CommonUtilities::Vector3<float> myDefaultVector2 = CommonUtilities::Vector3<float>(d, e, f);

			float myDotProduct = myDefaultVector.Dot(myDefaultVector2);



			Assert::AreEqual(myDotProduct, 28.f);
		}
	};
}
