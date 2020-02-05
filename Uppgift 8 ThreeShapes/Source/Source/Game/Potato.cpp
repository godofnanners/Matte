#include "stdafx.h"
#include "Potato.h"
#include "tga2d/sprite/sprite.h"
#include "Macro.h"
Potato::Potato(const CommonUtilities::Vector4<float>& aPosition) :
	mySprite(new Tga2D::CSprite("sprites/White_pixel.dds"))
{
	myPosition = aPosition;
	myZDistance = 0;
	mySprite->SetPivot({ 0.5f,0.5f });
}

Potato::Potato(const CommonUtilities::Vector4<float>& aPosition, const Tga2D::CColor aColor) :
	mySprite(new Tga2D::CSprite("sprites/White_pixel.dds")),
	myColor(new Tga2D::CColor(aColor))
{
	myPosition = aPosition;
	myZDistance = 0;
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetColor(*myColor);
}

Potato::~Potato()
{
	SAFE_DELETE(mySprite);
}

void Potato::Render(const float aNear, const float aFar) const
{
	if (myZDistance > aNear && myZDistance < aFar)
	{
		mySprite->Render();
	}
}

void Potato::SetPosition(const CommonUtilities::Vector4<float>&aNewPosition)
{
	myPosition = aNewPosition;
}

const CommonUtilities::Vector4<float>& Potato::GetPosition()
{
	return myPosition;
}

void Potato::UpdatePotato(const Camera * aCamera)
{
	CommonUtilities::Vector4<float> vector(aCamera->ToPostProjection(myPosition));
	myZDistance = vector.z;
	float inversW = 1 / vector.w;
	vector.x *= inversW;
	vector.y *= inversW;
	vector.z *= inversW;
	vector.w *= inversW;
	mySprite->SetSizeRelativeToImage({ 10.f / myZDistance,10.f / myZDistance });
	mySprite->SetPosition({ vector.x / 2.f + 0.5f,-1 * vector.y / 2.f + 0.5f });
}

bool Potato::ComparePotatoes(const Potato* aPotato, const Potato* aSecondPotato)
{
	return aPotato->myZDistance > aSecondPotato->myZDistance;
}
