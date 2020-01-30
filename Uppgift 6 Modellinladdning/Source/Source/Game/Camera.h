#pragma once
#include"Matrix/Matrix4x4.hpp"
#include "Vector/Vector4.hpp"
#include "Vector/Vector3.hpp"

class Camera
{
public:
	Camera()=default;
	void Init();

	CommonUtilities::Vector4<float>ToPostProjection(const CommonUtilities::Vector4<float>& aWorldPosition)const;
	void MoveCamera(const CommonUtilities::Vector3<float>& aMovement);
	void RotateCamera(const CommonUtilities::Matrix4x4<float>aRotation);

	float GetNearPlane() const;
	float GetFarPlane() const;
	float GetSpeed() const;

	const CommonUtilities::Matrix4x4<float>& GetTransform() const;
private:
	CommonUtilities::Matrix4x4<float> myTransform;
	CommonUtilities::Matrix4x4<float> myProjectionMatrix;
	float myNearPlane;
	float myFarPlane;
	float mySpeed;
};

