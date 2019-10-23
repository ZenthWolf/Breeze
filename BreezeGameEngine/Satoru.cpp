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

#include "Satoru.h"
#include "Graphics.h"


void Satoru::Update(float dt)
{
	if (ROCKETMODE)
	{
		X = X + Vx * dt;
		Y = Y + Vy * dt;
	}
	if (X < W)
	{
		Vx = -Vx/2;
		X = W;
	}

	else if (X >= Graphics::ScreenWidth - W)
	{
		Vx = -Vx/2;
		X = Graphics::ScreenWidth - W - 1;
	}

	if (Y < H)
	{
		Vy = -Vy/2;
		Y = H;
	}

	else if (Y >= Graphics::ScreenHeight - H)
	{
		Vy = -Vy/2;
		Y = Graphics::ScreenHeight - H - 1;
	}
}