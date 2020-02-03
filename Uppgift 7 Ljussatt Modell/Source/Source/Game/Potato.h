#pragma once
#include "Vector/Vector4.hpp"
#include "Vector/Vector3.hpp"
#include "Camera.h"

namespace Tga2D
{
	class CSprite;
	class CColor;
	class FBXModel;
	class CAudio;
}

class Potato
{
public:
	Potato(const CommonUtilities::Vector4<float>& aPosition);
	Potato(const CommonUtilities::Vector4<float>& aPosition,const CommonUtilities::Vector3<float>& aNormal,const Tga2D::CColor aColor);
	~Potato();

	void Render(const float aNear, const float aFar)const;
	void UpdatePotato(const Camera* aCamera, const bool aSpecBool, const bool aDiffBool);

	Tga2D::CColor UpdateLight(const Tga2D::CColor* aColor, const Camera* aCamera, const bool aSpecBool, const bool aDiffBool);


	static bool ComparePotatoes(const Potato* aPotato, const Potato* aSecondPotato);
private:
	CommonUtilities::Vector4<float>myPosition;
	float myZDistance;
	CommonUtilities::Vector3<float>myNormal;
	Tga2D::CSprite* mySprite;
	Tga2D::CColor* myColor;
};

