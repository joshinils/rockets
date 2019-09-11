#include "Rockets.h"
#include <stdlib.h>

int main()
{
	srand(0); // always same
	double scale = 120;
	Rockets demo;
	if (demo.Construct(16*scale, 9*scale, std::max(1.0,120/scale), std::max(1.0,120/scale)))
		demo.Start();
	return 0;
}