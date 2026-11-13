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
