#include "Point_hpp"

Point::Point()
{
    _x = 0;
    _y = 0;
}

Point& Point::operator=(const Point &copy)
{
    if(this != &copy)
    {
        _x = copy.x;
        _y = copy.y;
    }
    return *this;
}

Point::Point(const Point &copy)
{
    _x = copy.x;
    _y = copy.y;
}

Point::~Point() {}

Point::Point(const float x, const float y)
{
    _x = x;
    _y = y;
}

Point Point::getX () const
{
    return _x;
}

Point Point::getY () const
{
    return _y;
}
