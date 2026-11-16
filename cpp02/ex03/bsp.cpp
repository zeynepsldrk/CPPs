#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed tempVectorX((a.getX()).toFloat() - (b.getX()).toFloat());
	Fixed tempVectorY((a.getY()).toFloat() - (b.getY()).toFloat());

	Fixed tempVectorX2((a.getX()).toFloat() - (point.getX()).toFloat());
	Fixed tempVectorY2((a.getY()).toFloat() - (point.getY()).toFloat());

	float vector = (tempVectorX.getRawBits() * tempVectorX2.getRawBits()) - (tempVectorY.getRawBits() * tempVectorY2.getRawBits());

	tempVectorX = Fixed((b.getX()).toFloat() - (c.getX()).toFloat());
	tempVectorY = Fixed((b.getY()).toFloat() - (c.getY()).toFloat());

	tempVectorX2 = Fixed((b.getX()).toFloat() - (point.getX()).toFloat());
	tempVectorY2 = Fixed((b.getY()).toFloat() - (point.getY()).toFloat());

	float vector2 = (tempVectorX.getRawBits() * tempVectorX2.getRawBits()) - (tempVectorY.getRawBits() * tempVectorY2.getRawBits());

	tempVectorX = Fixed((c.getX()).toFloat() - (a.getX()).toFloat());
	tempVectorY = Fixed((c.getY()).toFloat() - (a.getY()).toFloat());

	tempVectorX2 = Fixed((a.getX()).toFloat() - (point.getX()).toFloat());
	tempVectorY2 = Fixed((a.getY()).toFloat() - (point.getY()).toFloat());

	float vector3 = (tempVectorX.getRawBits() * tempVectorX2.getRawBits()) - (tempVectorY.getRawBits() * tempVectorY2.getRawBits());

	std::cout << "cp1: " << vector << " | cp2: " << vector2 << " | cp3: " << vector3 << std::endl;


    if(vector < 0 && vector2 < 0 && vector3 < 0)
        return true;
    if(vector > 0 && vector2 > 0 && vector3 > 0)
        return true;
    else
        return false;
}
