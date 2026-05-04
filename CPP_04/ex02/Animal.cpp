#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other): type(other.type) {}

Animal &Animal::operator=(const Animal &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal's sound" << std::endl;
	return ;
}