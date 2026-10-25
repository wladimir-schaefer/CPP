#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

typedef  AForm* (*FormCreator)(const std::string&);

class Intern
{
private:
	static AForm* makeShrubberyCreationForm(const std::string& target);
	static AForm* makeRobotomyRequestForm(const std::string& target);
	static AForm* makePresidentialPardonForm(const std::string& target);
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	AForm* makeForm(const std::string& form, const std::string& target) const;

};

#endif