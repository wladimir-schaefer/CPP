#include "Form.hpp"

Form::Form(): _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150){}

Form::Form(std::string name, bool is_signed,int grade_to_sign, int grade_to_execute)
	: _name(name), _is_signed(is_signed), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
	if (_grade_to_sign < 1)
		throw GradeTooHighException();
	if (_grade_to_sign > 150)
		throw GradeTooLowException();
	if (_grade_to_execute < 1)
		throw GradeTooHighException();
	if (_grade_to_execute > 150)
		throw GradeTooLowException();
	}

Form::Form(const Form& other)
	: _name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute){}
Form::~Form(){}

const std::string& Form::getName() const{
	return _name;
}
int Form::getSigned() const{
	return _is_signed;
}
const int Form::getGradeToSign() const{
	return _grade_to_sign;
}
const int Form::getGradeToExecute () const{
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_is_signed = true;

}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << f.getName() << ": " 
	<< (f.getSigned() ? "signed" : "not signed") << ", "
	<< "Grade To Sign - " << f.getGradeToSign() << ", "
	<< "Grade To Execute - " << f.getGradeToExecute() << " "
	<< std::endl;
	return os;
}
