#include "stdafx.h"
#include "Sphere.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
#include "Matrix/Matrix4x4.hpp"
#include "Matrix/Matrix3x3.hpp"

void Sphere::Init(float aRadius, int anAmountOfPoints, CommonUtilities::Vector3<float> aStartPositon, int anAmountOfCircles)
{
	myStartPosition = aStartPositon;
	myAmountOfPoints = anAmountOfPoints;
	myAmountOfCircles = anAmountOfCircles;
	myRadius = aRadius;
	myPointStep = (3.14159265359f * 2) / myAmountOfPoints;

	for (int i = 0; i < myAmountOfPoints * myAmountOfCircles; i++)
	{
		myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(0, 0, 0, 1)));
	}
}

void Sphere::Update()
{
	float rotationStep = (3.14159265359f * 2) / myAmountOfCircles;
	float potatoIndex = 0;
	for (int j = 0; j < myAmountOfCircles; j++)
	{
		for (int i = 0; i < myAmountOfPoints; i++)
		{
			float x = myRadius * cos(myPointStep * i);
			float y = myRadius * sin(myPointStep * i);
			CommonUtilities::Vector4<float> CirclePoint = CommonUtilities::Vector4<float>(x, y, 0, 1);

			CirclePoint = (CirclePoint * CommonUtilities::Matrix4x4<float>().CreateRotationAroundY(rotationStep * j));
			CirclePoint = CirclePoint * myMatrix;

			myPotatoes[potatoIndex]->SetPosition(CirclePoint + myStartPosition);
			potatoIndex++;
		}
	}
}

void Sphere::Render(const float aNear, const float aFar)
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->Render(aNear, aFar);
	}
}
