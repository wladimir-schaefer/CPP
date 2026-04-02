#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need 1 argument\n";
		return 1;
	}

	Harl harl;

	std::string arg = argv[1];
	harl.complain(arg);

}