#include "stdafx.h"
#include "Cube.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
void Cube::Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector4<float> aStartPositon)
{
	myMatrix.AddToTranslation(CommonUtilities::Vector3<float>(aStartPositon.x, aStartPositon.y, aStartPositon.z));
	for (float width = 0; width < aSide; width++)
	{
		for (float height = 0; height < aSide; height++)
		{
			for (float depth = 0; depth < aSide; depth++)
			{
				if (height == 0 || width == 0 || height == aSide - 1 || width == aSide - 1 || depth == 0 || depth == aSide - 1)
				{
					myPotatoes.push_back(new Potato((CommonUtilities::Vector4<float>(aSpaceBetweenPoints * width, aSpaceBetweenPoints * height, aSpaceBetweenPoints * depth, 1) + aStartPositon)));
				}
			}
		}
	}
}

void Cube::Render(const float aNear, const float aFar)
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->SetPosition(myPotatoes[i]->GetPosition() * myMatrix);
		myPotatoes[i]->Render(aNear, aFar);
	}
}
