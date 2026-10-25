#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	std::srand(std::time(NULL));

	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	// every known form name: intern creates it, boss signs and executes it
	{
		const char* names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		for (int i = 0; i < 3; ++i) {
			AForm* form = someRandomIntern.makeForm(names[i], "Bender");
			if (form) {
				std::cout << *form << std::endl;
				boss.signForm(*form);
				boss.executeForm(*form);
				delete form;
			}
			std::cout << std::endl;
		}
	}

	// unknown form name: intern prints an error and returns NULL
	{
		AForm* form = someRandomIntern.makeForm("coffee request", "Boss");
		if (!form)
			std::cout << "makeForm returned NULL" << std::endl;
	}

	return 0;
}
