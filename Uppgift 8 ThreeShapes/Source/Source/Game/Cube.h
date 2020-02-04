#pragma once
#include "Shape.h"
#include "Vector/Vector3.hpp"
class Cube :public Shape
{
public:
	void Init(float aSide,float aSpaceBetweenPoints,CommonUtilities::Vector3<float> aStartPositon);
	void UpdatePoints(const Camera* aCamera);
	void Render();
private:
	float mySide;
};

