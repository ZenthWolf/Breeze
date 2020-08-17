#include "Enemy.h"

Enemy::Enemy(const Vec<float> pos, const Vec<float> vel)
	:Entity(pos, vel, 3, Allegiance::Enemy), col(Colors::Cyan), size(15)
{
	fixpos(float(size));
	collBoxSize = { size*2 -1 , size*2 -1 };
	size -= 1;
}

void Enemy::fixpos(float dr)
{
	pos = pos - Vec<float>(dr, dr);
}

void Enemy::Update(const float dt)
{
	VulnerableTimer(dt);
	StatusUpdate(dt);

	if (!stun)
	{
		pos += vel * dt;

		if (pos.Y - size <= 0.0f)
		{
			pos.Y = size;
			BounceY();
		}

		else if (pos.Y + size >= 600.0f)
		{
			pos.Y = 600.0f - size;
			BounceY();
		}

		else if (pos.X - size <= 0.0f)
		{
			pos.X = size;
			BounceX();
		}

		else if (pos.X + size >= 800.0f - size)
		{
			pos.Y = 800.0f;
			BounceX();
		}
	}
}

void Enemy::Draw(Graphics& gfx) const
{
	if (health > 0)
	{
		gfx.DrawCirc(pos + Vec<float>(float(size), float(size)), size + 1, col);
		for (int i = 3; i < 9; i++)
		{
			gfx.PutPixel(pos.X + i + size, pos.Y + size - i + 1, Colors::Black);
			gfx.PutPixel(pos.X - i + size, pos.Y + size - i + 1, Colors::Black);
		}
	}
}

void Enemy::Draw2(Graphics& gfx)
{
	if (health > 0)
	{
		if (vulnerable)
		{
			gfx.DrawCirc(pos + Vec<float>(float(size), float(size)), size + 1, col);
		}
		else
		{
			if (!flash)
			{
				gfx.DrawCirc(pos + Vec<float>(float(size), float(size)), size + 1, col);
			}
			else
			{
				gfx.DrawCirc(pos + Vec<float>(float(size), float(size)), size + 1, Colors::Red);
			}

			flash = !flash;
		}
		for (int i = 3; i < 9; i++)
		{
			gfx.PutPixel(pos.X + i + size, pos.Y + size - i + 1, Colors::Black);
			gfx.PutPixel(pos.X - i + size, pos.Y + size - i + 1, Colors::Black);
		}
	}
}

void Enemy::OnHit(Entity& attacker, int atindex)
{
	if (attacker.GetAllegiance() != Allegiance::Enemy && vulnerable)
	{
		health -= 1;
		vulnerable = false;
		invultime = -0.5f;
		flash = true;
	}
}

void Enemy::PushBox(Rect<float> wall)
{
	float Deviance[4] = { 0.0f }; //0-4 Left, Up, Right, Down
	float MinDev = 0.0f;

	Rect<float> entcoll = GetCollBox();

	float UpDeviance = entcoll.Y1 - wall.Y0;
	if (UpDeviance > 0.0f)
	{
		MinDev = UpDeviance;
	}
	float LeftDeviance = entcoll.X1 - wall.X0;
	if (LeftDeviance > 0.0f)
	{
		if (MinDev == 0.0f || LeftDeviance < MinDev)
		{
			MinDev = LeftDeviance;
		}
	}
	float DownDeviance = wall.Y1 - entcoll.Y0;
	if (DownDeviance > 0.0f)
	{
		if (MinDev == 0.0f || DownDeviance < MinDev)
		{
			MinDev = DownDeviance;
		}
	}
	float RightDeviance = wall.X1 - entcoll.X0;
	if (RightDeviance > 0.0f)
	{
		if (MinDev == 0.0f || RightDeviance < MinDev)
		{
			MinDev = RightDeviance;
		}
	}

	if (MinDev == UpDeviance)
	{
		pos.Y = round(pos.Y - UpDeviance);
		BounceY();
	}
	else if (MinDev == LeftDeviance)
	{
		pos.X = round(pos.X - LeftDeviance);
		BounceX();
	}
	else if (MinDev == DownDeviance)
	{
		pos.Y = round(pos.Y + DownDeviance);
		BounceY();
	}
	else if (MinDev == RightDeviance)
	{
		pos.X = round(pos.X + RightDeviance);
		BounceX();
	}
	else
	{
		//There probably should be an error or something here...
	}
}

void Enemy::BounceX()
{
	vel.X = -vel.X;
}

void Enemy::BounceY()
{
	vel.Y = -vel.Y;
}
