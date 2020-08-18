#pragma once

#include "Vec.h"
#include "Rect.h"
#include "Graphics.h"

#include "Character.h"
#include "Enemy.h"

class Attack
{
public:
	//VConcrete Elements to be VisitedV
	virtual void Afflict(Character& targ) = 0;
	virtual void Afflict(Enemy& targ) = 0;
	//^Concrete Elements to be Visited^

	Attack(const Vec<float> pos, const Vec<float> hBoxSize);
	Attack()
	{
		pos = { 0,0 };
		hitBoxSize = { 0,0 };
	}

	void Update(float dt);
	void Draw(Graphics& gfx, Color col) const;
	Rect<float> GetCollBox() const;

private:
	Vec<float> pos;
	Vec<float> hitBoxSize;
};

class SwordStrike : public Attack
{
public:
	SwordStrike(const Vec<float> pos, const Vec<float> hBoxSize)
		:Attack(pos, hBoxSize)
	{}

	void Afflict(Character& targ)
	{
		targ.TakeDamage(2);
	}
	void Afflict(Enemy& targ)
	{
		targ.TakeDamage(2);
	}
};

class SwordStun : public Attack
{
public:
	SwordStun(const Vec<float> pos, const Vec<float> hBoxSize)
		:Attack(pos, hBoxSize)
	{}

	void Afflict(Character& targ)
	{
		targ.TakeDamage(1);
		targ.Stun();
	}
	void Afflict(Enemy& targ)
	{
		targ.TakeDamage(1);
		targ.Stun()
	}
};