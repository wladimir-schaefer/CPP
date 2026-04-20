#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed():_value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const int_value){
	std::cout << "Int constructor called" << std::endl;
	_value = int_value << _fractional_bits;
}

Fixed::Fixed(float const float_value){
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(float_value * (1 << _fractional_bits));
}

Fixed::Fixed (const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return _value;
}

void Fixed::setRawBits( int const raw ){
	_value  = raw;
}

float Fixed::toFloat( void ) const{
	return (float)_value / (1 << _fractional_bits);
}

int Fixed::toInt( void ) const{
	return _value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}