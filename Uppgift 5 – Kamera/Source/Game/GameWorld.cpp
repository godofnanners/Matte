#include "stdafx.h"
#include "GameWorld.h"
#include "Camera.h"
#include "Potato.h"
#include "Random/Random.hpp"
#include "InputHandler/InputHandler.h"
#include <tga2d/sprite/sprite.h>
#include <tga2d/error/error_manager.h>
#include <tga2d/model/Fbxmodel.h>
#include <tga2d/audio/audio.h>
#include <algorithm>
CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
	myCamera = new Camera();
}


CGameWorld::~CGameWorld()
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
}

void CGameWorld::Init()
{
	myCamera->Init();
	myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.5f, 0.5f });
	myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(-5.f, -5.f, 25.f, 1.f)));
	myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(10.f, -5.f, 25.f, 1.f)));
	myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(-5.f, 10.f, 25.f, 1.f)));
	myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(10.f, 10.f, 25.f, 1.f)));

	for (size_t i = 0; i < 11; i++)
	{
		myPotatoes.push_back(new Potato(CommonUtilities::Vector4<float>(CommonUtilities::GetRandomFloat(-5.f,5.f), CommonUtilities::GetRandomFloat(-5.f, 5.f), CommonUtilities::GetRandomFloat(5.f, 20.f), 1.f)));
	}
}


void CGameWorld::Update(float aTimeDelta,CommonUtilities::InputHandler aInputHandler)
{
	auto cameraTransform = myCamera->GetTransform();

	if (aInputHandler.CheckIfKeyIsHeld('W'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * myCamera->GetSpeed() * (-1.f) * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('A'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * myCamera->GetSpeed() * (-1.f) * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('S'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * myCamera->GetSpeed() * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('D'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * myCamera->GetSpeed() * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('E'))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(-1 * myCamera->GetSpeed() * aTimeDelta));
		myCamera->RotateCamera(rotation);
	}
	if (aInputHandler.CheckIfKeyIsHeld('Q'))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(myCamera->GetSpeed() * aTimeDelta));
		myCamera->RotateCamera(rotation);
	}
	// Update all the things
	for (size_t i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->UpdatePotato(myCamera);
	}
	std::sort(myPotatoes.begin(), myPotatoes.end(), Potato::ComparePotatoes);
}

void CGameWorld::Render()
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
	}
}
