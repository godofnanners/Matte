#include "stdafx.h"
#include "ChildPlanet.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/math/common_math.h>


ChildPlanet::ChildPlanet(const CommonUtilities::Vector2<float>& aParentSpace):myParentSpace(aParentSpace)
{
	myOrbitAngle = 0;
	myOrbitAngleSpeed = 0;
	myPosition = { 0,0 };
	myOffset = { 0,0 };
	mySprite = nullptr;
	myRotation = 0;
	myRotationSpeed = 0;
}

void ChildPlanet::Init()
{
	myOrbitAngleSpeed = 2.f;
	myPosition = CommonUtilities::Vector2(0.1f, 0.1f);
	myRotationSpeed = 2;
	mySprite = new Tga2D::CSprite("sprites/planet1.dds");
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetPosition({ myPosition.x,myPosition.y });
	mySprite->SetRotation(myRotation);
}
void ChildPlanet::Update(float aTimeDelta)
{
	myOrbitAngle = aTimeDelta* myOrbitAngleSpeed ;
	myPosition = {(myPosition.x)*cos(myOrbitAngle)-(myPosition.y)*sin(myOrbitAngle),
					(myPosition.x)* sin(myOrbitAngle) + (myPosition.y) * cos(myOrbitAngle)};
	myRotation += myRotationSpeed * aTimeDelta;
	mySprite->SetRotation(myRotation);
	mySprite->SetPosition({ GetWorldPosition().x,GetWorldPosition().y });
}

CommonUtilities::Vector2<float> ChildPlanet::GetWorldPosition()
{
	return { myPosition.x + myParentSpace.x, myPosition.y + myParentSpace.y };
}

void ChildPlanet::Draw()
{
	mySprite->Render();
}