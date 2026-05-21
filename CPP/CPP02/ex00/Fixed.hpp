#pragma once
#include <iostream>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
