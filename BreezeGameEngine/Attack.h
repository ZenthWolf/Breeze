#pragma once

#include "Vec.h"
#include "Rect.h"
#include "Graphics.h"

class Attack
{
public:
	enum class AttackType
	{
		Blade
	};
	Attack(const Vec<float> pos, const Vec<float> hBoxSize, const AttackType type);
	void Update(float dt);
	void Draw(Graphics& gfx, Color col) const;
	void Afflict(class Entity& targ);
	Rect<float> GetCollBox() const;

private:
	Vec<float> pos;
	Vec<float> hitBoxSize;
	AttackType type;
};
