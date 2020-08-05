#pragma once

#include "Vec.h"
#include "Graphics.h"

class Entity
{
public:
	enum class AttackType
	{
		Blade
	};

	enum class Allegiance
	{
		Ava,
		Enemy,
		None
	};
	virtual void Update(float const dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;

	Vec<float> GetPos() const;
	void PushBox(Rect<float> wall);
	Allegiance GetAllegiance() const;
	Rect<float> GetCollBox() const;

protected:
	virtual ~Entity() = default;

	Entity(Vec<float> pos, Allegiance allegiance );
	Entity(Vec<float> pos, int health);
	Entity(Vec<float> pos, Vec<float> vel, int health, Allegiance allegiance);

	Allegiance allegiance = Allegiance::None;
	int health;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
};
