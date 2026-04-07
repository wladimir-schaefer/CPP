#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {

	private:
		Contact contact[8];
		int num_of_contacts;
		int oldest;

	public:
		PhoneBook();
		void add();
		void search();
		void displayAllContacts();
		void displayContact(int index);
		std::string format(const std::string &str);
};

#endif