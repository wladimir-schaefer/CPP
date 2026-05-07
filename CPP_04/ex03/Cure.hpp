#ifndef Cure_HPP
# define Cure_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
protected:
	std::string const type;

public:
	Cure(std::string const & type);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	Cure clone();
	void use(ICharacter&);
};

#endif