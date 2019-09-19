#ifndef WALL_H
#define WALL_H

#include "Vec2d.h"
#include "Aether.h"
#include "Drawable.h"

class Wall : public Drawable
{
private:
	Vec2d _origin; // top left
	double _width;
	double _height;

public:
	olc::Pixel color = {0xD7BA89};

	Wall(Vec2d const& origin, double width, double height);

	~Wall() = default;

	void draw(olc::PixelGameEngine* const pge);
};


#endif // WALL_H
