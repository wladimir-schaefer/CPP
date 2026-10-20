#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat ok("Alice", 2);
		std::cout << ok;
		ok.incrementGrade();
		std::cout << ok;
		ok.incrementGrade();
		std::cout << ok;
	}
	catch (Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat bad_h("Bob", 0);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} 

	try {
		Bureaucrat bad_l("Bob", 151);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
