#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    (void)value;
    this->value = toInt();
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    (void)value;
    this->value = (int)toFloat();
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy)
        this->value = copy.getRawBits();
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
    return ((value * 256) >> fractionalBits);
}

int Fixed::toInt( void ) const
{
    return value << fractionalBits;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return output;
}
