#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat says: Mew" << std::endl;
}