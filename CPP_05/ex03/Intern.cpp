#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstddef>

Intern::Intern(){}
Intern::Intern(const Intern&){}
Intern& Intern::operator=(const Intern&){
	return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const{

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	FormCreator creators[3] = {Intern::makeShrubberyCreationForm, 
								Intern::makeRobotomyRequestForm,
								Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern couldn't create " << form << ": unknown form" << std::endl;
	return NULL;
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target){
	return new PresidentialPardonForm(target);
}
