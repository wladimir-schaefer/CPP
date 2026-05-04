#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog says: Bark" << std::endl;
}

Brain* Dog::getBrain() const { return brain; }