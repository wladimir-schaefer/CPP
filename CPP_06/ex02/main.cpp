#include <cstdlib>
#include <ctime>
#include <iostream>
#include "identify.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 8; i++)
	{
		Base *obj = generate();
		std::cout << "  identify(Base*): ";
		identify(obj);
		std::cout << "  identify(Base&): ";
		identify(*obj);
		delete obj;
	}
	std::cout << "Plain Base object:" << std::endl;
	Base base;
	identify(&base);
	identify(base);
	return 0;
}
