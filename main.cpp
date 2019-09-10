#include "Rockets.h"

int main()
{
	double scale = 40;
	Rockets demo;
	if (demo.Construct(16*scale, 9*scale, 120/scale, 120/scale))
		demo.Start();
	return 0;
}