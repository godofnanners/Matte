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

void Body::Init(Tga2D::CSprite* aBodySprite, CommonUtilities::Vector2<float> aPosition, float aRotation,float anOrbitRotation, std::vector<Body>*aChildrenList)
{
	myOrbitAngleSpeed = anOrbitRotation;
	myPosition = aPosition;
	myRotationSpeed = aRotation;
	mySprite = aBodySprite;
	myChildren = aChildrenList;
	mySprite = aBodySprite;
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetRotation(myRotation);
}
void Body::Update(float aTimeDelta)
{
	if (myParent!=nullptr)
	{
		myOrbitAngle = aTimeDelta * myOrbitAngleSpeed;
		myOrbitAngle = Tga2D::DegToRad(myOrbitAngle);
		float cos = Tga2D::DX2D_Cos(myOrbitAngle);
		float sin = Tga2D::DX2D_Sin(myOrbitAngle);

		float x = (myPosition.x) * cos - (myPosition.y * sin);
		float y = (myPosition.x) * sin + (myPosition.y * cos);

		myPosition.x = x;
		myPosition.y = y;
	}


	myRotation += myRotationSpeed * aTimeDelta;
	mySprite->SetRotation(myRotation);
	myWorldPosition = GetWorldPosition();
	mySprite->SetPosition({ myWorldPosition.x * Tga2D::CEngine::GetInstance()->GetWindowRatioInversed() ,myWorldPosition.y });

	if (myChildren!=nullptr)
	{
		for (int i = 0; i < myChildren->size(); i++)
		{
			(*myChildren)[i].Update(aTimeDelta);
		}
	}

}

const CommonUtilities::Vector2<float> Body::GetWorldPosition() const
{
	if (myParent==nullptr)
	{
		return { myPosition.x ,myPosition.y };
	}
	return { myPosition.x + myParent->GetWorldPosition().x, myPosition.y + myParent->GetWorldPosition().y };
}

void Body::Draw()
{
	mySprite->Render();
	if (myChildren != nullptr)
	{
		for (int i = 0; i < myChildren->size(); i++)
		{
			(*myChildren)[i].Draw();
		}
	}
	
}