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
	mySpriteRotation = 0;
	myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.5f, 0.5f });
	mySun.Init();
}


void CGameWorld::Update(float aTimeDelta)
{ 	
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		Tga2D::CEngine::Shutdown();
	}
	/*mySpriteRotation += aTimeDelta;
	myTga2dLogoSprite->SetRotation(mySpriteRotation);
	myTga2dLogoSprite->Render();*/
	mySun.Update(aTimeDelta);
	mySun.Draw();
}