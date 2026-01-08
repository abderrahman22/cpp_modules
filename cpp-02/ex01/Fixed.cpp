/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:01:41 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/08 15:37:34 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

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
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.value;
	return *this;
}

Fixed::Fixed(const Fixed& other): value(other.value)
{
	std::cout << "Copy Constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
