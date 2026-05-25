#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {

}

Fixed::~Fixed() {

}

Fixed::Fixed(const Fixed &other) : _value(other._value) {

}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::Fixed(const int n) {
	_value = n * (1 << _bits);
}

Fixed::Fixed(const float f) {
	_value = roundf(f * (1 << _bits));
}

float Fixed::toFloat(void) const {
	return _value / (float)(1 << _bits);
}

int Fixed::toInt(void) const {
	return _value / (1 << _bits);
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed) {
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed &other) const {
	if(this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const {
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const {
	if(this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const {
	if(this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const {
	if(this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const {
	if(this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++() {
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_value += 1;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_value -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if(a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
