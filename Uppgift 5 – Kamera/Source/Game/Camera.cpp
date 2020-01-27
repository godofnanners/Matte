#define _USE_MATH_DEFINES
#include "stdafx.h"
#include "Camera.h"
#include <cmath>
void Camera::Init()
{
	mySpeed = 4.f;
	myNearPlane = 1.f;
	myFarPlane = 50.f;
	float screenWidth = static_cast<float>(Tga2D::CEngine::GetInstance()->GetRenderSize().x);
	float screenHeight = static_cast<float>(Tga2D::CEngine::GetInstance()->GetRenderSize().y);

	float foV = M_PI * 0.5f;

	myProjectionMatrix(1, 1) = (1 / std::tanf(foV / 2));
	myProjectionMatrix(1, 2) = 0;
	myProjectionMatrix(1, 3) = 0;
	myProjectionMatrix(1, 4) = 0;

	myProjectionMatrix(2, 1) = 0;
	myProjectionMatrix(2, 2)=(screenWidth/screenHeight/std::tanf(foV/2));
	myProjectionMatrix(2, 3) = 0;
	myProjectionMatrix(2, 4) = 0;

	myProjectionMatrix(3, 1) = 0;
	myProjectionMatrix(3, 2) = 0;
	myProjectionMatrix(3, 3)=myFarPlane/(myFarPlane-myNearPlane);
	myProjectionMatrix(3, 4) = 1;

	myProjectionMatrix(4, 1) = 0;
	myProjectionMatrix(4, 2) = 0;
	myProjectionMatrix(4, 3) = (-1 *myNearPlane*myFarPlane)/(myFarPlane-myNearPlane);
	myProjectionMatrix(4, 4) = 0;
}

CommonUtilities::Vector4<float> Camera::ToPostProjection(const CommonUtilities::Vector4<float>& aWorldPosition) const
{
	return CommonUtilities::Vector4<float>();
}

void Camera::MoveCamera(const CommonUtilities::Vector3<float>& aMovement)
{
}

void Camera::RotateFamera(const CommonUtilities::Matrix4x4<float> aRotation)
{
}

float Camera::GetNearPlane() const
{
	return 0.0f;
}

float Camera::GetFarPlane() const
{
	return 0.0f;
}

float Camera::GetSpeed() const
{
	return 0.0f;
}

const CommonUtilities::Matrix4x4<float>& Camera::GetTransform() const
{
	return myTransform;
}
