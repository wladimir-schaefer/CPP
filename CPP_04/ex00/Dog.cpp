#include "Dog.hpp"

Dog::Dog(): type("Dog") {}

Dog::Dog(const Dog &other): type(other.type) {}

Dog &Dog::operator=(const Dog &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog(){}

void Dog::makeSound(){
	std::cout << "Dog says: Bark" << std::endl;
}