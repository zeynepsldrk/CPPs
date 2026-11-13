#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    private:
        int value;
        static const int fractionalBits = 8;
    
    public:

        Fixed(const int value);
        Fixed(const float value);

        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(Fixed &otherObject) const;
        bool operator<(Fixed &otherObject) const;
        bool operator>=(Fixed &otherObject) const;
        bool operator<=(Fixed &otherObject) const;
        bool operator==(Fixed &otherObject) const;
        bool operator!=(Fixed &otherObject) const;

        Fixed &operator+(const Fixed &firstObject, const Fixed &secondObject) const;
        Fixed &operator-(const Fixed &firstObject, const Fixed &secondObject) const;
        Fixed &operator*(const Fixed &firstObject, const Fixed &secondObject) const;
        Fixed &operator/(const Fixed &firstObject, const Fixed &secondObject) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static const Fixed& min(Fixed &firstObject, Fixed &secondObject);
        static const Fixed& min(const Fixed &firstObject, const Fixed &secondObject);
        static const Fixed& max(Fixed &firstObject, Fixed &secondObject);
        static const Fixed& max(const Fixed &firstObject, const Fixed &secondObject);
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif