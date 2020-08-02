#pragma once

#include "Entity.h"
#include "Animation.h"

class Character : Entity
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
	Character(const Vec<float>& pos);
	void Draw(Graphics& gfx) const override;
	void Draw(Graphics& gfx, Color sub) const;
	void SetDir( const Vec<float>& dir );
	void Attack();
	bool GetSwing() const;
	void Update(float const dt) override;
	Rect<float> GetCollBox() const;
	Rect<float> GetSwingBox() const;

private:
	Surface sprite;
	bool swingstate = false;
	float swingcool = 0.0f;
	std::vector<Animation> animation;
	Sequence curSeq = Sequence::StandingDown;
	Action curAct = Action::Move;
	float speed = 120.0f;
};