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
	virtual void Update(float const dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;
	virtual void OnHit(Entity& attacker, int atindex) = 0;

	Vec<float> GetPos() const;
	virtual void PushBox(Rect<float> wall);
	Allegiance GetAllegiance() const;
	virtual Rect<float> GetCollBox() const;
	int GetAttackNum() const;
	

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
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
	std::vector<std::unique_ptr<Attack>> attack;
};
