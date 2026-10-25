#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	void executeAction() const;
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	class FileOpenException : public std::exception {
		public:
			const char* what() const throw();
	};
};

#endif
