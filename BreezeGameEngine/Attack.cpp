#include "Entity.h"

Entity::Attack::Attack(const Vec<float> pos, const Vec<float> hBoxSize, const Entity::AttackType type)
	:pos(pos), hitBoxSize(hBoxSize), type(type)
{
}

void Entity::Attack::Update(float dt)
{
}

void Entity::Attack::Draw(Graphics& gfx, Color col) const
{
	gfx.DrawRect(GetCollBox(), col);
}

Rect<float> Entity::Attack::GetCollBox() const
{
	return Rect<float>(pos, hitBoxSize);
}
