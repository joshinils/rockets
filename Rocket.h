#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include "Aether.h"

struct vec2d
{
public:
	double x = 0;
	double y = 0;

	vec2d(double x_ = 0, double y_ = 0)
		: x(x_)
		, y(y_)
	{ }

	inline vec2d const& normalize()
	{
		double l = length();

		if(l!=0)
		{
			x /= l;
			y /= l;
		}
		return *this;
	}

	double angleTo(vec2d const& other) const
	{
		double cosTheta = (double)(operator* (other) / (this->length() * other.length()));

		return acos(cosTheta);
	}

	inline double length() const
	{
		return sqrt(x*x + y*y);
	}

	// dot product
	inline double operator* (vec2d const& v) const
	{
		return x * v.x + y * v.y;
	}

	// scaling
	inline vec2d operator* (double s) const
	{
		vec2d res = *this;
		return res *= s;
	}

	// other order of arguments, double first
	friend inline vec2d operator* (double s, vec2d const& v)
	{
		return v * s;
	}

	inline vec2d const& operator*= (double s)
	{
		x *= s;
		y *= s;

		return *this;
	}

	inline vec2d operator/ (double s) const
	{
		vec2d res = *this;
		return res /= s;
	}

	inline vec2d const& operator/= (double s)
	{
		x /= s;
		y /= s;

		return *this;
	}

	inline vec2d operator+ (vec2d const& v) const
	{
		vec2d res = *this;
		return res += v;
	}

	inline vec2d const& operator+= (vec2d const& v)
	{
		x += v.x;
		y += v.y;

		return *this;
	}

	inline vec2d operator- (vec2d const& v) const
	{
		vec2d res = *this;
		return res -= v;
	}

	inline vec2d operator- () const
	{
		return operator*(-1);
	}

	inline vec2d const& operator-= (vec2d const& v)
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}

	friend std::ostream& operator<< (std::ostream& ostr, vec2d const& v)
	{
		return ostr << "(" << v.x << ", " << v.y << ")";
	}
};

class Rocket
{
private:
	vec2d _pos;
	vec2d _vel;
	vec2d _acc;
	bool _alive = true;
	int winner = 0;
	const double _friction = 0.9;

public:
	Rocket() = default;
	~Rocket() = default;

	void accelerate(vec2d change)
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
