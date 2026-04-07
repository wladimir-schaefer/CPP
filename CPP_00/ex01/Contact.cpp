#include "Contact.hpp"

void Contact::setContact(std::string first_name, std::string last_name, std::string nickneme, 
	std::string phone_number, std::string darkest_secret){
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickneme;
		this->phone_number = phone_number;
		this->darkest_secret = darkest_secret;
	}
std::string Contact::getFirstName() const {
	return this->first_name;
}
std::string Contact::getLastName() const {
	return this->last_name;
}
std::string Contact::getNickname() const {
	return this->nickname;
}
std::string Contact::getPhoneNumber() const {
	return this->phone_number;
}
std::string Contact::getDarkestSecret() const {
	return this->darkest_secret;
}