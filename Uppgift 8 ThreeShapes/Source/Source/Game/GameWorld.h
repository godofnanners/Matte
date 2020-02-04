#pragma once
#include <vector>
#include <string>
#include <array>

class Potato;
class Camera;

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

struct ObjectData
{
	ObjectData(std::array<float, 11>aValueList) :myValues(aValueList)
	{

	}
	std::array<float, 11> myValues = { 0 };
};


class CGameWorld
{
public:
	CGameWorld();
	~CGameWorld();

	void Init();
	void Update(float aTimeDelta, CommonUtilities::InputHandler aInputHandler);
	void ReadObjectDataFromFile(const std::string& FilePath, std::vector<ObjectData>& aObjectList);
	void AddModelPoints(const std::vector<ObjectData>& aObjectDataList, std::vector<Potato*>& aPotatoList);
	void Render();
private:
	std::vector<Potato*> myPotatoes;
	std::vector<ObjectData> myObjectData;
	Camera* myCamera;
};