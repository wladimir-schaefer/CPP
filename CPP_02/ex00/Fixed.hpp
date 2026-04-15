#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

private:
	int _value;
	static const int _fractional_bits;

public:
	Fixed();
	Fixed (const Fixed &obj);
	Fixed &operator=(const Fixed &c);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif