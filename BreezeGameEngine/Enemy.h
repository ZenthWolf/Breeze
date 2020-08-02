#pragma once

#include "Entity.h"
#include "Colors.h"

class Enemy : Entity
{
public:
	Enemy(const Vec<float> pos, const Vec<float> vel);
	void Update(const float dt);
	void Draw(Graphics& gfx) const;
private:
	void BounceX();
	void BounceY();

	Color col;
	float size;
};