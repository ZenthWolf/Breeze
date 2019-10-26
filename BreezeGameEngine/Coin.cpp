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
		Pos.X = x;
		Pos.Y = y;
		Vel.X = vx;
		Vel.Y = vy;
	}
}

Coin::Coin(Vec pos, Vec vel)
{
	Pos = pos;
	Vel = vel;
}

Coin::Coin()
{
	{
		Pos.X = W;
		Pos.Y = H;
		Vel.X = 0;
		Vel.Y = 0;
	}
}

void Coin::Init(float x, float y, float vx, float vy)
{
	{
		Pos.X = x;
		Pos.Y = y;
		Vel.X = vx;
		Vel.Y = vy;

		Got = 0;
	}
}

bool Coin::CoinColl(const Coin& TCoin) const
{
	{
		Vec tpos = TCoin.PollPos();
		Vec tvel = TCoin.PollVel();

		float TLeft =tpos.X - Coin::W;
		float TRight = tpos.X + Coin::W;
		float TTop = tpos.Y - Coin::H;
		float TBot = tpos.Y + Coin::H;

		float MLeft = Pos.X - W;
		float MRight = Pos.X + W;
		float MTop = Pos.Y - H;
		float MBot = Pos.Y + H;

		return (MLeft <= TRight && MRight >= TLeft &&
			MTop <= TBot && MBot >= TTop);
	}
}

void Coin::CoinBounce(Coin& TCoin)
{
	Vec tpos = TCoin.PollPos();
	Vec tvel = TCoin.PollVel();

	float Tvx = abs(Vel.X) + abs(tvel.X);
	float Tvy = abs(Vel.Y) + abs(tvel.Y);

	if (Pos.X > tpos.X)
	{
		Vel.X = Tvx / 2;
		TCoin.SetVel(-Vel.X, tvel.Y);
	}
	else
	{
		Vel.X = -Tvx / 2;
		TCoin.SetVel(-Vel.X, tvel.Y);
	}

	if (Pos.Y > tpos.Y)
	{
		Vel.Y = Tvy / 2;
		TCoin.SetVel(tvel.X, -Vel.Y);
	}
	else
	{
		Vel.Y = -Tvy / 2;
		TCoin.SetVel(tvel.X, -Vel.Y);
	}
}

Vec Coin::PollPos() const
{
	return Pos;
}

Vec Coin::PollVel() const
{
	return Vel;
}


void Coin::SetPos(const float x, const float y)
{
	Pos.X = x;
	Pos.Y = y;
}

void Coin::SetPos(const Vec pos)
{
	Pos.X = pos.X;
	Pos.Y = pos.Y;
}

void Coin::SetVel(const float vx, const float vy)
{
	Vel.X = vx;
	Vel.Y = vy;
}

void Coin::SetVel(const Vec vel)
{
	Vel.X = vel.X;
	Vel.Y = vel.X;
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
	Pos.X += Vel.X*dt;
	Pos.Y += Vel.Y*dt;

	if (Pos.X < W)
	{
		Vel.X = -Vel.X;
		Pos.X = W;
	}
	
	else if (Pos.X >= Graphics::ScreenWidth - W)
	{
		Vel.X = -Vel.X;
		Pos.X = Graphics::ScreenWidth - W - 1;
	}

	if (Pos.Y < H)
	{
		Vel.Y = -Vel.Y;
		Pos.Y = H;
	}

	else if (Pos.Y >= Graphics::ScreenHeight - H)
	{
		Vel.Y = -Vel.Y;
		Pos.Y = Graphics::ScreenHeight - H - 1;
	}
}

void Coin::Draw( Graphics& gfx )
{
	for (int px = -5; px <= -4; px++)
	{
		for (int py = -5; py <= 5; py++)
		{
			gfx.PutPixel(int(Pos.X) + px, int(Pos.Y) + py, 203, 153, 34);
		}
	}

	for (int px = 4; px <= 5; px++)
	{
		for (int py = -5; py <= 5; py++)
		{
			gfx.PutPixel(int(Pos.X) + px, int(Pos.Y) + py, 203, 153, 34);
		}
	}

	for (int px = -3; px <= 3; px++)
	{
		for (int py = -7; py <= 7; py++)
		{
			gfx.PutPixel(int(Pos.X) + px, int(Pos.Y) + py, 255, 180, 00);
		}
	}
}