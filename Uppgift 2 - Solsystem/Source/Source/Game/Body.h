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
	Body();
	Body(const Body * aParent);
	void Init(Tga2D::CSprite* aBodySprite, CommonUtilities::Vector2<float> aPosition, float aRotation, std::vector<Body>aChildreList = std::vector<Body>());
	void Update(float aTimeDelta);
	const CommonUtilities::Vector2<float> GetWorldPosition() const;
	void Draw();
private:
	const Body * myParent;
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


