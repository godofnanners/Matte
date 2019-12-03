#pragma once
#include "Vector/Vector2.h"
namespace Tga2D
{
	class CSprite;
}
class ChildMoon
{

public:
	ChildMoon() = delete;
	ChildMoon(const CommonUtilities::Vector2<float>& aParentSpace);
	void Init();
	void Update(float aTimeDelta);
	CommonUtilities::Vector2<float> GetWorldPosition();
	void Draw();
private:
	const CommonUtilities::Vector2<float>& myParentSpace;
	CommonUtilities::Vector2<float> myPosition;
	float myRotation;
	float myRotationSpeed;
	float myOrbitAngle;
	float myOrbitAngleSpeed;
	Tga2D::CSprite* mySprite;
};

