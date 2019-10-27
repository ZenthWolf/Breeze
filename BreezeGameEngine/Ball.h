#pragma once
#include "Graphics.h"
#include "Vec.h"
#include "RectF.h"
#include "Keyboard.h"

class Ball 
{
public:
	Ball();
	Ball(float x, float y, Color c);
	Ball(float x, float y, float speed, Color c);
	Ball(float x, float y, float speed, Vec initDir, Color c);
	Ball(Vec pos, float speed, Vec initDir, Color c);
	void Draw(Graphics& gfx);
	void Move(const float dt);
	bool CollWall(const RectF& wall);
	RectF GetRect() const;
	void BounceX();
	void BounceY();
	void BounceY(const Vec offx);
	void MoveX(const float dx);
	Vec GetPos() const;
	Vec GetVel() const;
	void SetHeldPos(const Vec& padPos, const float padHeight);
	void SetDir(const Vec Dir);
	float GetRad() const;
	int SayState() const;
	void HeldUpdate(Keyboard& kbd);

private:
	Vec Pos;
	Vec HeldPos = { 0.0f, 0.0f };
	Vec Vel;
	/* 0 = Held, 1 = Free*/
	int ballState = 0;
	float speed;
	static constexpr float R = 6.0f;
	Color C;
};