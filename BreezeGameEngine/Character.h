#pragma once

#include "Animation.h"
#include "Vec.h"
#include "Ground.h"

class Character
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
public:
	Character(const Vec<float>& pos);
	void Draw(Graphics& gfx) const;
	void Draw(Graphics& gfx, Color sub) const;
	void SetDir( const Vec<float>& dir );
	void Attack();
	bool GetSwing() const;
	Vec<float> GetPos() const;
	void Update(float const dt);
	Rect<float> GetCollBox() const;
	Rect<float> GetSwingBox() const;

private:
	Surface sprite;
	Vec<float> pos;
	Vec<float> vel = { 0.0f, 0.0f };
	bool swingstate = false;
	float swingcool;
	std::vector<Animation> animation;
	Sequence curSeq = Sequence::StandingDown;
	float speed = 100.0f;
};