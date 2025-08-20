/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:58:47 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 15:07:24 by oiskanda         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& rhs)  const {return _raw >  rhs._raw;}
bool Fixed::operator<(const Fixed& rhs)  const {return _raw <  rhs._raw;}
bool Fixed::operator>=(const Fixed& rhs) const {return _raw >= rhs._raw;}
bool Fixed::operator<=(const Fixed& rhs) const {return _raw <= rhs._raw;}
bool Fixed::operator==(const Fixed& rhs) const {return _raw == rhs._raw;}
bool Fixed::operator!=(const Fixed& rhs) const {return _raw != rhs._raw;}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed r;
	r._raw = this->_raw + rhs._raw;
	return (r);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed r;
	r._raw = this->_raw - rhs._raw;
	return (r);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed r;
    if (rhs._raw == 0)
	{
        r._raw = 0;
        return r;
    }
    long long num = (static_cast<long long>(this->_raw) << _fractionalBits);
    r._raw = static_cast<int>(num / rhs._raw);
    return r;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    long long prod = static_cast<long long>(this->_raw) * static_cast<long long>(rhs._raw);
    Fixed r;
	r._raw = static_cast<int>(prod >> _fractionalBits);
    return r;
}

Fixed& Fixed::operator++()
{
	++_raw;
	return  (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_raw;
    return tmp;
}
Fixed& Fixed::operator--()
{
	--_raw;
	return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_raw;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    return (os << fx.toFloat());
}
