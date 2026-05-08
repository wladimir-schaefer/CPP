#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other) {
		AAnimal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat says: Mew" << std::endl;
}

Brain* Cat::getBrain() const { return brain; }