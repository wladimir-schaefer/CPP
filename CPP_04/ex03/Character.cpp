#include "Character.hpp"

Character::Character(std::string const & name) : name(name), floorCount(0)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		this->floor[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	name = other.name;
	floorCount = other.floorCount;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (other.floor[i])
			floor[i] = other.floor[i]->clone();
		else
			floor[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		floorCount = other.floorCount;

		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];

			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
		{
			delete floor[i];

			if (other.floor[i])
				floor[i] = other.floor[i]->clone();
			else
				floor[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (int i = 0; i < floorCount; i++)
	{
		if (floor[i])
			delete floor[i];
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		floor[floorCount++] = inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
