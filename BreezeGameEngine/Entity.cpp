#include "Entity.h"


Entity::Entity(Vec<float> pos, Allegiance allegiance)
	:pos(pos), health(0), allegiance(allegiance)
{
}


Entity::Entity(Vec<float> pos, int health)
	:pos(pos), health(health)
{
}

Entity::Entity(Vec<float> pos, Vec<float> vel, int health, Allegiance allegiance)
	: pos(pos), vel(vel), health(health), allegiance(allegiance)
{
}


Vec<float> Entity::GetPos() const
{
	return pos;
}

/*
void Entity::PushBox(Rect<float> wall)
{
	float Deviance[4] = { 0.0f }; //0-4 Left, Up, Right, Down
	float MinDev = -1.0f;

	Rect<float> entcoll = GetCollBox();

	float UpDeviance = entcoll.Y1 - wall.Y0;
	if (UpDeviance > 0.0f)
	{
		MinDev = UpDeviance;
	}

	float LeftDeviance = entcoll.X1 - wall.X0;
	if (LeftDeviance > 0.0f && LeftDeviance < MinDev)
	{
		MinDev = LeftDeviance;
	}
	float DownDeviance = wall.Y1 - entcoll.Y0;
	if (DownDeviance > 0.0f && DownDeviance < MinDev)
	{
		MinDev = DownDeviance;
	}
	float RightDeviance = wall.X1 - entcoll.X0;
	if (RightDeviance > 0.0f && RightDeviance < MinDev)
	{
		MinDev = RightDeviance;
	}

	if (MinDev == UpDeviance)
	{
		pos.Y -= UpDeviance;
	}
	else if (MinDev == LeftDeviance)
	{
		pos.X -= LeftDeviance;
	}
	else if (MinDev == DownDeviance)
	{
		pos.Y += DownDeviance;
	}
	else if (MinDev == RightDeviance)
	{
		pos.X += RightDeviance;
	}
	else
	{
		//There probably should be an error or something here...
	}
}
*/

Entity::Allegiance Entity::GetAllegiance() const
{
	return allegiance;
}


Rect<float> Entity::GetCollBox() const
{
	return Rect<float>(pos, pos+collBoxSize);
}

