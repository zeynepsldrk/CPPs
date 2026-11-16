#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

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

        float getX (void) const;
        float getY (void) const;
        bool bsp( Point const a, Point const b, Point const c, Point const point);


};


#endif