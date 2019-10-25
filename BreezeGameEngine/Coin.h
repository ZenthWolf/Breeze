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

class Coin
{
public:
	Coin(float x, float y, float vx, float vy);
	Coin();
	void Init(float x, float y, float vx, float vy);
	void Update(float dt);
	void Draw( Graphics& gfx );
	bool IsGot() const;
	void Get();
	void Nab();
	float PollX();
	float PollY();
	void SetX(float x);
	void SetY(float y);
	float PollVx();
	float PollVy();
	void SetVx(float vx);
	void SetVy(float vy);
	void CoinColl(Coin& TCoin);
	static constexpr float W = 5.0f;
	static constexpr float H = 7.0f;

private:
	float X;
	float Y;
	float Vx;
	float Vy;
	bool Got = false;
};