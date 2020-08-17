#include "Character.h"

Character::Character(const Vec<float>& pos, Keyboard& kbd)
	:Entity(pos, Allegiance::Ava), sprite("Images//link90x90.bmp"), kbd(kbd)
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
	if (!kbd.KeyIsPressed(VK_CONTROL))
	{
		animation[(int)curSeq].Draw(Vec<int>(pos), gfx);

		for (int i = 0; i < attack.size(); i++)
		{
			attack[i]->Draw(gfx, Colors::Red);
		}
	}
	else
	{
		gfx.DrawRect(GetCollBox(), Colors::White);
		Draw(gfx, Colors::Red);
	}
}

void Character::Draw(Graphics& gfx, Color sub) const
{
	animation[(int)curSeq].Draw(Vec<int>(pos), gfx, sub);

	for (int i = 0; i < attack.size(); i++)
	{
		attack[i]->Draw(gfx, Colors::Red);
	}
}

void Character::SetDir(const Vec<float>& dir)
{
	if (curAct == Action::Move)
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
}

void Character::MakeAttack()
{
	if (curAct != Action::Attack)
	{
		swingstate = true;
		curAct = Action::Attack;

		Rect<float> edge = GetCollBox();
		Vec<float> cent = { 0.0f, 0.0f };
		Vec<float> half = { 0.0f, 0.0f };

		if (curSeq == Sequence::StandingRight || curSeq == Sequence::WalkingRight)
		{
			curSeq = Sequence::StandingRight;

			half = { 25.0f, 5.0f };
			cent = { edge.X1 + half.X, (edge.Y0 + edge.Y1) / 2 };
		}

		else if (curSeq == Sequence::StandingLeft || curSeq == Sequence::WalkingLeft)
		{
			curSeq = Sequence::StandingLeft;

			half = { 25.0f, 5.0f };
			cent = { edge.X0 - half.X, (edge.Y0 + edge.Y1) / 2 };
		}

		else if (curSeq == Sequence::StandingUp || curSeq == Sequence::WalkingUp)
		{
			curSeq = Sequence::StandingUp;

			half = { 5.0f, 25.0f };
			cent = { (edge.X0 + edge.X1) / 2, edge.Y0 - half.Y };
		}

		else if (curSeq == Sequence::StandingDown || curSeq == Sequence::WalkingDown)
		{
			curSeq = Sequence::StandingDown;

			half = { 5.0f, 25.0f };
			cent = { (edge.X0 + edge.X1) / 2, edge.Y1 + half.Y };
		}

		else
		{
			cent = { 35.0f, 15.0f };
			half = { 25.0f, 5.0f };
		}

		attack.push_back(
			std::make_unique<Attack>(cent - half, cent + half, 2, Attack::AttackType::Melee)
		);

		swingcool = 0.0f;
	}
}

void Character::SetVel()
{
	Vec<float> dir = { 0.0f, 0.0f };
	if (kbd.KeyIsPressed(VK_UP))
	{
		dir.Y -= 1.0f;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		dir.Y += 1.0f;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		dir.X -= 1.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		dir.X += 1.0f;
	}


	SetDir(dir);
}

bool Character::GetSwing() const
{
	return swingstate;
}

void Character::Update(float const dt)
{
	SetVel();

	if (curAct == Action::Move)
	{
		pos += vel * dt;
	}

	for (int i = 0; i < attack.size(); i++)
	{
		attack[i]->Update(dt);
	}

	if (swingstate)
	{
		swingcool += dt;
		if (swingcool >= 0.25f)
		{
			swingstate = false;
			curAct = Action::Move;
			attack.erase(attack.begin(), attack.begin()+1);
		}
	}

	animation[(int)curSeq].Update(dt);
}

void Character::Input(Keyboard::Event e)
{
	if (e.IsPress() && e.GetCode() == ' ')
	{
		MakeAttack();
	}
}



Rect<float> Character::GetCollBox() const
{
	Vec<float> v0 = pos + Vec<float>(25.0f, 20.0f);
	Vec<float> v1 = pos + Vec<float>(65.0f, 70.0f);
	return Rect<float>( v0, v1 );
}

Rect<float> Character::GetAttackBox(int atindex) const
{
	if (atindex < attack.size())
	{
		return attack[atindex]->GetCollBox();
	}
	else
	{
		return Rect<float>(0.0f, 0.0f, 0.0f, 0.0f);
	}
}
