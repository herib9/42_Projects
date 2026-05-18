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
	if(this != &other)
		this->_fPvalue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fPvalue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fPvalue = raw;
}
