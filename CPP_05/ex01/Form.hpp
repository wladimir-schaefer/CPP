#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Form{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
	Form& operator=(const Form&);
public:
	Form();
	Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute);
	Form(const Form&);
	~Form();

	const std::string& getName() const;
	int getSigned() const;
	const int getGradeToSign() const;
	const int getGradeToExecute () const;

	void beSigned(const Bureaucrat&);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};	
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif