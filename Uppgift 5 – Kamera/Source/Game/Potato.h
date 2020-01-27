#pragma once
#include "Vector/Vector4.hpp"
#include "Camera.h"
class Potato
{
public:
	Potato(const CommonUtilities::Vector4<float>& aPosition);
	~Potato();

	void Render(const float aNear, const float aFar)const;
	void UpdatePotato(const Camera& aCamera);

	static bool ComparePotatoes(const Potato* aPotato, const Potato* aSecondPotato);
private:
	CommonUtilities::Vector4<float>myPosition;
	float myZDistance;
	Tga2D::CSprite* mySprite;
};

