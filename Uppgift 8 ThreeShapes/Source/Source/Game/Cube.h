#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
#include "Matrix/Matrix4x4.hpp"
class Cube :public Shape
{
public:
	void Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector3<float> aStartPositon);
	void Update();
	void Render(const float aNear, const float aFar);
private:
	float mySide;
	float mySpaceBetweenPoints;
	CommonUtilities::Vector3<float> myStartPosition;
};

