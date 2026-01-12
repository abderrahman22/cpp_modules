/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:01:41 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/09 01:49:02 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :value(0){}

Fixed::Fixed(const int v)
{
	value = v * (1 << fractional_bits);
}

Fixed::Fixed(const float v)
{
	value = roundf(v * (1 << fractional_bits));
}


Fixed& Fixed::operator=(const Fixed& other)
{
	value = other.value;
	return *this;
}

Fixed::Fixed(const Fixed& other): value(other.value){}

Fixed::~Fixed(){}

float Fixed::toFloat( void ) const
{
	return ((float)value / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (value / (1 << fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

//ex02

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

bool Fixed::operator>(Fixed &other) const
{
	if (this->value > other.value)
		return true;
	else
		return false;
}

bool Fixed::operator<(Fixed &other) const
{
	if (this->value < other.value)
		return true;
	else
		return false;
}

bool Fixed::operator>=(Fixed &other) const
{
	if (this->value >= other.value)
		return true;
	else
		return false;
}

bool Fixed::operator<=(Fixed &other) const
{
	if (this->value <= other.value)
		return true;
	else
		return false;
}

bool Fixed::operator==(Fixed &other) const
{
	if (this->value == other.value)
		return true;
	else
		return false;
}

bool Fixed::operator!=(Fixed &other) const
{
	if (this->value != other.value)
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value + other.value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value - other.value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)//++i
{
	this->value++;
	return (*this);
}

Fixed& Fixed::operator--(void)//--i
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int)//i++
{
	Fixed tmp(*this);
	this->value++;
	return tmp;
}

Fixed Fixed::operator--(int)//i--
{
	Fixed tmp(*this);
	this->value--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.value < b.value)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.value < b.value)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.value > b.value)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.value > b.value)
		return a;
	return b;
}
