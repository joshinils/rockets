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
		double minx = minX();
		double miny = minY();
		double maxx = maxX();
		double maxy = maxY();

		for (size_t i = 0; i < olc::PixelGameEngine::ScreenWidth(); i++)
		{
			for (size_t j = 0; j < olc::PixelGameEngine::ScreenHeight(); j++)
			{
				double x = minx + (maxx-minx) * i / olc::PixelGameEngine::ScreenWidth();
				double y = miny + (maxy-miny) * j / olc::PixelGameEngine::ScreenHeight();

				size_t amount = mandelbrot(x,y);
				Draw(x,y,olc::Pixel(amount%255, (amount*8+1)%255, (amount*16+1)%255));
			}
		}



		for (int i = -10; i < 10; i++)
		{
			for (int j = -10; j < 10; j++)
			{
				Draw(i, j, olc::RED);
			}
		}
		Draw(0, 0 ,olc::GREEN);
		return true;
	}

	const int MAXITERS = 100;

	template <typename zahl>
	size_t mandelbrot(const zahl& rC, const zahl& iC)
	{
		size_t iters = 0;
		zahl rZ = 0;
		zahl iZ = 0;

		while (++iters < MAXITERS && rZ*rZ + iZ*iZ < 4)
		{
			// malnehmen
			// Z = (rZ + iZ)^2 + (rC + iC)
			// Z = (rZ + I*iZ)(rZ + I*iZ) + (rC + I*iC)
			// Z = rZ*rZ + 2*IiZ*rZ + I^2*iZ^2 + (rC + I*iC)
			// Z = rZ*rZ + rC - iZ^2   +   2*I*iZ*rZ + I*iC

			static zahl oldrZ = rZ;
			oldrZ = rZ;
			// rZ <- rZ*rZ + rC - iZ^2

			rZ = rZ*rZ + rC - iZ*iZ;
			//rZ *= rZ;
			//rZ += rC - iZ*iZ;

			// iZ <- 2*iZ*rZ + iC
			iZ = 2 * iZ*oldrZ + iC;
			//iZ *= 2*oldrZ;
			//iZ += iC;
		}

		return iters;
	}


private:

};

#endif // ROCKETS_H
