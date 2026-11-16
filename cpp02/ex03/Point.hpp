#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

    private:
        const Fixed _x;
        const Fixed _y; 
    public:
        Point();
        Point(const Point &copy);
        Point &operator=(const Point &copy);
        ~Point();

        Point(const float x, const float y);
        Fixed getX (void) const;
        Fixed getY (void) const;
        
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif