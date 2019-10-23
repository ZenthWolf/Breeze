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
	Coin(int x, int y, int vx, int vy);
	Coin();
	void Init(int x, int y, int vx, int vy);
	void Update();
	void Draw( Graphics& gfx );
	bool IsGot() const;
	void Get();
	int PollX();
	int PollY();
	void SetX(int x);
	void SetY(int y);
	int PollVx();
	int PollVy();
	void SetVx(int vx);
	void SetVy(int vy);
	void CoinColl(Coin& TCoin);
	static constexpr int W = 5;
	static constexpr int H = 7;

private:
	int X;
	int Y;
	int Vx;
	int Vy;
	bool Got = false;
};