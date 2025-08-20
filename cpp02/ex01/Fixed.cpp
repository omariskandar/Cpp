/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:58:47 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 14:21:36 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructer called.\n";
}

Fixed::Fixed(const Fixed& other) : _raw(0)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_raw = rhs._raw;
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default desstructer called.\n";
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _raw = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _raw = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_raw = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_raw) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _raw >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    return (os << fx.toFloat());
}
