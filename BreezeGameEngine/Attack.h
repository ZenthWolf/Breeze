#pragma once
//Playground to identify needed interactions
//Eventual baseline for "Room" class, but don't take this shit seriously.

#include "Entity.h"

class Attack
{
	Attack(const Vec<float> pos, const Vec<float> hBoxSize, const Entity::AttackType type, Entity& source);
	void Update(float dt);
	void Afflict(Entity& targ);
	Rect<float> GetCollBox();

private:
	Entity& source; //Reference to the source which created this attack - More evidence for Ava/NME sharing a parent class?
	Vec<float> pos;
	Vec<float> hitBoxSize;
	Entity::AttackType type;
	Entity::Allegiance allegiance;
};
