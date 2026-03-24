#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;
		void announce( void ){
			std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
		}
	public:
		Zombie( void );
		~Zombie ( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif