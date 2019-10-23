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



void Satoru::Update(Keyboard& kbd, float dt)
{

	if (kbd.KeyIsPressed(VK_UP))
	{
		if (!ROCKETMODE)
		{
			Y = Y - 2.0f * 60.0f * dt;
		}
		else if (!inhibitUp)
		{
			Vy = Vy - 30.0f;
		}
		else
		{
			inhibitUp = 0;
		}
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		if (!ROCKETMODE)
		{
			Y = Y + 2.0f * 60.0f * dt;
		}
		else if (!inhibitDown)
		{
			Vy = Vy + 30.0f;
		}
		else
		{
			inhibitDown = 0;
		}
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		if (!ROCKETMODE)
		{
			X = X - 2.0f * 60.0f * dt;
		}
		else if (!inhibitLeft)
		{
			Vx = Vx - 30.0f;
		}
		else
		{
			inhibitLeft = 0;
		}
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!ROCKETMODE)
		{
			X = X + 2.0f * 60.0f * dt;
		}
		else if (!inhibitRight)
		{
			Vx = Vx + 30.0f;
		}
		else
		{
			inhibitRight = 0;
		}
	}

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