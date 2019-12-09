#pragma once
#include "Vector/Vector2.h"
#include "ChildMoon.h"
#include <vector>
namespace Tga2D
{
	class CSprite;
}
class Body
{

public:
	Body() = delete;
	Body(const CommonUtilities::Vector2<float>* aParentSpace, int anAmountOfChildren, Tga2D::CSprite* aSprite);
	void Init();
	void Update(float aTimeDelta);
	CommonUtilities::Vector2<float> GetWorldPosition();
	void Draw();
private:
	const CommonUtilities::Vector2<float> * myParentSpace;
	CommonUtilities::Vector2<float> myPosition;
	CommonUtilities::Vector2<float> myWorldPosition;
	float myRotation;
	float myRotationSpeed;
	float myOrbitAngle;
	float myOrbitAngleSpeed;
	int myAmountOfChildren;
	Tga2D::CSprite* mySprite;
	std::vector<Body>myChildren;
};


