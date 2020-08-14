#include "Attack.h"

Attack::Attack(const Vec<float> pos, const Vec<float> hBoxSize, const AttackType type)
	:pos(pos), hitBoxSize(hBoxSize), type(type)
{
}

void Attack::Update(float dt)
{
}

void Attack::Draw(Graphics& gfx, Color col) const
{
	gfx.DrawRect(GetCollBox(), col);
}

Rect<float> Attack::GetCollBox() const
{
	return Rect<float>(pos, hitBoxSize);
}
