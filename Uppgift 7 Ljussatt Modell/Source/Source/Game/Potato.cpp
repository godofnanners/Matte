#include "stdafx.h"
#include "Potato.h"
#include "tga2d/sprite/sprite.h"
#include "Matrix/Matrix4x4.hpp"
#include "Macro.h"
Potato::Potato(const CommonUtilities::Vector4<float>& aPosition) :
	mySprite(new Tga2D::CSprite("sprites/White pixel.png"))
{
	myPosition = aPosition;
	myColor = new Tga2D::CColor(1.f, 1.f, 1.f, 1.f);
	myZDistance = 0;
	mySprite->SetPivot({ 0.5f,0.5f });
}

Potato::Potato(const CommonUtilities::Vector4<float>& aPosition, const CommonUtilities::Vector3<float>& aNormal, const Tga2D::CColor aColor) :
	mySprite(new Tga2D::CSprite("sprites/White_pixel.dds")),
	myColor(new Tga2D::CColor(aColor))
{
	myPosition = aPosition;
	myNormal = aNormal;
	myZDistance = 0;
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetColor(*myColor);
}

Potato::~Potato()
{
	SAFE_DELETE(mySprite);
	SAFE_DELETE(myColor);
}

void Potato::Render(const float aNear, const float aFar) const
{
	if (myZDistance > aNear && myZDistance < aFar)
	{
		mySprite->Render();
	}
}

void Potato::UpdatePotato(const Camera* aCamera, const bool aSpecBool, const bool aDiffBool)
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
	mySprite->SetColor(UpdateLight(myColor, aCamera,aSpecBool,aDiffBool));
}

Tga2D::CColor Potato::UpdateLight(const Tga2D::CColor* aColor, const Camera* aCamera,const bool aSpecBool,const bool aDiffBool)
{

	CommonUtilities::Vector4<float> AmbientColor = { 0.1f,0.1f,0.1f,1.f };
	CommonUtilities::Vector4<float> DiffuseColor = { 0.f,0.f ,0.f ,0.f };
	CommonUtilities::Vector4<float> SpeccularColor = { 0.f,0.f,0.f,0.f };
	CommonUtilities::Vector4<float> LightColor = { 1.f,1.f,1.f,1.f };
	float SpecIntens = 5.f;
	CommonUtilities::Vector4<float> ColorVec;
	ColorVec.x = aColor->myR;
	ColorVec.y = aColor->myG;
	ColorVec.z = aColor->myB;
	ColorVec.w = aColor->myA;
	CommonUtilities::Vector3<float> Light = aCamera->GetTransform().GetForward();
	Light.Normalize();
	Light *= -1.f;
	//ambient
	AmbientColor= CommonUtilities::Vector4<float>().CompMult(AmbientColor, ColorVec);
	//diffuse
	if (aDiffBool)
	{
		//DiffuseColor = { 0.8f,0.8f ,0.8f ,1.f };
		DiffuseColor = CommonUtilities::Vector4<float>().CompMult(LightColor, ColorVec);

		DiffuseColor *= (myNormal.Dot(Light) > 0) ? myNormal.Dot(Light) : 0;
	}
	
	//specular
	if (aSpecBool && myNormal.Dot(Light) > 0)
	{
		SpeccularColor = { 1.f,1.f,1.f,1.f };
		CommonUtilities::Vector3<float> CameraPosition = aCamera->GetPosition();
		CommonUtilities::Vector3<float> V = { CameraPosition.x - myPosition.x, CameraPosition.y - myPosition.y ,CameraPosition.z - myPosition.z };
		V.Normalize();
		CommonUtilities::Vector3<float> R = ((2 * (myNormal.Dot(Light)) * myNormal) - (Light));
		R.Normalize();
		
		SpeccularColor = CommonUtilities::Vector4<float>().CompMult(SpeccularColor, LightColor);
		SpeccularColor *= pow(((V.Dot(R) > 0) ? V.Dot(R) : 0),SpecIntens);
	}
	

	//add all
	Tga2D::CColor newColor;
	newColor.myR = AmbientColor.x + DiffuseColor.x + SpeccularColor.x;
	newColor.myG = AmbientColor.y + DiffuseColor.y + SpeccularColor.y;
	newColor.myB = AmbientColor.z + DiffuseColor.z + SpeccularColor.z;
	newColor.myA = AmbientColor.w + DiffuseColor.w + SpeccularColor.w;

	return newColor;
}

bool Potato::ComparePotatoes(const Potato* aPotato, const Potato* aSecondPotato)
{
	return aPotato->myZDistance > aSecondPotato->myZDistance;
}
