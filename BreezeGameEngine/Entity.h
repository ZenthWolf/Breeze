#pragma once

#include "Vec.h"
#include "Graphics.h"
#include "Attack.h"
#include<vector>
#include<memory>

class Entity
{
public:
	enum class Allegiance
	{
		Ava,
		Enemy,
		None
	};
	enum DefType
	{
		UNDEF  = 0b1,
		Melee  = 0b10,
		Ranged = 0b100,
		Magic  = 0b1000
	};

	virtual void Update(float const dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;
	virtual void OnHit(Entity& attacker, int atindex) = 0;

	/* VCOMBAT MANAGERV */
	unsigned short int TakeDamage(int damage);
	void Stun();
	void StatusUpdate(float dt);
	const Attack& GetAttack(int atindex);
	/* ^COMBAT MANAGER^ */

	Vec<float> GetPos() const;
	virtual void PushBox(Rect<float> wall);
	Allegiance GetAllegiance() const;
	virtual Rect<float> GetCollBox() const;
	int GetAttackNum() const;
	unsigned short int GetDefSignature() const;
	bool IsVulnerable() const;

	const unsigned short int typemask = 0b1111;
	const unsigned short int typeshift = 0;
	const unsigned short int statmask = 0b11110000;
	const unsigned short int statshift = 4;
	

protected:
	virtual ~Entity() = default;

	Entity(Vec<float> pos, Allegiance allegiance );
	Entity(Vec<float> pos, int health);
	Entity(Vec<float> pos, Vec<float> vel, int health, Allegiance allegiance);
	void VulnerableTimer(float dt);

	Allegiance allegiance = Allegiance::None;
	int health;
	bool vulnerable = true;
	float invultime = 0.0f;
	bool stun = false;
	float stuntime = 0.0f;
	unsigned short int defsignature = 0b11111110;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
	std::vector<std::unique_ptr<Attack>> attack;
};
