#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat says: Mew" << std::endl;
}