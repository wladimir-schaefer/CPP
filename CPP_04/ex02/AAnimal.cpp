#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): type(other.type) {}

AAnimal &AAnimal::operator=(const AAnimal &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}
