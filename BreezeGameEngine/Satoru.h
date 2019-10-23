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
	void Update(float dt);
	float X;
	float Y;
	float Vx;
	float Vy;
	bool ROCKETMODE = false;
	static constexpr float W = 9.0f;
	static constexpr float H = 9.0f;

	float DefX = 100.0f;
	float DefY = 550.0f;
};