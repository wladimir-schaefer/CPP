#include <string>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(){
	num_of_contacts = 0;
	oldest = 0;
}

void PhoneBook::add(){
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << "Enter the first name\n";
		std::getline(std::cin, first_name);
		if (!std::cin)
			exit(0);
		if (first_name.empty())
			std::cout << "The field can't be empty\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "Enter the last name\n";
		std::getline(std::cin, last_name);
		if (!std::cin)
			exit(0);
		if (last_name.empty())
			std::cout << "The field can't be empty\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "Enter the nickname\n";
		std::getline(std::cin, nickname);
		if (!std::cin)
			exit(0);
		if (nickname.empty())
			std::cout << "The field can't be empty\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "Enter the phone number\n";
		std::getline(std::cin, phone_number);
		if (!std::cin)
			exit(0);
		if (phone_number.empty())
			std::cout << "The field can't be empty\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "Enter the darkest secret\n";
		std::getline(std::cin, darkest_secret);
		if (!std::cin)
			exit(0);
		if (darkest_secret.empty())
			std::cout << "The field can't be empty\n";
		else
			break ;
	}

	int index_to_add;

	if (num_of_contacts < 8)
	{
		index_to_add = num_of_contacts;
		num_of_contacts++;
	}
	else
	{
		index_to_add = oldest;
		oldest = (oldest + 1) % 7;
	}

	contact[index_to_add].setContact(first_name, last_name, nickname, phone_number, darkest_secret);
	std::cout << "Contact added!\n";
}

void PhoneBook::search(){
	std::string input;
	int index;

	if (num_of_contacts == 0){
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	PhoneBook::displayAllContacts();

	while (1)
	{
		std::cout << "Enter the index of the contact\n";
		std::getline(std::cin, input);
		if (!std::cin)
			exit(0);
		if (input.empty())
		{
			std::cout << "The field can't be empty\n";
		}
		else if (input.length() > 1 || !isdigit(input[0]))
		{
			std::cout << "Index has to be digit in range 0 - 7\n";
		}
		else
		{
			index = atoi(input.c_str());
			if (index >= num_of_contacts)
				std::cout << "There are only " << num_of_contacts
					<< " contact(s)\n";
			else
				break ;
		}
	}
	PhoneBook::displayContact(index);
}

void PhoneBook::displayAllContacts(){

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname"
		<< std::endl;

	for (int i = 0; i < num_of_contacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << format(contact[i].getFirstName()) << "|"
			<< std::setw(10) << format(contact[i].getLastName()) << "|"
			<< std::setw(10) << format(contact[i].getNickname())
			<< std::endl;
	}
}

void PhoneBook::displayContact(int index){
	std::cout << "First name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickame: " << contact[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkes secret: " << contact[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::format(const std::string &str)
{
	if (str.length() > 10)
				return (str.substr(0, 9) + ".");
	else
		return str;
}