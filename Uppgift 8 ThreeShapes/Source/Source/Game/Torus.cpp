#include "stdafx.h"
#include "Torus.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
#include "Matrix/Matrix4x4.hpp"
#include "Matrix/Matrix3x3.hpp"

void Torus::Init(float aRadius, float aHoleRadius, int anAmountOfPoints, CommonUtilities::Vector3<float> aStartPositon, int anAmountOfCircles)
{
	myStartPosition = aStartPositon;
	myAmountOfPoints = anAmountOfPoints;
	myAmountOfCircles = anAmountOfCircles;
	myHoleRadius = aHoleRadius;
	myRadius = aRadius;
	myPointStep = (3.14159265359f * 2) / myAmountOfPoints;

	for (int i = 0; i < myAmountOfPoints * myAmountOfCircles; i++)
	{
		myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(0, 0, 0, 1)));
	}
}

void Torus::Update()
{
	float rotationStep = (3.14159265359f * 2) / myAmountOfCircles;
	float potatoIndex = 0;


	for (int j = 0; j < myAmountOfCircles; j++)
	{
		float CircleCenterX = myHoleRadius * cos(rotationStep * j);
		float CircleCenterY = myHoleRadius * sin(rotationStep * j);

		CommonUtilities::Vector4<float> DonutCirclePoint = CommonUtilities::Vector4<float>(CircleCenterX, CircleCenterY, 0, 0);

		DonutCirclePoint = DonutCirclePoint * CommonUtilities::Matrix4x4<float>().CreateRotationAroundX(1.57079633f);

		//DonutCirclePoint = DonutCirclePoint * myMatrix;

		DonutCirclePoint = DonutCirclePoint;

		for (int i = 0; i < myAmountOfPoints; i++)
		{
			float x = myRadius * cos(myPointStep * i);
			float y = myRadius * sin(myPointStep * i);

			CommonUtilities::Vector4<float> CirclePoint = CommonUtilities::Vector4<float>(x, y, 0, 1);

			
			CommonUtilities::Matrix4x4<float> CreationRotation = CommonUtilities::Matrix4x4<float>().CreateRotationAroundY(-rotationStep * j);

			
			CirclePoint = ((CirclePoint)* CreationRotation);

			CirclePoint = CirclePoint + DonutCirclePoint;

			CirclePoint = CirclePoint * myMatrix;

			myPotatoes[potatoIndex]->SetPosition(CirclePoint+myStartPosition);

			potatoIndex++;
		}
	}
}

void Torus::Render(const float aNear, const float aFar)
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->Render(aNear, aFar);
	}
}
