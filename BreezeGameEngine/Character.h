#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Keyboard.h"

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
	void SetDir( const Vec<float>& dir );
	bool GetSwing() const;
	void Update(float const dt) override;
	void Input(Keyboard::Event e);
	Rect<float> GetCollBox() const override;
	Rect<float> GetAttackBox(int atindex) const;

	void OnHit(Entity& attacker, int atindex) override
	{}

private:
	void MakeAttack();
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