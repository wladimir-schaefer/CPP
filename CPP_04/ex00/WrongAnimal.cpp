#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal's sound" << std::endl;
	return ;
}