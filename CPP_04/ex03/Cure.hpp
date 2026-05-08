#ifndef Cure_HPP
# define Cure_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif