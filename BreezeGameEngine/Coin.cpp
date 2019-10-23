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

#include "Coin.h"
#include "Graphics.h"

Coin::Coin(float x, float y, float vx, float vy)
{
	{
		X = x;
		Y = y;
		Vx = vx;
		Vy = vy;
	}
}

Coin::Coin()
{
	{
		X = W;
		Y = H;
		Vx = 0;
		Vy = 0;
	}
}

void Coin::Init(float x, float y, float vx, float vy)
{
	{
		X = x;
		Y = y;
		Vx = vx;
		Vy = vy;

		Got = 0;
	}
}

void Coin::CoinColl(Coin& TCoin)
{
	{
		float TLeft = TCoin.PollX() - Coin::W;
		float TRight = TCoin.PollX() + Coin::W;
		float TTop = TCoin.PollY() - Coin::H;
		float TBot = TCoin.PollY() + Coin::H;

		float MLeft = X - W;
		float MRight = X + W;
		float MTop = Y - H;
		float MBot = Y + H;

		if (MLeft <= TRight && MRight >= TLeft &&
			MTop <= TBot && MBot >= TTop)
		{
			float Tvx = abs(Vx) + abs(TCoin.PollVx());
			float Tvy = abs(Vy) + abs(TCoin.PollVy());

			if (X > TCoin.PollX())
			{
				Vx = Tvx / 2;
				TCoin.SetVx(-Vx);
			}
			else
			{
				Vx = -Tvx / 2;
				TCoin.SetVx(-Vx);
			}

			if (Y > TCoin.PollY())
			{
				Vy = Tvy / 2;
				TCoin.SetVy(-Vy);
			}
			else
			{
				Vy = -Tvy / 2;
				TCoin.SetVy(-Vy);
			}
		}
	}
}

float Coin::PollX()
{
	return X;
}

float Coin::PollY()
{
	return Y;
}

float Coin::PollVx()
{
	return Vx;
}

float Coin::PollVy()
{
	return Vy;
}

void Coin::SetX(float x)
{
	X = x;
}

void Coin::SetY(float y)
{
	Y = y;
}

void Coin::SetVx(float vx)
{
	Vx = vx;
}

void Coin::SetVy(float vy)
{
	Vy = vy;
}

void Coin::Get()
{
	Got = !Got;
}
bool Coin::IsGot() const
{
	return Got;
}

void Coin::Update(float dt)
{
	X += Vx*dt;
	Y += Vy*dt;

	if (X < W)
	{
		Vx = -Vx;
		X = W;
	}
	
	else if (X >= Graphics::ScreenWidth - W)
	{
		Vx = -Vx;
		X = Graphics::ScreenWidth - W - 1;
	}

	if (Y < H)
	{
		Vy = -Vy;
		Y = H;
	}

	else if (Y >= Graphics::ScreenHeight - H)
	{
		Vy = -Vy;
		Y = Graphics::ScreenHeight - H - 1;
	}
}

void Coin::Draw( Graphics& gfx )
{
	for (int px = -5; px <= -4; px++)
	{
		for (int py = -5; py <= 5; py++)
		{
			gfx.PutPixel(int(X) + px, int(Y) + py, 203, 153, 34);
		}
	}

	for (int px = 4; px <= 5; px++)
	{
		for (int py = -5; py <= 5; py++)
		{
			gfx.PutPixel(int(X) + px, int(Y) + py, 203, 153, 34);
		}
	}

	for (int px = -3; px <= 3; px++)
	{
		for (int py = -7; py <= 7; py++)
		{
			gfx.PutPixel(int(X) + px, int(Y) + py, 255, 180, 00);
		}
	}
}