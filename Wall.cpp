#include "Wall.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"

Wall::Wall(Vec2d const & origin, double width, double height)
	: Drawable(Drawable::zIndex::background)
	, _origin(origin)
	, _width(width)
	, _height(height)
{ }

void Wall::draw(olc::PixelGameEngine* const pge)
{
	dynamic_cast<Aether*>(pge)->FillRect(_origin.x, _origin.y, _width, _height, color);
}
