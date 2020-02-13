#include "stdafx.h"
#include "Cube.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
void Cube::Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector4<float> aStartPositon)
{
	mySide = aSide;
	mySpaceBetweenPoints = aSpaceBetweenPoints;
	myStartPosition = aStartPositon;
	
	for (float width = 0; width < mySide; width++)
	{
		for (float height = 0; height < mySide; height++)
		{
			for (float depth = 0; depth < mySide; depth++)
			{
				if (height == 0 || width == 0 || height == mySide - 1 || width == mySide - 1 || depth == 0 || depth == mySide - 1)
				{
					myPotatoes.push_back(new Potato((CommonUtilities::Vector4<float>(0,0,0,0))));
				}
			}
		}
	}

}

void Cube::Update()
{
	int index = 0;
	for (float width = 0; width < mySide; width++)
	{
		for (float height = 0; height < mySide; height++)
		{
			for (float depth = 0; depth < mySide; depth++)
			{
				if (height == 0 || width == 0 || height == mySide - 1 || width == mySide - 1 || depth == 0 || depth == mySide - 1)
				{
					myPotatoes[index]->SetPosition((CommonUtilities::Vector4<float>(mySpaceBetweenPoints * width, mySpaceBetweenPoints * height, mySpaceBetweenPoints * depth, 1)+myStartPosition)*myMatrix);
					index++;
				}
			}
		}
	}
}

void Cube::Render(const float aNear, const float aFar)
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->Render(aNear, aFar);
	}
}
