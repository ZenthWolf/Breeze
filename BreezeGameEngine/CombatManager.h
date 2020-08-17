#pragma once
#include "Attack.h"
#include "Entity.h"

struct AtkStats
{
	int damage = 0;
	int typesig = 0;
	int status = 0;
};

struct DefStats
{
	bool isVuln = true;
	int vultype = 0;
	int status = 0;
};

class CombatManager
{
public:
	void AttackOn(const Attack& attack, Entity& target);
private:
	AtkStats attackstat;
	DefStats targetstat;
	void ReadAttack(const Attack& attack);
	void ReadDefense(const Entity& target);
};