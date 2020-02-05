#include "stdafx.h"
#include "Sphere.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
#include "Matrix/Matrix4x4.hpp"
#include "Matrix/Matrix3x3.hpp"

void Sphere::Init(float aRadius,int anAmountOfPoints , CommonUtilities::Vector4<float> aStartPositon ,int anAmountOfRows)
{
	float startPoint = 0;
	float pointStep = (3.14159265359f * 2) / anAmountOfPoints;
	float rotationStep = (3.14159265359f * 2) / anAmountOfRows;
	for (int j = 0; j < anAmountOfRows; j++)
	{
		for (int i = 0; i < anAmountOfPoints; i++)
		{
			float x = aRadius*cos(pointStep*i);
			float y = aRadius*sin(pointStep*i);
			CommonUtilities::Vector4<float> CirclePoint = CommonUtilities::Vector4<float>(x, y , 0 ,1);
			
			CirclePoint=CirclePoint*CommonUtilities::Matrix4x4<float>().CreateRotationAroundY(rotationStep*j);
			CirclePoint.x += aStartPositon.x+aRadius;
			CirclePoint.y += aStartPositon.y+aRadius;
			CirclePoint.z += aStartPositon.z+aRadius;

			myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(CirclePoint.x,CirclePoint.y,CirclePoint.z,1)));
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
