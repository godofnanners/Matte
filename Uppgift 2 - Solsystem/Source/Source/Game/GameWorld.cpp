#include "stdafx.h"
#include "GameWorld.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/error/error_manager.h>
CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
}


CGameWorld::~CGameWorld()
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
}

void CGameWorld::Init()
{
	myMoons = std::vector<Body>();
	myPlanets = std::vector<Body>();
	//create planets and moons in lists
	for (int i = 0; i < 2; i++)
	{
		myPlanets.push_back(Body(&mySun));
	}
	for (int i = 0; i < 1; i++)
	{
		for (int i = 0; i < myPlanets.size(); i++)
		{
			myMoons.push_back(Body(&myPlanets[i]));
		}
	}

	//init moons and planets with position and other values
	for (int i = 0; i < myMoons.size(); i++)
	{
		myMoons[i].Init(new Tga2D::CSprite("sprites/moon.dds"), CommonUtilities::Vector2(0.05f , 0.05f ), -10 + i, -40);
	}
	for (int i = 0; i < myPlanets.size(); i++)
	{
		myPlanets[i].Init(new Tga2D::CSprite("sprites/planet1.dds"), CommonUtilities::Vector2(0.1f * (i + 1), 0.1f * (i + 1)), 2*(i+1), 20 * (i + 1), &myMoons);
	}

	mySun.Init(new Tga2D::CSprite("sprites/sun.dds"), CommonUtilities::Vector2(0.5f, 0.5f), 5, 0, &myPlanets);
}


void CGameWorld::Update(float aTimeDelta)
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		Tga2D::CEngine::Shutdown();
	}
	mySun.Update(aTimeDelta);
	mySun.Draw();
}