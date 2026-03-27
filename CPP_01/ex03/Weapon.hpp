#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

	private:
		std::string name;

	public:
		Zombie(std::string name);
		~Zombie ( void );
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif