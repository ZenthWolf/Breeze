#include "CombatManager.h"

void CombatManager::AttackOn(const Attack& attack, Entity& target)
{
	auto atksig = attack.GetSignature();
	auto defsig = target.GetDefSignature();

	auto atktype = (atksig & attack.typemask) >> attack.typeshift;
	auto defvuln = (defsig & target.typemask) >> target.typeshift;

	unsigned short int rebound = 0;

	if (target.IsVulnerable() && defvuln & (0b1 << atktype))
	{
		rebound = target.TakeDamage((atksig & attack.damagemask) >> attack.damshift);

		auto statsig = (atksig & attack.statmask) >> attack.statshift;
		auto defstat = (defsig & target.statmask) >> target.statshift;

		if (statsig & Attack::Status::stun &&
			defstat & Attack::Status::stun)
		{
			target.Stun();
		}


		if (!rebound)
		{
			//Do Rebound attack
			//Not implemented until there is a scheme that can never result in infinite rebounds
		}
	}

	ReadAttack(attack);
	ReadDefense(target);
	bool truth = true;
}

void CombatManager::ReadAttack(const Attack& attack)
{
	auto atksig = attack.GetSignature();

	attackstat.damage = (atksig & attack.damagemask) >> attack.damshift;
	int type = 0;

	auto atktype = (atksig & attack.typemask) >> attack.typeshift;

	for (int atype = int(Attack::AttackType::UNDEF); atype != int(Attack::AttackType::LAST); atype++)
	{
		if (atype == atktype)
		{
			attackstat.typesig = 0b1 << atype;
			break;
		}
	}

	attackstat.status = (atksig & attack.statmask) >> attack.statshift;
}

void CombatManager::ReadDefense(const Entity& target)
{
	auto defsig = target.GetDefSignature();

	targetstat.vulsig = (defsig & target.typemask) >> target.typeshift;
	targetstat.status = (defsig & target.statmask) >> target.statshift;
	targetstat.isVuln = target.IsVulnerable();
}
