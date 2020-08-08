#include "Obstacle.h"

Obstacle::Obstacle(const Vec<float> v0, const Vec<float> v1)
	:box(v0,v1)
{

}

void Obstacle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(box, col);
}

Rect<float> Obstacle::GetCollBox()
{
	return box;
}
