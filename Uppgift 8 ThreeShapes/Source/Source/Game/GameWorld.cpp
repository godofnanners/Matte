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
#include <fstream>
#include <iomanip>
#include <iostream>
#include <Macro.h>
#include "Cube.h"
#include "Sphere.h"
CGameWorld::CGameWorld()
{
	myCamera = new Camera();
	myCube = new Cube();
	mySphere = new Sphere();
}


CGameWorld::~CGameWorld()
{
	SAFE_DELETE(myCamera);
}

void CGameWorld::Init()
{
	myCamera->Init();
	myCube->Init(10, 0.9f, CommonUtilities::Vector4<float>(0, 0, 0,1));
	mySphere->Init(4, 20, CommonUtilities::Vector4<float>(10, 0, 0,1));
}


void CGameWorld::Update(float aTimeDelta, CommonUtilities::InputHandler aInputHandler)
{
	auto cameraTransform = myCamera->GetTransform();

	if (aInputHandler.CheckIfKeyIsHeld('W'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * (-1 * myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('A'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * (-1 * myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('S'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * (myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('D'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * (myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld(VK_RIGHT))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(myCamera->GetSpeed() * aTimeDelta));
		myCamera->RotateCamera(rotation);
	}
	if (aInputHandler.CheckIfKeyIsHeld(VK_LEFT))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(-1 * myCamera->GetSpeed() * aTimeDelta));
		myCamera->RotateCamera(rotation);
	}

	if (aInputHandler.CheckIfKeyIsHeld(VK_UP))
	{
		myCamera->MoveCamera(cameraTransform.GetUp() * (myCamera->GetSpeed() * aTimeDelta));
	}

	if (aInputHandler.CheckIfKeyIsHeld(VK_DOWN))
	{
		myCamera->MoveCamera(cameraTransform.GetUp() * (-1 * myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('T'))
	{
		mySphere->Rotate(myCube->X, 5.f);
	}
	if (aInputHandler.CheckIfKeyIsHeld('G'))
	{
		mySphere->Rotate(myCube->Y, 5.f);
	}
	if (aInputHandler.CheckIfKeyIsHeld('B'))
	{
		mySphere->Rotate(myCube->Z, 5.f);
	}
	// Update all the things
	mySphere->UpdatePoints(myCamera);
	myCube->UpdatePoints(myCamera);
}





void CGameWorld::Render()
{
	myCube->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
	mySphere->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
}
