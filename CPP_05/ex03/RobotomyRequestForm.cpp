#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeAction() const {
	std::cout << "* BZZZZZZZ... DRRRRRRR... BZZZT *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
}