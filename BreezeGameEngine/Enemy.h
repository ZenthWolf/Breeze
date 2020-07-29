#pragma once

#include "Vec.h"
#include "Colors.h"
#include "Graphics.h"

class Enemy
{
public:
	Enemy(const Vec<float> pos, const Vec<float> vel);
	void Update(const float dt);
	void Draw(Graphics& gfx) const;
private:
	void BounceX();
	void BounceY();

	int health;
	Vec<float> pos;
	Vec<float> vel;
	Color col;
	float size;
};