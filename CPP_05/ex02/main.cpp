#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(std::time(NULL));

	// grade high enough: every form gets signed and executed
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << shrub << std::endl << robot << std::endl << pardon << std::endl;
		boss.signForm(shrub);
		boss.executeForm(shrub);
		boss.signForm(robot);
		boss.executeForm(robot);
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}

	std::cout << std::endl << std::endl;

	// form not signed: execution fails
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		boss.executeForm(pardon);
	}

	std::cout << std::endl << std::endl;

	// grade high enough to sign but too low to execute
	{
		Bureaucrat dave("Dave", 50);
		std::cout << dave << std::endl;
		RobotomyRequestForm robot("Marvin");
		dave.signForm(robot);
		dave.executeForm(robot);
	}

	std::cout << std::endl << std::endl;

	// grade too low to sign
	{
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;
		ShrubberyCreationForm shrub("garden");
		intern.signForm(shrub);
		intern.executeForm(shrub);
	}

	std::cout << std::endl << std::endl;

	// robotomy several times to see the 50% chance
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Zaphod");
		boss.signForm(robot);
		for (int i = 0; i < 5; ++i)
			boss.executeForm(robot);
	}

	std::cout << std::endl << std::endl;

	// forms used through an AForm pointer
	{
		Bureaucrat boss("Boss", 1);
		AForm* form = new PresidentialPardonForm("Trillian");
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	return 0;
}
