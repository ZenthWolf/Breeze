#include "CombatManager.h"

void CombatManager::AttackOn(Attack& attack, Entity& target)
{
	auto atksig = attack.GetSignature();
	auto defsig = target.GetDefSignature();

	auto atktype = (atksig & attack.typemask) >> attack.typeshift;
	auto defvuln = (defsig & target.typemask) >> target.typeshift;

	unsigned short int rebound = 0;

	if (defvuln & (0b1 >> atktype))
	{
		rebound = target.TakeDamage((atksig & attack.damagemask) >> attack.damshift);

		auto statsig = (atksig & attack.statmask) >> attack.statshift;
		auto defstat = (defvuln & target.statmask) >> target.statshift;

		if (statsig & Attack::Status::stun && 
			defstat & Attack::Status::stun)
		{
			target.Stun();
		}
	}

	if (!rebound)
	{
		//Do Rebound attack
		//Not implemented until there is a scheme that can never result in infinite rebounds
	}
}
