#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""){
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& original): name (original.name){
	if (this != &original)
		*this = original;
}

Bureaucrat::Bureaucrat& operator (const Bureaucrat &other){
	
}