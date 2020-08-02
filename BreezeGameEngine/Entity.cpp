#include "Entity.h"


Entity::Entity(Vec<float> pos)
	:pos(pos), health(0)
{
}


Entity::Entity(Vec<float> pos, int health)
	:pos(pos), health(health)
{
}

Entity::Entity(Vec<float> pos, Vec<float> vel, int health)
	: pos(pos), vel(vel), health(health)
{
}


Vec<float> Entity::GetPos() const
{
	return pos;
}

/*
Rect<float> Entity::GetCollBox() const
{
	return collBox;
}
*/
