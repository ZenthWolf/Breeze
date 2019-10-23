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

class Satoru
{
public:
	void Update();
	int X;
	int Y;
	int Vx;
	int Vy;
	bool ROCKETMODE = false;
	static constexpr int W = 9;
	static constexpr int H = 9;
	bool CoinGot = false;

	int DefX = 100;
	int DefY = 550;
};