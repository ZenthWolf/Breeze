#pragma once

#include "Entity.h"
#include "Colors.h"

class Enemy : public Entity
{
public:
	Enemy(const Vec<float> pos, const Vec<float> vel);

	void Update(const float dt) override;
	void Draw(Graphics& gfx) const override;
	void Draw2(Graphics& gfx);
	void OnHit(Entity& attacker, int atindex);
	virtual void PushBox(Rect<float> wall) override;

	//This trash has to be handled better some other way, right?
	void fixpos(float dr);

private:
	void BounceX();
	void BounceY();

	Color col;
	float size;
	bool flash;
};