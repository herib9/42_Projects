#include "Fixed.hpp"

Fixed::Fixed() : _fPvalue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fPvalue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fPvalue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int fPvalue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fPvalue = fPvalue << _bits;
}

Fixed::Fixed(const float fPvalue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fPvalue = roundf(fPvalue * (1 << _bits));
}

int	Fixed::getRawBits(void) const {
	return this->_fPvalue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fPvalue = raw;
}

float	Fixed::toFloat(void) const {
	return (float)(_fPvalue) / (1 << _bits);
}

int	Fixed::toInt(void) const {
	return _fPvalue >> _bits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed) {
	o << fixed.toFloat();
	return o;
}
