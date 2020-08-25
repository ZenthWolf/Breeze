#pragma once



#include "Vec.h"
#include "Rect.h"
#include "Graphics.h"
#include "Animation.h"
#include "Keyboard.h"
#include<vector>
#include<memory>


class Attack;
class Entity;

class Character;
class Enemy;

class SwordSrike;
class SwordStun;

class Attack
{
public:
	//VConcrete Elements to be VisitedV
	virtual void Afflict(Character& targ) = 0;
	virtual void Afflict(Enemy& targ) = 0;
	//^Concrete Elements to be Visited^

	Attack(const Vec<float> pos, const Vec<float> hBoxSize);
	Attack()
	{
		pos = { 0,0 };
		hitBoxSize = { 0,0 };
	}

	void Update(float dt);
	void Draw(Graphics& gfx, Color col) const;
	Rect<float> GetCollBox() const;

private:
	Vec<float> pos;
	Vec<float> hitBoxSize;
};

class Entity
{
public:
	//VAccept Visitors and Break EncapsulationV
	virtual void OnHit(class Attack& attack) = 0;

	void TakeDamage(float hp)
	{
		assert(hp >= 0);
		health -= hp;
		vulnerable = false;
		invultime = -0.5f;
		flash = true;
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
	//virtual void OnHit(Entity& attacker, int atindex) = 0;

	Vec<float> GetPos() const;
	virtual void PushBox(Rect<float> wall);
	Allegiance GetAllegiance() const;
	virtual Rect<float> GetCollBox() const;
	int GetAttackNum() const;
	bool IsVulnerable() const;


protected:
	virtual ~Entity() = default;

	Entity(Vec<float> pos, Allegiance allegiance);
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
	bool flash = false;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	Vec<float> collBoxSize = { 0.0f, 0.0f };
	std::vector<std::unique_ptr<class Attack>> attack;
};

class Character : public Entity
{
private:
	enum class Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};

	enum class Action
	{
		Move,
		Attack,
		Jump
	};
public:
	Character(const Vec<float>& pos, Keyboard& kbd);
	void Draw(Graphics& gfx) const override;
	void Draw(Graphics& gfx, Color sub) const;
	void SetDir(const Vec<float>& dir);
	bool GetSwing() const;
	void Update(float const dt) override;
	void Input(Keyboard::Event e);
	Rect<float> GetCollBox() const override;
	Rect<float> GetAttackBox(int atindex) const;
	Attack& GetAttack(int atindex) const;

	void OnHit(class Attack& attack) override
	{
		attack.Afflict(*this);
	}

private:
	void MakeAttack(int type = 0);
	void SetVel();

	Surface sprite;
	bool swingstate = false;
	float swingcool = 0.0f;
	std::vector<Animation> animation;
	Sequence curSeq = Sequence::StandingDown;
	Action curAct = Action::Move;
	float speed = 120.0f;

	Keyboard& kbd;
};

class Enemy : public Entity
{
public:
	Enemy(const Vec<float> pos, const Vec<float> vel);

	void Update(const float dt) override;
	void Draw(Graphics& gfx) const override;
	void Draw2(Graphics& gfx);
	void OnHit(class Attack& attack) override
	{
		attack.Afflict(*this);
	}
	virtual void PushBox(Rect<float> wall) override;

	//This trash has to be handled better some other way, right?
	void fixpos(float dr);

private:
	void BounceX();
	void BounceY();

	Color col;
	float size;
};

class SwordStrike : public Attack
{
public:
	SwordStrike(const Vec<float> pos, const Vec<float> hBoxSize)
		:Attack(pos, hBoxSize)
	{}

	void Afflict(Character& targ)
	{
		if (targ.IsVulnerable())
		{
			targ.TakeDamage(2);
		}
	}
	void Afflict(Enemy& targ)
	{
		if (targ.IsVulnerable())
		{
			targ.TakeDamage(2);
		}
	}
};

class SwordStun : public Attack
{
public:
	SwordStun(const Vec<float> pos, const Vec<float> hBoxSize)
		:Attack(pos, hBoxSize)
	{}

	void Afflict(Character& targ)
	{
		if (targ.IsVulnerable())
		{
			targ.TakeDamage(1);
			targ.Stun();
		}
		
	}
	void Afflict(Enemy& targ)
	{

		if (targ.IsVulnerable())
		{
			targ.TakeDamage(1);
			targ.Stun();
		}
	}
};