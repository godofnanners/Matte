#include "stdafx.h"
#include "Cube.h"

void Cube::Init(float aSide, float aSpaceBetweenPoints, CommonUtilities::Vector3<float> aStartPositon)
{
	for (float height = 0; height < aSide; height+=aSpaceBetweenPoints)
	{
		for (float width = 0; width < aSide; width+=aSpaceBetweenPoints)
		{
			for (float depth = 0; depth < aSide; depth+=aSpaceBetweenPoints)
			{

			}
		}
	}
}

void Cube::UpdatePoints(const Camera* aCamera)
{
}

void Cube::Render()
{
}
