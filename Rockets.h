#ifndef ROCKETS_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "plane/Plane.h"

class Rockets
	: public Plane
{
public:
	Rockets() = default;
	~Rockets() = default;

	virtual bool OnUserCreate()
	{
		Plane::OnUserCreate();
		std::cout << __FUNCTION__ << std::endl;

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		Plane::OnUserUpdate(fElapsedTime);
		std::cout << __FUNCTION__ << std::endl;

		Clear(olc::BLACK);

		for (int i = -10; i < 10; i++)
		{
			for (int j = -10; j < 10; j++)
			{
				Draw(i, j, olc::RED);
			}
		}
		Draw(0, 0 ,olc::GREEN);

		double minx = minX();
		double miny = minY();
		double maxx = maxX();
		double maxy = maxY();

		double r = 10;
		FillCircle(minx, miny, r, olc::MAGENTA);
		FillCircle(minx, maxy, r, olc::YELLOW);
		FillCircle(maxx, miny, r, olc::BLUE);
		FillCircle(maxx, maxy, r, olc::CYAN);

		return true;
	}

private:

};

#endif // ROCKETS_H
