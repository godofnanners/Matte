#include "stdafx.h"
#include "ChildMoon.h"
#include "stdafx.h"
#include "ChildPlanet.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/math/common_math.h>


ChildMoon::ChildMoon(const CommonUtilities::Vector2<float>& aParentSpace) :myParentSpace(aParentSpace)
{
	myOrbitAngle = 0;
	myOrbitAngleSpeed = 0;
	myPosition = { 0,0 };
	mySprite = nullptr;
	myRotation = 0;
	myRotationSpeed = 0;
}

void ChildMoon::Init()
{
	myOrbitAngleSpeed = 50.f;
	myPosition = CommonUtilities::Vector2(0.1f, 0.1f);
	myRotationSpeed = -5;
	mySprite = new Tga2D::CSprite("sprites/moon.dds");
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetRotation(myRotation);

}
void ChildMoon::Update(float aTimeDelta)
{
	myOrbitAngle = aTimeDelta * myOrbitAngleSpeed;
	myOrbitAngle = Tga2D::DegToRad(myOrbitAngle);
	float cos = Tga2D::DX2D_Cos(myOrbitAngle);
	float sin = Tga2D::DX2D_Sin(myOrbitAngle);

	float x = (myPosition.x) * cos - (myPosition.y * sin);
	float y = (myPosition.x) * sin + (myPosition.y * cos);

	myPosition.x = x;
	myPosition.y = y;

	myRotation += myRotationSpeed * aTimeDelta;
	mySprite->SetRotation(myRotation);
	mySprite->SetPosition({ GetWorldPosition().x  ,GetWorldPosition().y });


}

CommonUtilities::Vector2<float> ChildMoon::GetWorldPosition()
{
	return { myPosition.x * Tga2D::CEngine::GetInstance()->GetWindowRatioInversed() + myParentSpace.x, myPosition.y + myParentSpace.y };
}

void ChildMoon::Draw()
{
	mySprite->Render();
}