#include "Enemy.h"

Enemy::Enemy(const Vec<float> pos, const Vec<float> vel)
	:pos(pos), vel(vel), health(3), col(Colors::Cyan), size(15)
{
}

void Enemy::Update(const float dt)
{
	pos += vel*dt;

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

void Enemy::Draw(Graphics& gfx) const
{
	gfx.DrawCirc(pos, size, col);
}

void Enemy::BounceX()
{
	vel.X = -vel.X;
}

void Enemy::BounceY()
{
	vel.Y = -vel.Y;
}
