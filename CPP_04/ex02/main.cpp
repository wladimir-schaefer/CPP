#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int l = 2;
	const Animal* animals[l];

	for (int i = 0; i < l/2; i++)
		animals[i] = new Dog();
	for (int i = l/2; i < l; i++)
		animals[i] = new Cat();

	for (int i = 0; i < l; i++)
		delete animals[i];
	
	std::cout << std::endl;

	Dog a;
	a.getBrain()->ideas[0] = "Eat";
	Dog b = a;
	Dog c(a);
	a.getBrain()->ideas[0] = "Play";
	std::cout << a.getBrain()->ideas[0] << std::endl;
	std::cout << b.getBrain()->ideas[0] << std::endl;
	std::cout << c.getBrain()->ideas[0] << std::endl;

	return 0;
}