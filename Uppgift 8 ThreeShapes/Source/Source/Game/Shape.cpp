#include "stdafx.h"
#include "Shape.h"
#include <algorithm>
void Shape::UpdatePoints(const Camera* aCamera)
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->UpdatePotato(aCamera);

	}
	
	std::sort(myPotatoes.begin(), myPotatoes.end(), Potato::ComparePotatoes);
}

void Shape::Rotate(RotationType aRotationType, float aRotationAmount)
{
	switch (aRotationType)
	{
	case X:
		myMatrix = CommonUtilities::Matrix4x4<float>().CreateRotationAroundX(aRotationAmount) * myMatrix;
		break;
	case Y:
		myMatrix = CommonUtilities::Matrix4x4<float>().CreateRotationAroundY(aRotationAmount) * myMatrix;
		break;
	case Z:
		myMatrix = CommonUtilities::Matrix4x4<float>().CreateRotationAroundZ(aRotationAmount) * myMatrix;
		break;
	case None:
		break;
	default:
		break;
	}
}

Shape::~Shape()
{
	for (auto p : myPotatoes)
	{
		SAFE_DELETE(p);
	}
	myPotatoes.clear();
}
