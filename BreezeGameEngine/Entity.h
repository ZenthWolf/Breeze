#pragma once

#include "Vec.h"
#include "Graphics.h"
#include<vector>
#include<memory>

class Entity
{
public:
	//VAccept Visitors and Break EncapsulationV
	virtual void OnHit(class Attack& attack) = 0;

	void TakeDamage(float hp)
	{
		assert(hp >=0);
		health -= hp;
	}

	void Stun(float duration = 2.0f)
	{
		if (!stun)
		{
			stun = true;
			stuntime = -duration;
		}
	}
	//^Accept Visitors and Break Encapsulation^

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
	void StatusUpdate(float dt);

	Allegiance allegiance = Allegiance::None;
	int health;
	bool vulnerable = true;
	float invultime = 0.0f;
	bool stun = false;
	float stuntime = 0.0f;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
	std::vector<std::unique_ptr<class Attack>> attack;
};
