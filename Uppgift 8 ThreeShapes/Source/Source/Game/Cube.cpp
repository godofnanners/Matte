#include "stdafx.h"
#include "Cube.h"
#include "Vector/Vector4.hpp"
#include <algorithm>
void Cube::Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector4<float> aStartPositon)
{
	mySide = aSide;
	mySpaceBetweenPoints = aSpaceBetweenPoints;
	myStartPosition = aStartPositon;
	
	for (float width = myStartPosition.x-(mySide*0.5f); width < myStartPosition.x + mySide*0.5f; width++)
	{
		for (float height = myStartPosition.y - (mySide * 0.5f); height < mySide * 0.5f; height++)
		{
			for (float depth = myStartPosition.z - (mySide * 0.5f); depth < mySide * 0.5f; depth++)
			{
				if (height == myStartPosition.y - (mySide * 0.5f) || width == myStartPosition.x - (mySide * 0.5f)
					|| height == (myStartPosition.y + mySide * 0.5f) - 1 || width == (myStartPosition.x + mySide * 0.5f) - 1
					|| depth == myStartPosition.z - (mySide * 0.5f) || depth == (myStartPosition.z + mySide * 0.5f) - 1)
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
	for (float width = -(mySide * 0.5f); width < mySide * 0.5f; width++)
	{
		for (float height = -(mySide * 0.5f); height < mySide * 0.5f; height++)
		{
			for (float depth = -(mySide * 0.5f); depth < mySide * 0.5f; depth++)
			{
				if (height == -(mySide * 0.5f) || width == -(mySide * 0.5f) 
					|| height == (mySide * 0.5f)-1|| width == (mySide * 0.5f)-1
					|| depth == -(mySide * 0.5f) || (depth == mySide * 0.5f-1))
				{
					CommonUtilities::Vector4<float> position = CommonUtilities::Vector4<float>(mySpaceBetweenPoints * width, mySpaceBetweenPoints * height, mySpaceBetweenPoints * depth, 1);
					position = position * myMatrix;
					myPotatoes[index]->SetPosition(position+myStartPosition);
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
