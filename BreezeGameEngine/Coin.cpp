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

Coin::Coin(int x, int y, int vx, int vy)
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

void Coin::Init(int x, int y, int vx, int vy)
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
		int TLeft = TCoin.PollX() - Coin::W;
		int TRight = TCoin.PollX() + Coin::W;
		int TTop = TCoin.PollY() - Coin::H;
		int TBot = TCoin.PollY() + Coin::H;

		int MLeft = X - W;
		int MRight = X + W;
		int MTop = Y - H;
		int MBot = Y + H;

		if (MLeft <= TRight && MRight >= TLeft &&
			MTop <= TBot && MBot >= TTop)
		{
			int Tvx = abs(Vx) + abs(TCoin.PollVx());
			int Tvy = abs(Vy) + abs(TCoin.PollVy());

			if (X > TCoin.PollX())
			{
				Vx = Tvx / 2;
				TCoin.SetVx(-Vx);

				if (Tvx % 2 == 1)
				{
					Vx++;
				};
			}
			else
			{
				Vx = -Tvx / 2;
				TCoin.SetVx(-Vx);

				if (Tvx % 2 == 1)
				{
					TCoin.SetVx(-Vx+1);
				}
			}

			if (Y > TCoin.PollY())
			{
				Vy = Tvy / 2;
				TCoin.SetVy(-Vy);

				if (Tvy % 2 == 1)
				{
					Vy++;
				}
			}
			else
			{
				Vy = -Tvy / 2;
				TCoin.SetVy(-Vy);

				if (Tvy % 2 == 1)
				{
					TCoin.SetVy(-Vy+1);
				}
			}
		}
	}
}

int Coin::PollX()
{
	return X;
}

int Coin::PollY()
{
	return Y;
}

int Coin::PollVx()
{
	return Vx;
}

int Coin::PollVy()
{
	return Vy;
}

void Coin::SetX(int x)
{
	X = x;
}

void Coin::SetY(int y)
{
	Y = y;
}

void Coin::SetVx(int vx)
{
	Vx = vx;
}

void Coin::SetVy(int vy)
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

void Coin::Update()
{
	X += Vx;
	Y += Vy;

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
			gfx.PutPixel(X + px, Y + py, 203, 153, 34);
		}
	}

	for (int px = 4; px <= 5; px++)
	{
		for (int py = -5; py <= 5; py++)
		{
			gfx.PutPixel(X + px, Y + py, 203, 153, 34);
		}
	}

	for (int px = -3; px <= 3; px++)
	{
		for (int py = -7; py <= 7; py++)
		{
			gfx.PutPixel(X + px, Y + py, 255, 180, 00);
		}
	}
}