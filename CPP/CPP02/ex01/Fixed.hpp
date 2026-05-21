#pragma once
#include <string>
#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fPvalue;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed(const int fPvalue);
		Fixed(const float fPvalue);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
};
