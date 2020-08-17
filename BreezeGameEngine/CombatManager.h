#pragma once
#include "Attack.h"
#include "Entity.h"

class CombatManager
{
public:
	void AttackOn(const Attack& attack, Entity& target);
private:
};