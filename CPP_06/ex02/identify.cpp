#include <cstdlib>
#include <exception>
#include <iostream>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Generated: A" << std::endl;
		return new A();
	case 1:
		std::cout << "Generated: B" << std::endl;
		return new B();
	default:
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

// Pointer version: dynamic_cast returns NULL on failure.
void identify(Base *p)
{
	if (!p)
		std::cout << "null pointer" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

// Reference version: dynamic_cast throws std::bad_cast on failure
// (caught as std::exception, so <typeinfo> is not needed).
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &) {}
	std::cout << "unknown" << std::endl;
}
