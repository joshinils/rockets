#include "Rockets.h"
#include <stdlib.h>

bool Rockets::OnUserCreate()
{
	Plane::OnUserCreate();
	std::cout << __FUNCTION__ << std::endl;

	for (size_t i = 0; i < 1; i++)
	{
		Rocket r;
		r.accelerate(vec2d((rand()%1000)/10.0 -50, (rand()%1000)/10.0 -50));
		rockets.push_back(r);
	}

	return true;
}

bool Rockets::OnUserUpdate(float fElapsedTime)
{
	Plane::OnUserUpdate(fElapsedTime);
	std::cout << __FUNCTION__ << std::endl;

	Clear(olc::BLACK);
	double minx = minX();
	double miny = minY();
	double maxx = maxX();
	double maxy = maxY();

	for (size_t i = 0; i < olc::PixelGameEngine::ScreenWidth(); i++)
	{
		for (size_t j = 0; j < olc::PixelGameEngine::ScreenHeight(); j++)
		{
			double x = minx + (maxx*i - minx * i) / olc::PixelGameEngine::ScreenWidth();
			double y = miny + (maxy*j - miny * j) / olc::PixelGameEngine::ScreenHeight();
		}
	}

	for (size_t i = 0; i < rockets.size(); i++)
	{
		rockets[i].move(fElapsedTime);
		rockets[i].draw(this);
	}

	return true;
}
