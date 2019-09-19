#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"

class Drawable
{
public:
	enum zIndex
	{
		unset = 0,
		background,
		foreground,
		gui,
	};

private: zIndex _zOrder = unset;
public:
	Drawable(zIndex zIndex = unset)
		: _zOrder(zIndex)
	{ };

	virtual ~Drawable() = default;

	virtual void draw(olc::PixelGameEngine* const pge) = 0;

	zIndex getZIndex() const
	{
		return _zOrder;
	}
};

#endif // DRAWABLE_H
