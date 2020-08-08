#pragma once
//Playground to identify needed interactions
//Eventual baseline for "Room" class, but don't take this shit seriously.

#include "Character.h"
#include "Enemy.h"
#include "Keyboard.h"
#include "Graphics.h"
#include <vector>


class Room
{
public:
	Room(Character& Ava, int scenario, Keyboard& kbd);
	void Update(float dt);
	void Draw(Graphics& gfx);

private:
	void ReadInput() const;
	void CheckObstacles(); //Check entities are not colliding with obstacles
	void EnemyCollision(); //Check if Ava is in contact with an enemy
	void HitDetection(); //Detect Collision of attacks
	bool IsColliding(const Rect<float> box1, const Rect<float> box2) const; //Do these objects collide?

	Character& Ava; //Does Ava properly belong to the "Room" she is in? Or do rooms just "know" about her?
	std::vector<Enemy> enemy; // Should have a list of enemies- ALL ENEMIES ARE REQUIRED TO DO ANYTHING STATED HERE, SO BASIS FOR SUBCLASS!
	std::vector<Rect<float>> obstacle; // List of obstacles- which will eventually be a class like "ground" once was.

	Keyboard& kbd;
};