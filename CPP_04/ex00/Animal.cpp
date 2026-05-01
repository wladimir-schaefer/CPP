#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal &other): type(other.type) {}

Animal &Animal::operator=(const Animal &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal(){}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	return ;
}