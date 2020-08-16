#pragma once

#include "Vec.h"
#include "Rect.h"
#include "Graphics.h"

class Attack
{
public:
	enum class AttackType
	{
		Melee,
		Ranged,
		Magic,
		UNDEF = -1
	};
	Attack(const Vec<float> pos, const Vec<float> hBoxSize, const AttackType type);
	Attack()
	{
		pos = { 0,0 };
		hitBoxSize = { 0,0 };
		type = AttackType::UNDEF;
	}

	void Update(float dt);
	void Draw(Graphics& gfx, Color col) const;
	void Afflict(class Entity& targ);
	Rect<float> GetCollBox() const;

private:
	Vec<float> pos;
	Vec<float> hitBoxSize;
	AttackType type;
};
