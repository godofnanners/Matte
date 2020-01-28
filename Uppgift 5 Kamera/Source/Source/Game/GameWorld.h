#pragma once
#include <vector>
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
class Potato;
class Camera;
class CGameWorld
{
public:
	CGameWorld();
	~CGameWorld();

	void Init();
	void Update(float aTimeDelta,CommonUtilities::InputHandler aInputHandler);
	void Render();
private:
	Tga2D::CSprite* myTga2dLogoSprite;
	std::vector<Potato*> myPotatoes;
	Camera * myCamera;
};