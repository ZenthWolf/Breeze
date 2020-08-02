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
	void Update(float const dt);
	Vec<float> GetPos() const;
	Rect<float> GetCollBox() const;
	void Draw(Graphics& gfx) const;

protected:
	Entity(Vec<float> pos);
	Entity(Vec<float> pos, int health);
	Entity(Vec<float> pos, Vec<float> vel, int health);

	int health;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	//Rect<float> collBox;
};
