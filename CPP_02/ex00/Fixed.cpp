#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(){
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	_value = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &c){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &c)
		_value = c.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ){
	_value  = raw;
}
