#include "PhoneBook.hpp"
#include <cstdlib>

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter the command ADD, SEARCH or EXIT\n";
		std::getline(std::cin, command);
		if (!std::cin)
			exit(0);
		if (command == "ADD" || command == "add")
		{
			phonebook.add();
		}
		else if (command == "SEARCH" || command == "search")
		{
			phonebook.search();
		}
		else if (command == "EXIT" || command == "exit")
			break ;
	}
	
}
