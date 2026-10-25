#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw FileOpenException();

	file << "       _-_" << std::endl
	     << "    /~~   ~~\\" << std::endl
	     << " /~~         ~~\\" << std::endl
	     << "{               }" << std::endl
	     << " \\  _-     -_  /" << std::endl
	     << "   ~  \\\\ //  ~" << std::endl
	     << "_- -   | | _- _" << std::endl
	     << "  _ -  | |   -_" << std::endl
	     << "      // \\\\" << std::endl;
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "could not open file";
}
