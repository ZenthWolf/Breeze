#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(float x, float y, Color c)
{
	Pos = { x, y };
	C = c;
}

Ball::Ball(float x, float y, float v, Color c)
{
	Pos = { x, y };
	speed = v;
	SetDir({ -1.0f, -1.0f });
	C = c;
}

Ball::Ball(float x, float y, float v, Vec initDir, Color c)
{
	Pos = { x, y };
	speed = v;
	SetDir(initDir);
	C = c;
}

Ball::Ball(Vec pos, float v, Vec initDir, Color c)
{
	Pos = pos;
	speed = v;
	SetDir(initDir);
	C = c;
}

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawCirc(int(Pos.X), int(Pos.Y), int(R), C);
}

void Ball::Move(float dt)
{
	Pos += Vel * dt * 60.0f;
}

bool Ball::CollWall(const RectF& wall)
{
	RectF Rect = GetRect();

	bool hit = false;
	if (Rect.X0 < wall.X0)
	{
		Pos.X += wall.X0 - Rect.X0;
		BounceX();
		hit = true;
	}
	else if (Rect.X1 > wall.X1)
	{
		Pos.X += wall.X1 - Rect.X1;
		BounceX();
		hit = true;
	}
	if (Rect.Y0 < wall.Y0)
	{
		Pos.Y += wall.Y0 - Rect.Y0;
		BounceY();
		hit = true;
	}
	else if (Rect.Y1 > wall.Y1)
	{
		Pos.Y += wall.Y1 - Rect.Y1;
		BounceY();
		hit = true;
	}
	return hit;
}

void Ball::BounceX()
{
	Vel.X = -Vel.X;
}

void Ball::BounceY()
{
	Vel.Y = -Vel.Y;
}

void Ball::BounceY(const Vec off)
{
	SetDir(off);
}

void Ball::MoveX(const float dx)
{
	Pos.X += dx;
}

Vec Ball::GetPos() const
{
	return Pos;
}

Vec Ball::GetVel() const
{
	return Vel;
}

void Ball::SetHeldPos(const Vec& padPos, const float padHeight)
{
	Pos = padPos + Vec{ 0, -R - padHeight };
}

void Ball::SetDir(const Vec Dir)
{
	Vel = Dir.Norm() * speed;
}

float Ball::GetRad() const
{
	return R;
}

int Ball::SayState() const
{
	return ballState;
}

void Ball::HeldUpdate(Keyboard& kbd)
{
	if ( (kbd.KeyIsPressed(VK_LEFT) && Vel.X > 0.0f) || (kbd.KeyIsPressed(VK_RIGHT) && Vel.X < 0.0f) )
	{
		BounceX();
	}

	if (kbd.KeyIsPressed(VK_SPACE))
	{
		ballState = 1;
	}
}

RectF Ball::GetRect() const
{
	return RectF::FromCent(Pos, R, R);;
}
