#include "Attack.h"
#include <cassert>

Attack::Attack(const Vec<float> pos, const Vec<float> hBoxSize, const int damage, const AttackType type, const Status stat)
	:pos(pos), hitBoxSize(hBoxSize), type(type)
{
	assert(damage > 0);
	assert(damage < 16);
	assert(int(type) < 4);

	int dsig = damage;
	int tsig = int(type);

	signature |= dsig | (tsig << 4) | (stat << 6);
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

unsigned int Attack::GetSignature() const
{
	return signature;
}
