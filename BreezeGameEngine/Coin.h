/***************************************************************************/
/***               Temper Tech Directly V 1.0.0                          ***/
/*** Coin.h                                                              ***/
/*** Copyright for all time (if your law disagrees, it can suck it)      ***/
/***                                                                     ***/
/*** Part of Directly(c)                                                 ***/
/***                                                                     ***/
/*** Proprietary Software, do not read.                                  ***/
/*** You cannot use it, look at it, or have it on your computer,         ***/
/*** unless you are a working member of Temper Tech                      ***/
/***                                                                     ***/
/*** If you need help, go fuck yourself.                                 ***/
/***************************************************************************/
#pragma once

#include "Graphics.h"
#include "Vec.h"

class Coin
{
public:
	Coin(float x, float y, float vx, float vy);
	Coin(Vec pos, Vec vel);
	Coin();
	void Init(float x, float y, float vx, float vy);
	void Update(float dt);
	void Draw( Graphics& gfx );
	bool IsGot() const;
	void Get();
	void Nab();
	Vec PollPos() const;
	void SetPos(const float x, const float y);
	void SetPos(const Vec pos);
	Vec PollVel() const;
	void SetVel(const float vx, const float vy);
	void SetVel(const Vec vel);
	bool CoinColl(const Coin& TCoin) const;
	void CoinBounce(Coin& TCoin);
	static constexpr float W = 5.0f;
	static constexpr float H = 7.0f;

private:
	Vec Pos;
	Vec Vel;
	bool Got = false;
};