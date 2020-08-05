#include "Room.h"

/*
void Room::Update(float dt)
{
	// Inform dynamic objects that it is time to update!
	Ava.Update(dt);
	for (int i = 0; i < Enemy.size(); i++)
	{
		Enemy[i].Update(dt);
	}

	for (int i = 0; i < Attack.size(); i++)
	{
//		Attack[i].Update(dt);
	}

	//Do the collisiony type stuff
	CheckObstacles();
	HitDetection();      //Active hits have preference over passive hits
	EnemyCollision();
	
}
*/

/*
void Room::CheckObstacles()
{
	for (int i = 0; i < Obstacle.size(); i++)
	{
		//STATIC COLLISION

		Rect<float> staticBox = Obstacle[i].GetCollBox();

		//Check Ava/Obstacle Collision
		if ( IsColliding( Ava.GetCollBox(), staticBox) )
		{
			Ava.PushBox( staticBox ); // A function which replaces Ava to end collision
		}

		//Check Enemy/Obstacle Collision
		for (int j = 0; j < Enemy.size(); j++)
		{
			Rect<float> enemyBox = Enemy[j].GetCollBox();
			if (IsColliding( enemyBox, staticBox ))
			{
				Enemy.PushBox( staticBox ); // A function which replaces Enemy to end collision- may also alter behavior
			}
		}
	}
}
*/

/*
void Room::EnemyCollision()
{
	//Check Ava/Enemy Collision
	Rect<float> avaBox = Ava.GetCollBox();

	for (int i = 0; i < Enemy.size(); i++)
	{
		Rect<float> enemyBox = Enemy[i].GetCollBox();
		if (IsColliding(avaBox, enemyBox ))
		{
			// Ava has a response- gets hit, flashes, is pushed away, etc.
			// Enemy may have a response- animation/sound effect, health gain, tactics change
			// Details of hit may be enemy dependent. The ENEMY should handle the process since it is the most unpredictable piece!

			Enemy[i].Contact(Ava);
			break; // Only one may hit

			//
			//	Note: The quality of this hit detection scheme will be interesting with multiple enemies. It may make for eratic recoiling by Ava
			//	and become unintentionally frustrating. Two possible tunes: Easy- the *closest* contact matters, not the arbitrary first; or Hard-
			//	an entirely new scheme of hit detection which scans the whole screen more objectively to find a "reasonable" direction
			//
		}
	}
}
*/

/*
void Room::HitDetection()
{
	//
		// What even is an "Attack"?
		// Some attacks are affixed to their source (Ava's swing) and will recoil on their source
		// Some attacks are disjoint from their source (a fireball or energy beam, which cannot affect their source
		// Some attacks should play sides (Enemies don't hurt each other; *most* of Ava's attacks should not affect her
		// Attacks may need a reference to their particular source (for recoil) or "side" at least
	//
}
*/

/*
bool Room::IsColliding(const Rect<float> box1, const Rect<float> box2) const
{
	if ("box 1 collides with box 2")
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/