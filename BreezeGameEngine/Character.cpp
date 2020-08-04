#include "Character.h"

Character::Character(const Vec<float>& pos)
	:Entity(pos, Allegiance::Ava), sprite("Images//link90x90.bmp")
{
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animation.emplace_back(90, 90*i, 90, 90, 4, sprite, 0.16f);
	}

	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		animation.emplace_back(90, 90 * (i-int(Sequence::StandingLeft)), 90, 90, 1, sprite, 0.16f);
	}
}

void Character::Draw(Graphics& gfx) const
{
	animation[(int)curSeq].Draw( Vec<int>(pos), gfx );
}

void Character::Draw(Graphics& gfx, Color sub) const
{
	animation[(int)curSeq].Draw(Vec<int>(pos), gfx, sub);
}

void Character::SetDir(const Vec<float>& dir)
{
	if (dir.X > 0.0f)
	{
		curSeq = Sequence::WalkingRight;
	}
	else if (dir.X < 0.0f)
	{
		curSeq = Sequence::WalkingLeft;
	}
	else if (dir.Y > 0.0f)
	{
		curSeq = Sequence::WalkingDown;
	}
	else if (dir.Y < 0.0f)
	{
		curSeq = Sequence::WalkingUp;
	}
	else
	{
		if (vel.X > 0.0f)
		{
			curSeq = Sequence::StandingRight;
		}
		else if (vel.X < 0.0f)
		{
			curSeq = Sequence::StandingLeft;
		}
		else if (vel.Y > 0.0f)
		{
			curSeq = Sequence::StandingDown;
		}
		else if (vel.Y < 0.0f)
		{
			curSeq = Sequence::StandingUp;
		}
	}
	vel = dir * speed;
}

void Character::Attack()
{
	swingstate = true;
	swingcool = 0.0f;
}

bool Character::GetSwing() const
{
	return swingstate;
}

void Character::Update(float const dt)
{
	pos += vel * dt;

	if (swingstate)
	{
		swingcool += dt;
		if (swingcool >= 0.5f)
		{
			swingstate = false;
		}
	}

	animation[(int)curSeq].Update(dt);
}



Rect<float> Character::GetCollBox() const
{
	return Rect<float>( pos + Vec<float>(25.0f, 20.0f), pos + Vec<float>(65.0f, 70.0f) );
}

Rect<float> Character::GetSwingBox() const
{
	Rect<float> edge = GetCollBox();

	if (curSeq == Sequence::StandingRight)
	{
		Vec<float> half = { 25.0f, 5.0f };
		Vec<float> cent = { edge.X1 + half.X, (edge.Y0 + edge.Y1)/2 };
		return Rect<float>(cent - half, cent + half);
	}

	else if (curSeq == Sequence::StandingLeft)
	{
		Vec<float> half = { 25.0f, 5.0f };
		Vec<float> cent = { edge.X0 - half.X, (edge.Y0 + edge.Y1) / 2 };
		return Rect<float>(cent - half, cent + half);
	}

	else if (curSeq == Sequence::StandingUp)
	{
		Vec<float> half = { 5.0f, 25.0f };
		Vec<float> cent = { (edge.X0 + edge.X1) / 2, edge.Y0 - half.Y };
		return Rect<float>(cent - half, cent + half);
	}

	else if (curSeq == Sequence::StandingDown)
	{
		Vec<float> half = { 5.0f, 25.0f };
		Vec<float> cent = { (edge.X0 + edge.X1) / 2, edge.Y1 + half.Y };
		return Rect<float>(cent - half, cent + half);
	}

	else
	{
		return Rect<float> {10.0f, 10.0f, 60.0f, 20.0f };
	}
}