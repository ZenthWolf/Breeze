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
#include "Keyboard.h"
#include "Vec.h"

class Satoru
{
public:
	void Update(Keyboard& kbd, float dt);
	Vec Pos;
	Vec Vel;
	bool ROCKETMODE = false;
	static constexpr float W = 9.0f;
	static constexpr float H = 9.0f;
	void Draw(Graphics& gfx);

	float DefX = 100.0f;
	float DefY = 550.0f;

private:
	bool inhibitLeft = 0;
	bool inhibitRight = 0;
	bool inhibitUp = 0;
	bool inhibitDown = 0;
};