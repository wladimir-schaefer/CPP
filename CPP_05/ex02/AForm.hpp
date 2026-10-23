#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class AForm{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
	AForm();
	AForm& operator=(const AForm&);
public:
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm&);
	virtual ~AForm();

	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute () const;

	void beSigned(const Bureaucrat&);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
