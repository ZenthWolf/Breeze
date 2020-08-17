#pragma once

#include "Vec.h"
#include "Rect.h"
#include "Graphics.h"

class Attack
{
public:
	enum class AttackType
	{
		UNDEF,
		Melee,
		Ranged,
		Magic,
		LAST
	};
	enum Status
	{
		none = 0b0,
		stun = 0b1,
		frze = 0b10,
		burn = 0b100,
		mpow = 0b1000
	};
	Attack(const Vec<float> pos, const Vec<float> hBoxSize, const int damage, const AttackType type, const Status stat = Status::none);
	Attack()
	{
		pos = { 0,0 };
		hitBoxSize = { 0,0 };
		type = AttackType::UNDEF;
	}

	void Update(float dt);
	void Draw(Graphics& gfx, Color col) const;
	void Afflict(class Entity& targ);
	Rect<float> GetCollBox() const;
	unsigned int GetSignature() const;

	const unsigned short int damagemask = 0b1111;
	const unsigned short int damshift = 0;
	const unsigned short int typemask = 0b110000;
	const unsigned short int typeshift = 4;
	const unsigned short int statmask = 0b1111000000;
	const unsigned short int statshift = 6;

private:
	Vec<float> pos;
	Vec<float> hitBoxSize;
	AttackType type;
	unsigned short int signature = 0; // 2 Byte
};
