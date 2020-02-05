#pragma once
#include <vector>
#include <string>
#include <array>

class Potato;
class Camera;
class Cube;
class Sphere;
namespace Tga2D
{
	class CSprite;
	class FBXModel;
	class CAudio;
}
namespace CommonUtilities
{
	class InputHandler;
}




class CGameWorld
{
public:
	CGameWorld();
	~CGameWorld();

	void Init();
	void Update(float aTimeDelta, CommonUtilities::InputHandler aInputHandler);
	void Render();
private:
	Cube * myCube;
	Sphere* mySphere;
	Camera* myCamera;
};