#include "stdafx.h"
#include "Sphere.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
#include "Matrix/Matrix4x4.hpp"
#include "Matrix/Matrix3x3.hpp"

void Sphere::Init(float aRadius, int anAmountOfPoints, CommonUtilities::Vector4<float> aStartPositon, int anAmountOfRows)
{
	myStartPosition = aStartPositon;
	myAmountOfPoints = anAmountOfPoints;
	myAmountOfRows = anAmountOfRows;
	myRadius = aRadius;
	myPointStep = (3.14159265359f * 2) / myAmountOfPoints;

	for (int i = 0; i < myAmountOfPoints; i++)
	{
		myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(0, 0, 0, 1)));
	}
}

void Sphere::Update()
{
	float rotationStep = (3.14159265359f * 2) / myAmountOfRows;
	for (int j = 0; j < myAmountOfRows; j++)
	{
		for (int i = 0; i < myAmountOfPoints; i++)
		{
			float x = myRadius * cos(myPointStep * i);
			float y = myRadius * sin(myPointStep * i);
			CommonUtilities::Vector4<float> CirclePoint = CommonUtilities::Vector4<float>(x, y, 0, 1);

			CirclePoint = (CirclePoint * CommonUtilities::Matrix4x4<float>().CreateRotationAroundY(rotationStep * j))*myMatrix;
			CirclePoint.x += myStartPosition.x + myRadius;
			CirclePoint.y += myStartPosition.y + myRadius;
			CirclePoint.z += myStartPosition.z + myRadius;

			myPotatoes[i]->SetPosition(CommonUtilities::Vector4<float>(CirclePoint.x, CirclePoint.y, CirclePoint.z, 1));
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
