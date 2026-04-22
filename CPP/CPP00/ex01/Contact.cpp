#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""){}
Contact::~Contact(){};

void	Contact::set_firstName(const std::string& name) {
	this->_firstName = name;
}

std::string Contact::get_firstName(void) const {
	return (this->_firstName);
}

void	Contact::set_lastName(const std::string& lname) {
	this->_lastName = lname;
}

std::string Contact::get_lastName(void) const {
	return (this->_lastName);
}

void	Contact::set_nickName(const std::string& nick) {
	this->_nickName = nick;
}

std::string Contact::get_nickName(void) const {
	return (this->_nickName);
}

void	Contact::set_phoneNumber(const std::string& number) {
	 this->_phoneNumber = number;
}

std::string Contact::get_phoneNumber(void) const {
	return (this->_phoneNumber);
}

void	Contact::set_darkestSecret(const std::string& secret) {
	this->_darkestSecret = secret;
}

std::string Contact::get_darkestSecret(void) const {
	return (this->_darkestSecret);
}

