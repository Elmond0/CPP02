/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:00:00 by miricci           #+#    #+#             */
/*   Updated: 2026/04/03 13:01:56 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int nbr) : raw_value(nbr << bp)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float nbr) : raw_value(roundf(nbr * (1 << bp)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &other) : raw_value(other.raw_value)
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->raw_value = other.raw_value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{

	return (this->raw_value);
}

void Fixed::setRawBits(int const raw)
{

	this->raw_value = raw;
	return;
}

float Fixed::toFloat(void) const
{

	return ((float)raw_value / (1 << bp));
}

int Fixed::toInt(void) const
{

	return (raw_value >> bp);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{

	o << f.toFloat();
	return (o);
}

// Comparison operators

bool Fixed::operator>(const Fixed &other) const
{

	return (raw_value > other.raw_value);
}

bool Fixed::operator<(const Fixed &other) const
{

	return (raw_value < other.raw_value);
}

bool Fixed::operator>=(const Fixed &other) const
{

	return (raw_value >= other.raw_value);
}

bool Fixed::operator<=(const Fixed &other) const
{

	return (raw_value <= other.raw_value);
}

bool Fixed::operator==(const Fixed &other) const
{

	return (raw_value == other.raw_value);
}

bool Fixed::operator!=(const Fixed &other) const
{

	return (raw_value != other.raw_value);
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{

	Fixed res;

	res.raw_value = raw_value + other.raw_value;
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{

	Fixed res;

	res.raw_value = raw_value - other.raw_value;
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{

	Fixed res;
	long long prod = (long long)raw_value * (long long)other.raw_value;

	res.setRawBits(prod >> bp);
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const
{

	if (other.raw_value == 0)
	{
		std::cerr << "Math error: division by zero" << std::endl;
		return (Fixed());
	}
	Fixed res;
	long long val = ((long long)raw_value << bp) / other.raw_value;

	res.setRawBits(val);
	return (res);
}

// Increment / Decrement operators

Fixed &Fixed::operator++(void)
{

	raw_value += 1;
	return (*this);
}

Fixed &Fixed::operator--(void)
{

	raw_value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{

	Fixed ret(*this);

	raw_value += 1;
	return (ret);
}

Fixed Fixed::operator--(int)
{

	Fixed ret(*this);

	raw_value -= 1;
	return (ret);
}

// Min / Max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{

	return (a <= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{

	return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{

	return (a >= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{

	return (a >= b ? a : b);
}
