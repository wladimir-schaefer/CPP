#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog says: Bark" << std::endl;
}