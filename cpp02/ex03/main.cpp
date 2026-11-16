#include "Fixed.hpp"

int main( void ) {

    Point a(-2.0f, 3.0f);
    Point b(2.0f, 3.0f);
    Point c(-1.0f, 0.0f);

    //Test 1 Nokta üçgen içinde
    Point p1(-1.0f, 2.0f);
    std::cout << bsp(a, b, c, p1) << std::endl;

    //Test 2 Nokta üçgen dışında
    Point p2(-3.0f, 2.0f);
    std::cout << bsp(a, b, c, p2) << std::endl;

    //Test 3 Nokta üçgen kenarında
    Point p3(0.0f, 3.0f);
    std::cout << bsp(a, b, c, p3) << std::endl;

    return 0;
}
