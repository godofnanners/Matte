#pragma once
#include "Sun.h"
#include "Body.h"
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
	Body mySun;
	std::vector<Body> myPlanets;
	std::vector<Body> myMoons;
	Tga2D::CSprite* myTga2dLogoSprite;
	float mySpriteRotation;
};