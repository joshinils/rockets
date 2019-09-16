#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include "Aether.h"
#include "plane/Vec2d.h"

class Rocket
{
private:
	Vec2d _pos;
	Vec2d _vel;
	Vec2d _acc;
	bool _alive = true;
	int winner = 0;
	const double _friction = 0.9;

public:
	Rocket() = default;
	~Rocket() = default;

	void accelerate(Vec2d change)
	{
		_acc += change;
	}

	void killEngine()
	{
		_acc *= 0;
	}

	void move(double timePassed)
	{
		_vel += timePassed * _acc;
		_vel *= _friction;
		_pos += timePassed * _vel;
	}

	double size=15;
	void draw(olc::PixelGameEngine* pge);
};

#endif // ROCKET_H
