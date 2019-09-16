#include "Aether.h"
#include <stdlib.h>

bool Aether::OnUserCreate()
{
	Plane::OnUserCreate();
	std::cout << __FUNCTION__ << std::endl;

	for (size_t i = 0; i < 1; i++)
	{
		Rocket r;
		r.accelerate(vec2d((rand()%1000)/10.0 -50, (rand()%1000)/10.0 -50));
		aether.push_back(r);
	}

	return true;
}

bool Aether::OnUserUpdate(float fElapsedTime)
{
	Plane::OnUserUpdate(fElapsedTime);

	//Clear(olc::BLACK);

	double minx = minX();
	double miny = minY();
	double maxx = maxX();
	double maxy = maxY();

	/**
	for (size_t i = 0; i < olc::PixelGameEngine::ScreenWidth(); i++)
	{
		for (size_t j = 0; j < olc::PixelGameEngine::ScreenHeight(); j++)
		{
			double x = minx + (maxx*i - minx * i) / olc::PixelGameEngine::ScreenWidth();
			double y = miny + (maxy*j - miny * j) / olc::PixelGameEngine::ScreenHeight();
		}
	}
	/**

	for (size_t i = 0; i < aether.size(); i++)
	{
		aether[i].move(fElapsedTime);
		aether[i].draw(this);
	}

	/**
	for (size_t i = 0; i < 1000; i++)
	{
		double x1 = minx + (rand()%1000)/1000.0 * (maxx-minx);
		double x2 = minx + (rand()%1000)/1000.0 * (maxx-minx);
		double y1 = miny + (rand()%1000)/1000.0 * (maxy-miny);
		double y2 = miny + (rand()%1000)/1000.0 * (maxy-miny);
		DrawLine(x1, y1, x2, y2);
	}
	/**/

	return true;
}
