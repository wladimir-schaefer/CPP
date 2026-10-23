#include "AForm.hpp"

AForm::AForm(): _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150){}

AForm::AForm(std::string name,int grade_to_sign, int grade_to_execute)
	: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
	if (_grade_to_sign < 1)
		throw GradeTooHighException();
	if (_grade_to_sign > 150)
		throw GradeTooLowException();
	if (_grade_to_execute < 1)
		throw GradeTooHighException();
	if (_grade_to_execute > 150)
		throw GradeTooLowException();
	}

AForm::AForm(const AForm& other)
	: _name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute){}
AForm::~AForm(){}

const std::string& AForm::getName() const{
	return _name;
}
bool AForm::getSigned() const{
	return _is_signed;
}
int AForm::getGradeToSign() const{
	return _grade_to_sign;
}
int AForm::getGradeToExecute () const{
	return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << f.getName() << ": " 
	<< (f.getSigned() ? "signed" : "not signed") << ", "
	<< "grade to sign - " << f.getGradeToSign() << ", "
	<< "grade to execute - " << f.getGradeToExecute();
	return os;
}
