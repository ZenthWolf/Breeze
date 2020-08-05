#include "Attack.h"

Attack::Attack(const Vec<float> pos, const Vec<float> hBoxSize, const Entity::AttackType type, Entity& source)
	:pos(pos), hitBoxSize(hBoxSize), type(type), source(source)
{
	allegiance = source.GetAllegiance();
}