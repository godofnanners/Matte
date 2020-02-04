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
CGameWorld::CGameWorld()
{
	myCamera = new Camera();
	mySpecBool = true;
	myDiffBool = true;
}


CGameWorld::~CGameWorld()
{
	SAFE_DELETE(myCamera);
}

void CGameWorld::Init()
{
	ReadObjectDataFromFile("Model.txt", myObjectData);

	AddModelPoints(myObjectData,myPotatoes);

	myCamera->Init();

	
	
}


void CGameWorld::Update(float aTimeDelta, CommonUtilities::InputHandler aInputHandler)
{
	auto cameraTransform = myCamera->GetTransform();

	if (aInputHandler.CheckIfKeyIsHeld('W'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * (myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('A'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * (-1 * myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('S'))
	{
		myCamera->MoveCamera(cameraTransform.GetForward() * (-1*myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld('D'))
	{
		myCamera->MoveCamera(cameraTransform.GetRight() * (myCamera->GetSpeed() * aTimeDelta));
	}
	if (aInputHandler.CheckIfKeyIsHeld(VK_RIGHT))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(myCamera->GetRotationSpeed() * aTimeDelta));
		myCamera->RotateCamera(rotation);
	}
	if (aInputHandler.CheckIfKeyIsHeld(VK_LEFT))
	{
		CommonUtilities::Matrix4x4<float> rotation(CommonUtilities::Matrix4x4<float>::CreateRotationAroundY(-1 * myCamera->GetRotationSpeed() * aTimeDelta));
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
	if (aInputHandler.CheckIfKeyIsPressed('1'))
	{
		myDiffBool = !myDiffBool;
	}
	if (aInputHandler.CheckIfKeyIsPressed('2'))
	{
		mySpecBool = !mySpecBool;
	}

	
	// Update all the things
	for (size_t i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->UpdatePotato(myCamera,mySpecBool,myDiffBool);
	}
	std::sort(myPotatoes.begin(), myPotatoes.end(), Potato::ComparePotatoes);
}

void CGameWorld::ReadObjectDataFromFile(const std::string& FilePath, std::vector<ObjectData>& aObjectList)
{
	std::ifstream inFile;

	inFile.open(FilePath);
	if (!inFile)
	{
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}

	int valuesIndex = 0;
	int objectIndex = 0;
	std::array<float, 11> valueList;
	while (inFile >> valueList[valuesIndex])
	{
		valuesIndex++;
		if (valuesIndex >= valueList.size())
		{
			aObjectList.push_back(ObjectData(valueList));
			valuesIndex = 0;
		}
	}

	inFile.close();
}

void CGameWorld::AddModelPoints(const std::vector<ObjectData>& aObjectDataList, std::vector<Potato*>& aPotatoList)
{
	CommonUtilities::Vector4<float> position;
	CommonUtilities::Vector3<float> normal;
	for (unsigned int i = 0; i < aObjectDataList.size(); i++)
	{
		int valueSize = aObjectDataList[i].myValues.size();

		position = { aObjectDataList[i].myValues[0], aObjectDataList[i].myValues[1], aObjectDataList[i].myValues[2], 1.f };

		normal = { aObjectDataList[i].myValues[3], aObjectDataList[i].myValues[4], aObjectDataList[i].myValues[5] };

		Tga2D::CColor color = Tga2D::CColor(aObjectDataList[i].myValues[valueSize - 3]/255, aObjectDataList[i].myValues[valueSize - 2] / 255, aObjectDataList[i].myValues[valueSize - 1] / 255, 1.f);
		aPotatoList.push_back(new Potato(position,normal, color));
	}
}

void CGameWorld::Render()
{
	for (int i = 0; i < myPotatoes.size(); i++)
	{
		myPotatoes[i]->Render(myCamera->GetNearPlane(), myCamera->GetFarPlane());
	}
}
