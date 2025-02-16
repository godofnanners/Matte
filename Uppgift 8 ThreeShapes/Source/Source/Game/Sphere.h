#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
class Sphere :public Shape
{
public:
	void Init(float aRadius, int anAmountOfPoints, CommonUtilities::Vector3<float> aStartPositon, int anAmountOfRows=20);

	void Update();
	
	void Render(const float aNear, const float aFar);
private:
	float myRadius;
	CommonUtilities::Vector3<float>myStartPosition;
	float myPointStep;
	float myRotationStep;
	int myAmountOfCircles;
	int myAmountOfPoints;
};

