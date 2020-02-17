#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
class Torus :public Shape
{
public:
	void Init(float aRadius,float aHoleRadius, int anAmountOfPoints,CommonUtilities::Vector3<float> aStartPositon, int anAmountOfCircles = 20);

	void Update();

	void Render(const float aNear, const float aFar);
private:
	float myRadius;
	float myHoleRadius;
	CommonUtilities::Vector3<float>myStartPosition;
	float myPointStep;
	float myRotationStep;
	int myAmountOfCircles;
	int myAmountOfPoints;
};

