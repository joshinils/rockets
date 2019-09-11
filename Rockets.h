#ifndef ROCKETS_H
#define ROCKETS_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "plane/Plane.h"
#include "Rocket.h"

class Rocket;
class Rockets
	: public Plane
{

private:
	std::vector<Rocket> rockets;

public:
	Rockets() = default;
	~Rockets() = default;

	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

private:

};

#endif // ROCKETS_H
