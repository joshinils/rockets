#include "Rocket.h"
#include "Aether.h"

void Rocket::draw(olc::PixelGameEngine* pge)
{
	Vec2d velN = _vel;
	velN.normalize();

	Vec2d front = _pos + velN * size;
	Vec2d backR(_pos.x + (-0.5		*velN.x + 0.8660254*velN.y)*size / 2,
				_pos.y + (-0.8660254*velN.x - 0.5	   *velN.y)*size / 2);
	Vec2d backL(_pos.x + (-0.5		*velN.x - 0.8660254*velN.y)*size / 2,
				_pos.y + (+0.8660254*velN.x - 0.5	   *velN.y)*size / 2);

	olc::Pixel fillCol(255, 255, 255, 255);//10 + 10 * int(_alive));
	olc::Pixel strokeCol(255, 255, 255, 255);//5 + 5 * int(_alive));
	static_cast<Aether*>(pge)->FillTriangle(front.x, front.y, backL.x, backL.y, backR.x, backR.y, fillCol);
	static_cast<Aether*>(pge)->DrawTriangle(front.x, front.y, backL.x, backL.y, backR.x, backR.y, strokeCol);

	strokeCol = olc::WHITE;
	strokeCol.a = 200;
	if (_alive)
		strokeCol.b = 0;
	else if (winner == 1)
	{
		strokeCol.r = 0;
		strokeCol.b = 0;
	}
	else
	{
		strokeCol.g = 0;
		strokeCol.b = 0;
	}
	static_cast<Aether*>(pge)->FillCircle(_pos.x, _pos.y, size / 3, strokeCol);
}
