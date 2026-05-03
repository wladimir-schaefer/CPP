#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
}

Cat::Cat(const Cat &other) {
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat(){}

void Cat::makeSound() const {
	std::cout << "Cat says: Mew" << std::endl;
}