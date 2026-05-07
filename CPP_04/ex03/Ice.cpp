#include "Ice.hpp"

Ice::Ice(std::string const & type) : type("ice") {}
Ice::Ice(const Ice &other) {}
Ice &Ice::operator=(const Ice &other) {}
Ice::~Ice() {}

Ice *Ice::clone() const {
	return (new Ice)
}

void Ice::use(ICharacter& charater){
	std::cout << "* shoots an ice bolt at " << 
	charater.getName() << " *" << std::endl;
}
