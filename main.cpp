#include "Aether.h"
#include <stdlib.h>

int main()
{
	srand(0); // always same
	double scale = 120;
	Aether world;
	if (world.Construct(16*scale, 9*scale, std::max(1.0,120/scale), std::max(1.0,120/scale)))
		world.Start();
	return 0;
}