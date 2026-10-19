#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat&);
	Bureaucrat& operator=(Bureaucrat&);
	~Bureaucrat();

	std::string getName();
	int getGrade();

	std::exception GradeTooHighException;
	std::exception GradeTooLowException;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);
Bureaucrat::GradeTooHighException;
Bureaucrat::GradeTooLowException;

#endif