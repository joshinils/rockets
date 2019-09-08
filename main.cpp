#include "Rockets.h"

int main()
{
	Rockets demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
	return 0;
}