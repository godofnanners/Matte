#pragma once

class Hitbox
{
public:
	Hitbox(const Tga2D::Vector2<float>& aPosition, float aWidth, float aHeight);
	bool IsColliding(Hitbox aHitbox);
	float GetLeftSide();
	float GetRightSide();
	float GetTopSide();
	float GetBottomSide();

	Tga2D::Vector2<float> myPosition;
	float myWidth, myHeight;

private:

};