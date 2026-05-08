#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
protected:
	std::string const type;

public:
	Ice(std::string const & type);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();

	Ice *clone() const;
	void use(ICharacter&);
};

#endif