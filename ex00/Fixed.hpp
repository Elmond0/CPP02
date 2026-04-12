/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:55:03 by elmondo           #+#    #+#             */
/*   Updated: 2026/04/12 12:37:48 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int raw_value;
	static const int bp = 8;

public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
