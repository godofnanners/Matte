#pragma once
#include "Vector/Vector2.h"
namespace Tga2D
{
	class CSprite;
}
class ChildPlanet
{
public:
	ChildPlanet() = delete;
	ChildPlanet(const CommonUtilities::Vector2<float> &aParentSpace);
	void Init();
	void Update(float aTimeDelta);
	CommonUtilities::Vector2<float> GetWorldPosition();
	void Draw();
private:
	const CommonUtilities::Vector2<float>&myParentSpace;
	CommonUtilities::Vector2<float> myPosition;
	CommonUtilities::Vector2<float> myOffset;
	float myRotation;
	float myRotationSpeed;
	float myOrbitAngle;
	float myOrbitAngleSpeed;
	Tga2D::CSprite* mySprite;
};

