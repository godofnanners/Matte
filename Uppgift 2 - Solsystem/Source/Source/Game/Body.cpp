#include "stdafx.h"
#include "Body.h"
#include "stdafx.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/math/common_math.h>


Body::Body(const CommonUtilities::Vector2<float> * aParentSpace,int anAmountOfChildren, Tga2D::CSprite* aSprite)
{
	myOrbitAngle = 0;
	myOrbitAngleSpeed = 0;
	myPosition = { 0,0 };
	mySprite = aSprite;
	myParentSpace = aParentSpace;
	myRotation = 0;
	myRotationSpeed = 0;
}

void Body::Init()
{
	myOrbitAngleSpeed = 20.f;
	myPosition = CommonUtilities::Vector2(0.2f, 0.2f);
	myRotationSpeed = 5;
	mySprite = new Tga2D::CSprite("sprites/planet1.dds");
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetRotation(myRotation);

	for (int i = 0; i < myChildren.size(); i++)
	{
		myChildren.push_back(Body(myWorldPosition,))
	}

	for (size_t i = 0; i < myChildren.size(); i++)
	{
		myChildren[i].Init();
	}

}
void Body::Update(float aTimeDelta)
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
	myWorldPosition = GetWorldPosition();
	mySprite->SetPosition({ GetWorldPosition().x  ,GetWorldPosition().y });
	myChildMoon->Update(aTimeDelta);
}

CommonUtilities::Vector2<float> Body::GetWorldPosition()
{
	return { myPosition.x * Tga2D::CEngine::GetInstance()->GetWindowRatioInversed() + myParentSpace.x, myPosition.y + myParentSpace.y };
}

void Body::Draw()
{
	mySprite->Render();
	myChildMoon->Draw();
}