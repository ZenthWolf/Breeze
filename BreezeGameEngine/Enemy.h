#pragma once

#include "Entity.h"
#include "Colors.h"

class Enemy : public Entity
{
public:
	Enemy(const Vec<float> pos, const Vec<float> vel);
	void Update(const float dt) override;
	void Draw(Graphics& gfx) const override;
private:
	void BounceX();
	void BounceY();

	Color col;
	float size;
};