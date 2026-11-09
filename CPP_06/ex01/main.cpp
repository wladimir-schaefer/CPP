#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data		original(42, "serialization", 3.14);
	Data*		originalPtr = &original;

	uintptr_t	raw = Serializer::serialize(originalPtr);
	Data*		restored = Serializer::deserialize(raw);

	std::cout << "original pointer : " << originalPtr << std::endl;
	std::cout << "raw (uintptr_t)  : " << raw << std::endl;
	std::cout << "restored pointer : " << restored << std::endl;

	std::cout << "restored->id     : " << restored->id << std::endl;
	std::cout << "restored->name   : " << restored->name << std::endl;
	std::cout << "restored->value  : " << restored->value << std::endl;

	if (restored == originalPtr)
		std::cout << "OK: restored pointer equals the original" << std::endl;
	else
	{
		std::cout << "KO: pointers differ" << std::endl;
		return 1;
	}
	return 0;
}
