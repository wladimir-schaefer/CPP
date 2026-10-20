#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "--- Testing unequip ---" << std::endl;
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "--- Testing unknown materia ---" << std::endl;
	tmp = src->createMateria("fire");
	if (tmp)
		me->equip(tmp);
	else
		std::cout << "Unknown materia type, not equipped." << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}