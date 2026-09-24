#pragma once
#include <exception>
#include <iostream>

class	Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat& original);
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat &other);

		std::string getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		class	GradeTooHighException: public std::exception{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException: public std::exception{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& b);

