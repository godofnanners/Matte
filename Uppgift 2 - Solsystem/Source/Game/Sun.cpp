#include "stdafx.h"
#include "Sun.h"
#include <tga2d/sprite/sprite.h>

Sun::Sun()
{
	mySprite = nullptr;
	myPosition = {0,0};
	myRotation = 0;
	myRotationSpeed = 0;
}

void Sun::Init()
{
	myPosition = CommonUtilities::Vector2(0.5f,0.5f);
	myRotationSpeed = 1;
	mySprite= new Tga2D::CSprite("sprites/sun.dds");
	mySprite->SetPivot({ 0.5f,0.5f });
	mySprite->SetPosition({ myPosition.x,myPosition.y });
	mySprite->SetRotation(myRotation);
	myChildPlanet = new ChildPlanet(myPosition);
	myChildPlanet->Init();
}

void Sun::Update(float aTimeDelta)
{
	myRotation += myRotationSpeed*aTimeDelta;
	mySprite->SetRotation(myRotation);
	myChildPlanet->Update(aTimeDelta);
}

void Sun::Draw()
{
	mySprite->Render();
	myChildPlanet->Draw();
}
