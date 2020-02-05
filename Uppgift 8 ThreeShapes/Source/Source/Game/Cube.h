#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
#include "Matrix/Matrix4x4.hpp"
class Cube :public Shape
{
public:
	void Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector4<float> aStartPositon);
	void Render(const float aNear, const float aFar);
private:
	float mySide;

};

