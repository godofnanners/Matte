#pragma once
#include "Potato.h"
#include <vector>
#include "Macro.h"
	
class Shape
{
public:
	enum RotationType
	{
		X,Y,Z,None
	};
	virtual void UpdatePoints(const Camera* aCamera);
	void Rotate(RotationType aRotationType, float aRotationAmount);
	virtual ~Shape();
protected:
	std::vector<Potato*>myPotatoes;
	CommonUtilities::Matrix4x4<float> myMatrix;
};

