#pragma once
#include "Sun.h"
namespace Tga2D
{
	class CSprite;
}

class CGameWorld
{
public:
	CGameWorld(); 
	~CGameWorld();

	void Init();
	void Update(float aTimeDelta); 
private:
	Sun mySun;
	Tga2D::CSprite* myTga2dLogoSprite;
	float mySpriteRotation;
};