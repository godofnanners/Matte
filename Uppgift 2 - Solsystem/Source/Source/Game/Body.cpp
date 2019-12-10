#include "stdafx.h"
#include "Body.h"
#include "stdafx.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/math/common_math.h>


Body::Body()
{
	myOrbitAngle = 0;
	myOrbitAngleSpeed = 0;
	myPosition = { 0,0 };
	myRotation = 0;
	myRotationSpeed = 0;
	myParent = nullptr;
}

Body::Body(const Body* aParent)
{
	myOrbitAngle = 0;
	myOrbitAngleSpeed = 0;
	myPosition = { 0,0 };
	myRotation = 0;
	myRotationSpeed = 0;
	myParent = aParent;
}

void Body::Init(Tga2D::CSprite* aBodySprite, CommonUtilities::Vector2<float> aPosition, float aRotation, std::vector<Body>aChildreList = std::vector<Body>())
{
	myOrbitAngleSpeed = 20.f;
	myPosition = aPosition;
	myRotationSpeed = aRotation;
	mySprite = aBodySprite;
	myChildren = aChildreList;
	mySprite = aBodySprite;
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetRotation(myRotation);
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

	for (int i = 0; i < myChildren.size(); i++)
	{
		myChildren[i].Update(aTimeDelta);
	}

}

const CommonUtilities::Vector2<float> Body::GetWorldPosition() const
{
	return { myPosition.x * Tga2D::CEngine::GetInstance()->GetWindowRatioInversed() + myParent->GetWorldPosition().x, myPosition.y + myParent->GetWorldPosition().y };
}

void Body::Draw()
{
	mySprite->Render();
	for (int i = 0; i < myChildren.size(); i++)
	{
		myChildren[i].Draw();
	}
}