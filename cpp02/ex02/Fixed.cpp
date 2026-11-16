#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
    if (value > (2147483647 / 256) || value < (-2147483648 / 256))
    {
        std::cout << "Error: Int out of range" << std::endl;
        this->value = 0;
        return;
    }
    else
        this->value = value * (1 << fractionalBits);
}

Fixed::Fixed(const float value)
{
    if (value > (2147483647 / 256) || value < (-2147483648 / 256))
    {
        std::cout << "Error: Float out of range" << std::endl;
        this->value = 0;
        return;
    }
    else
        this->value = (int)roundf(value * (1 << fractionalBits));
}

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    if(this != &copy)
        this->value = copy.value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const
{
    return value;
}

void Fixed::setRawBits( int const raw )
{
    value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
    return value / (1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return output;
}

bool Fixed::operator>(const Fixed &otherObject) const
{
    if(((*this).value) > (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &otherObject) const
{
    if(((*this).value) >= (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &otherObject) const
{
    if(((*this).value) < (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &otherObject) const
{
    if(((*this).value) <= (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &otherObject) const
{
    if(((*this).value) == (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &otherObject) const
{
    if(((*this).value) != (otherObject.value))
        return true;
    return false;
}

Fixed Fixed::operator-(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)(*this).value - otherObject.value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result.value = 0;
    }
    else
        result.value = (int)temp;

    return (result);
}

Fixed Fixed::operator+(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)(*this).value + otherObject.value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result.value = 0;
    }
    else
        result.value = (int)temp;

    return (result);
}

Fixed Fixed::operator/(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)((*this).value) * 256;
    temp /= otherObject.value;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result.value = 0;
    }
    else
        result.value = (int)temp;

    return (result);
}

Fixed Fixed::operator*(const Fixed &otherObject) const
{
    Fixed result;
    long long temp;

    temp = (long long)((*this).value) * (otherObject.value);
    temp /= 256;

    if (temp > 2147483647 || temp < -2147483648)
    {
        std::cout << "Error: Out of range" << std::endl;
        result.value = 0;
    }
    else
        result.value = (int)temp;
    return (result);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;

    if(temp.value >= 2147483647)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this).value)++;
    return temp;
}

Fixed& Fixed::operator++()
{
    if(((*this).value) >= 2147483647)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this).value)++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    if(((*this).value) <= -2147483648)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this).value)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;

    if(temp.value <= -2147483648)
        std::cout << "Error: Out of range" << std::endl;
    else
        ((*this).value)--;
    return temp;
}

Fixed& Fixed::min(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return secondObject;
    return firstObject;
}

Fixed& Fixed::max(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return firstObject;
    return secondObject;
}

const Fixed& Fixed::min(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return secondObject;
    return firstObject;
}

const Fixed& Fixed::max(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return firstObject;
    return secondObject;
}
