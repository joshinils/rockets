#include "Wall.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"

Wall::Wall(Vec2d const & origin, double width, double height)
	: Drawable(Drawable::zIndex::background)
	, _origin(origin)
	, _width(width)
	, _height(height)
	, _center(origin.x + width/2, origin.y + height/2)
{ }

void Wall::draw(olc::PixelGameEngine* const pge)
{
	dynamic_cast<Aether*>(pge)->FillRect(_origin.x, _origin.y, _width, _height, color);
}

double Wall::distanceTo(Vec2d const & p)
{
	//TODO
	return 0.0;

	/*
		from pRocket
			//https://gamedev.stackexchange.com/questions/44483/how-do-i-calculate-distance-between-a-point-and-an-axis-aligned-rectangle
			float dx = max( abs(agent[i].xPos - (barrier[1].xTop + barrier[1].xWid / 2)) - barrier[1].xWid / 2, 0);
			float dy = max( abs(agent[i].yPos - (barrier[1].yTop + barrier[1].yWid / 2)) - barrier[1].yWid / 2, 0);
			agent[i].score = -sqrt(dx*dx + dy*dy) + agent[i].winner*500;

	*/
}
