#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
    if (value > (2147483647 / 256) || value < (-2147483648 / 256))
    {
        std::cout << "Error: Int out of range" << std::endl;
        this->_value = 0;
        return;
    }
    else
        this->_value = value * (1 << _fractionalBits);
}

Fixed::Fixed(const float value)
{
    if (value > (2147483647 / 256) || value < (-2147483648 / 256))
    {
        std::cout << "Error: Float out of range" << std::endl;
        this->_value = 0;
        return;
    }
    else
        this->_value = (int)roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    if(this != &copy)
        this->_value = copy._value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const
{
    return _value;
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return _value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return output;
}

bool Fixed::operator>(const Fixed &otherObject) const
{
    if(((*this)._value) > (otherObject._value))
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &otherObject) const
{
    if(((*this)._value) >= (otherObject._value))
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &otherObject) const
{
    if(((*this)._value) < (otherObject._value))
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &otherObject) const
{
    if(((*this)._value) <= (otherObject._value))
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &otherObject) const
{
    if(((*this)._value) == (otherObject._value))
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &otherObject) const
{
    if(((*this)._value) != (otherObject._value))
        return true;
    return false;
}

Fixed Fixed::operator-(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)(*this)._value - otherObject._value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result._value = 0;
    }
    else
        result._value = (int)temp;

    return (result);
}

Fixed Fixed::operator+(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)(*this)._value + otherObject._value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result._value = 0;
    }
    else
        result._value = (int)temp;

    return (result);
}

Fixed Fixed::operator/(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)((*this)._value) * 256;
    temp /= otherObject._value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result._value = 0;
    }
    else
        result._value = (int)temp;

    return (result);
}

Fixed Fixed::operator*(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)((*this)._value) * (otherObject._value);
    temp /= 256;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result._value = 0;
    }
    else
        result._value = (int)temp;
    return (result);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;

    if(temp._value >= 2147483647)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this)._value)++;
    return temp;
}

Fixed& Fixed::operator++()
{
    if(((*this)._value) >= 2147483647)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this)._value)++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    if(((*this)._value) <= -2147483648)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this)._value)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;

    if(temp._value <= -2147483648)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this)._value)--;
    return temp;
}

Fixed& Fixed::min(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject._value) > (secondObject._value))
        return secondObject;
    return firstObject;
}

Fixed& Fixed::max(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject._value) > (secondObject._value))
        return firstObject;
    return secondObject;
}

const Fixed& Fixed::min(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject._value) > (secondObject._value))
        return secondObject;
    return firstObject;
}

const Fixed& Fixed::max(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject._value) > (secondObject._value))
        return firstObject;
    return secondObject;
}
