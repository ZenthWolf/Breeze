#include "CombatManager.h"

void CombatManager::AttackOn(const Attack& attack, Entity& target)
{
	ReadAttack(attack);
	ReadDefense(target);

	unsigned short int rebound = 0;

	if (targetstat.isVuln && targetstat.vultype & attackstat.typesig)
	{
		rebound = target.TakeDamage(attackstat.damage);

		if (attackstat.status & targetstat.status)
		{
			if(attackstat.status & Attack::Status::stun)
			target.Stun();
		}


		if (!rebound)
		{
			//Do Rebound attack
			//Not implemented until there is a scheme that can never result in infinite rebounds
		}
	}
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

	targetstat.vultype = (defsig & target.typemask) >> target.typeshift;
	targetstat.status = (defsig & target.statmask) >> target.statshift;
	targetstat.isVuln = target.IsVulnerable();
}
