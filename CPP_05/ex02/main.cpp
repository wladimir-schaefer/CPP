#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// grade high enough: signing succeeds
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
		alice.signForm(contract);
		std::cout << contract;
	}

	std::cout << std::endl << std::endl;
	
	// grade too low: signing fails, form stays unsigned
	{
		Bureaucrat bob("Bob", 100);
		std::cout << bob << std::endl;
		Form permit("Permit", 50, 25);
		std::cout << permit << std::endl;
		bob.signForm(permit);
		std::cout << permit;
	}

	std::cout << std::endl << std::endl;

	// grade exactly equal to the required one: signing succeeds
	{
		Bureaucrat carol("Carol", 50);
		std::cout << carol << std::endl;
		Form lease("Lease", 50, 25);
		std::cout << lease << std::endl;
		carol.signForm(lease);
		std::cout << lease;
	}

	std::cout << std::endl << std::endl;

	// attempt to sign bad form
	try {
	Form bad("Bad", 0, 25);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
