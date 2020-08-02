#pragma once

#include "Vec.h"
#include "Graphics.h"

class Entity
{
private:
	enum class AttackType
	{
		Blade
	};

public:
	virtual void Update(float const dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;

	Vec<float> GetPos() const;
	Rect<float> GetCollBox() const;

protected:
	virtual ~Entity() = default;

	Entity(Vec<float> pos);
	Entity(Vec<float> pos, int health);
	Entity(Vec<float> pos, Vec<float> vel, int health);
	int health;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
};
