#include "pch.h"
#include "CppUnitTest.h"
#include "Vector3.h"

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

			float testA = a / myDefaultVector.Length();

			Assert::AreEqual(myNormalizedVector, testA); 
		}
	};
}
