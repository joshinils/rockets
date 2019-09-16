#ifndef AETHER_H
#define AETHER_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "plane/Plane.h"
#include "Rocket.h"

class Rocket;
class Aether
	: public Plane
{

private:
	std::vector<Rocket> aether;

public:
	Aether() = default;
	~Aether() = default;

	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

private:

};

#endif // AETHER_H
