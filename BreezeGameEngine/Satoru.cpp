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

void Satoru::Draw(Graphics& gfx)
{
	//Hair
	int py = -9;
	for (int px = -7; px <= 7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}

	py = -8;
	for (int px = -9; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}

	py = -7;
	for (int px = -9; px <= -2; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}
	for (int px = 2; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}
	py = -6;
	for (int px = -9; px <= -2; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}
	for (int px = 4; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}

	py = -5;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}
	for (int px = 8; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}

	py = -4;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}
	for (int px = 8; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 94, 44, 44);
	}

	//Eye White
	py = -3;
	for (int px = -5; px <= -3; px++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}
	for (int px = 3; px <= 5; px++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	py = 1;
	for (int px = -5; px <= -3; px++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}
	for (int px = 3; px <= 5; px++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	int px = -5;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	px = -3;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	px = 3;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	px = 5;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(X + px, Y + py, 255, 255, 255);
	}

	//skin
	py = -7;
	for (int px = -1; px <= 1; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	py = -6;
	for (int px = -1; px <= 4; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	py = -5;
	for (int px = -6; px <= 7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	py = -4;
	for (int px = 6; px <= 7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	for (int px = -2; px <= 2; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	gfx.PutPixel(X - 6, Y + py, 209, 169, 109);

	py = -3;
	for (int px = -8; px <= -7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	for (int px = 7; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	gfx.PutPixel(X + 1, Y + py, 209, 169, 109);
	gfx.PutPixel(X - 1, Y + py, 209, 169, 109);

	py = -2;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	gfx.PutPixel(X, Y + py, 209, 169, 109);

	py = 9;
	for (int px = -7; px <= 7; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	py = 8;
	for (int px = -8; px <= 8; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	py = 7;
	for (int px = -9; px <= -3; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
	for (int px = 3; px <= 9; px++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -9;
	for (int py = -1; py <= 7; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -8;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -7;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -6;
	for (int py = 2; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -5;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -4;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -3;
	for (int py = 3; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -2;
	for (int py = 2; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = -1;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 0;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 1;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 2;
	for (int py = 2; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 3;
	for (int py = 3; py <= 5; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 4;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 5;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 6;
	for (int py = 2; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 7;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 8;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}

	px = 9;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(X + px, Y + py, 209, 169, 109);
	}
}
