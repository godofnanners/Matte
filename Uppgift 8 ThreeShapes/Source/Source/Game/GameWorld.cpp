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
#include "Torus.h"

CGameWorld::CGameWorld()
{
	myCamera = new Camera();
	myCube = new Cube();
	mySphere = new Sphere();
	myTorus = new Torus();
}


CGameWorld::~CGameWorld()
{
	SAFE_DELETE(myCamera);
}

void CGameWorld::Init()
{
	myCamera->Init();
	myCube->Init(15, 0.3f, CommonUtilities::Vector3<float>(-10, 0, 0));
	mySphere->Init(2.5f, 41, CommonUtilities::Vector3<float>(0, 0, 0),40);
	myTorus->Init(1.f, 2.f, 40, CommonUtilities::Vector3<float>(10, 0, 0), 40);
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
		myCube->Rotate(myCube->X, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('G'))
	{
		myCube->Rotate(myCube->Y, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('B'))
	{
		myCube->Rotate(myCube->Z, 1.f*aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('Y'))
	{
		mySphere->Rotate(myCube->X, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('H'))
	{
		mySphere->Rotate(myCube->Y, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('N'))
	{
		mySphere->Rotate(myCube->Z, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('U'))
	{
		myTorus->Rotate(myCube->X, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('J'))
	{
		myTorus->Rotate(myCube->Y, 1.f * aTimeDelta);
	}
	if (aInputHandler.CheckIfKeyIsHeld('M'))
	{
		myTorus->Rotate(myCube->Z, 1.f * aTimeDelta);
	}
	// Update all the things
	myTorus->Update();
	mySphere->Update();
	myCube->Update();
	mySphere->UpdatePoints(myCamera);
	myCube->UpdatePoints(myCamera);
	myTorus->UpdatePoints(myCamera);
}

void CGameWorld::Render()
{
	myCube->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
	mySphere->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
	myTorus->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
}
