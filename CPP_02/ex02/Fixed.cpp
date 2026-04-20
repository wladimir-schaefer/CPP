#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed():_value(0){
	// std::cout << "Default constructor called" << std::endl;
	// _value = 0;
}

Fixed::Fixed(int const int_value){
	// std::cout << "Int constructor called" << std::endl;
	_value = int_value << _fractional_bits;
}

Fixed::Fixed(float const float_value){
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(float_value * (1 << _fractional_bits));
}

Fixed::Fixed (const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other){
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
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

// comparison operators
bool Fixed::operator>(const Fixed &other) const{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const{
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const{
	return _value != other._value;
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const{
	Fixed res;
	res.setRawBits(_value + rhs.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &rhs) const{
	Fixed res;
	res.setRawBits(_value - rhs.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed res;
	res.setRawBits((_value * rhs.getRawBits()) >> _fractional_bits);
	return res;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed res;
	res.setRawBits((_value << _fractional_bits) / rhs.getRawBits());
	return res;
}

// increment/decrement operators
Fixed &Fixed::operator++( void ){
	_value++;
	return *this;
}

Fixed Fixed::operator++( int ){
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed &Fixed::operator--( void ) {
	_value--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return (a > b) ? a : b;
}