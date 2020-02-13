#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
class Sphere :public Shape
{
public:
	void Init(float aRadius, int anAmountOfPoints, CommonUtilities::Vector4<float> aStartPositon, int anAmountOfRows=20);

	void Update();
	
	void Render(const float aNear, const float aFar);
private:
	float myRadius;
	CommonUtilities::Vector4<float>myStartPosition;
	float myPointStep;
	float myRotationStep;
	int myAmountOfRows;
	int myAmountOfPoints;
};

