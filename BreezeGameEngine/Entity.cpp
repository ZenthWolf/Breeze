#include "Entity.h"


Entity::Entity(Vec<float> pos, Allegiance allegiance = Allegiance::None)
	:pos(pos), health(0), allegiance(allegiance)
{
}


Entity::Entity(Vec<float> pos, int health)
	:pos(pos), health(health)
{
}

Entity::Entity(Vec<float> pos, Vec<float> vel, int health, Allegiance allegiance = Allegiance::None)
	: pos(pos), vel(vel), health(health), allegiance(allegiance)
{
}


Vec<float> Entity::GetPos() const
{
	return pos;
}

Entity::Allegiance Entity::GetAllegiance() const
{
	return allegiance;
}


Rect<float> Entity::GetCollBox() const
{
	return Rect<float>(pos, pos+collBoxSize);
}

