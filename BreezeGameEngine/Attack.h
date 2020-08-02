#pragma once
//Playground to identify needed interactions
//Eventual baseline for "Room" class, but don't take this shit seriously.

#include "Character.h"

class Attack
{
private:
	Attack();
	~Attack();
	void Update(float dt);
	void Afflict(Character& targ);
	Rect<float> GetCollBox();

private:
	Character& source; //Reference to the source which created this attack - More evidence for Ava/NME sharing a parent class?
	Vec<float> pos;
	Rect<float> hitBox;
	float strength;
};