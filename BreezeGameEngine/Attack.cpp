#include "Attack.h"

Attack::Attack(const Vec<float> pos, const Vec<float> hBoxSize)
	:pos(pos), hitBoxSize(hBoxSize)
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
