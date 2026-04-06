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
		void add(  );
		void search();

};

#endif