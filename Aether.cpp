#include "Aether.h"
#include <stdlib.h>
#include "Rocket.h"
#include "Wall.h"

Aether::~Aether()
{
	for (size_t i = 0; i < world.size(); i++)
	{
		delete world[i];
		world[i] = nullptr;
	}
}

bool Aether::OnUserCreate()
{
	// olc::PixelGameEngine::SetPixelMode(olc::Pixel::ALPHA);

	Plane::OnUserCreate();
	std::cout << __FUNCTION__ << std::endl;

	for (size_t i = 0; i < 100; i++)
	{
		Rocket* r = new Rocket;
		r->accelerate(Vec2d((rand()%1000)/10.0 -50, (rand()%1000)/10.0 -50));
		world.push_back(r);
	}

	Wall* w = new Wall(Vec2d(0,0),10,10);
	world.push_back(w);

	return true;
}

bool Aether::OnUserUpdate(float fElapsedTime)
{
	Plane::OnUserUpdate(fElapsedTime);//Clear(olc::BLACK);

	/**/
	double minx = minX();
	double miny = minY();
	double maxx = maxX();
	double maxy = maxY();

	std::sort(std::begin(world), std::end(world), [](const Drawable* const a, const Drawable* const b) -> bool
	{
		return a->getZIndex() < b->getZIndex();
	});

	for (size_t i = 0; i < world.size(); i++)
	{
		if(typeid(*world[i]) == typeid(Rocket) )
		{
			static_cast<Rocket*>(world[i])->move(fElapsedTime);
		}
		world[i]->draw(this);
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
