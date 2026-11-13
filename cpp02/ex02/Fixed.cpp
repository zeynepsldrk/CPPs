#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;

    int scaled = value * (1 << fractionalBits);

    if (scaled > 2147483647 || scaled < -2147483648)
    {
        std::cout << "Error: Float out of range" << std::endl;
        this->value = 0;
        return;
    }
    else
        this->value = value * (1 << fractionalBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    
    float scaled = value * (1 << fractionalBits);

    if (scaled > 2147483647 || scaled < -2147483648)
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
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    //value = copy.value;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy)
        this->value = copy.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
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

bool Fixed::operator>(Fixed &otherObject) const
{
    if(((*this).value) > (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator>=(Fixed &otherObject) const
{
    if(((*this).value) >= (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator<(Fixed &otherObject) const
{
    if(((*this).value) < (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator<=(Fixed &otherObject) const
{
    if(((*this).value) <= (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator==(Fixed &otherObject) const
{
    if(((*this).value) == (otherObject.value))
        return true;
    return false;
}

bool Fixed::operator!=(Fixed &otherObject) const
{
    if(((*this).value) != (otherObject.value))
        return true;
    return false;
}

Fixed& Fixed::operator-(const Fixed &firstObject, const Fixed &secondObject) const
{
    Fixed result;

    result.value = (firstObject.value) - (secondObject.value);
    return (result);
}

Fixed& Fixed::operator+(const Fixed &firstObject, const Fixed &secondObject) const
{
    Fixed result;

    result.value = (firstObject.value) + (secondObject.value);
    return (result);
}

Fixed& Fixed::operator/(const Fixed &firstObject, const Fixed &secondObject) const
{
    Fixed result;

    result.value = (firstObject.value) / (secondObject.value);
    return (result);
}

Fixed& Fixed::operator*(const Fixed &firstObject, const Fixed &secondObject) const
{
    Fixed result;

    result.value = (firstObject.value) * (secondObject.value);
    return (result);
}

Fixed& Fixed::operator++(int)
{
    Fixed temp = *this;
    ((*this).value)++;
    return temp;
}

Fixed& Fixed::operator++()
{
    return (((*this).value)++);
}

Fixed& Fixed::operator--()
{
    return (((*this).value)--);
}

Fixed& Fixed::operator--(int)
{
    Fixed temp = *this;
    ((*this).value)--;
    return temp;
}

static Fixed& Fixed::min(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return secondObject;
    return firstObject;
}

static Fixed& Fixed::max(Fixed &firstObject, Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return firstObject;
    return secondObject;
}

static const Fixed& Fixed::min(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return secondObject;
    return firstObject;
}

static const Fixed& Fixed::max(const Fixed &firstObject, const Fixed &secondObject)
{
    if((firstObject.value) > (secondObject.value))
        return firstObject;
    return secondObject;
}
