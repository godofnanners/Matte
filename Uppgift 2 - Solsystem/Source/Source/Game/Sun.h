#pragma once
#include "Vector/Vector2.h"
#include "ChildPlanet.h"
namespace Tga2D
{
	class CSprite;
}

class Sun
{
public:
	Sun();
	void Init();
	void Update(float aTimeDelta);
	void Draw();
private:
	CommonUtilities::Vector2<float> myPosition;
	float myRotation;
	float myRotationSpeed;
	Tga2D::CSprite * mySprite;
	ChildPlanet * myChildPlanet;
};

