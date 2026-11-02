#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>
#include <iostream>
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter&){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&){return *this;}
ScalarConverter::~ScalarConverter(){}

enum e_type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID};

bool isPseudo(const std::string& str){
	static const char* arr[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	const int count = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < count; i++){
		if (str == arr[i])
			return true;
	}
	return false;
}

bool isChar(const std::string& str){
	if (str.length() != 1)
		return false;
	unsigned char c = static_cast<unsigned char>(str[0]);
	if (!std::isprint(c))
		return false;
	if (std::isdigit(c))
		return false;
	return true;
}

bool isInt(const std::string& str){
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return false;
	for (; i < str.length(); i++){
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool isDouble(const std::string& str){
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	size_t start = i;
	while (i < str.length() && std::isdigit(static_cast<unsigned char>(str[i])))
		i++;
	if (i == start || i == str.length() || str[i] != '.')
		return false;
	i++;
	start = i;
	while (i < str.length() && std::isdigit(static_cast<unsigned char>(str[i])))
		i++;
	if (i == start || i != str.length())
		return false;
	return true;
}

bool isFloat(const std::string& str){
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
	return isDouble(str.substr(0, str.length() - 1));
}

e_type detectType(const std::string& str){
	if (str.empty())
		return INVALID;
	if (isPseudo(str))
		return PSEUDO;
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isDouble(str))
		return DOUBLE;
	return INVALID;
}

std::string formatNumber(double d){
	std::ostringstream os;
	if (d == std::floor(d))
		os << std::fixed << std::setprecision(1);
	os << d;
	return os.str();
}

void printChar(double d){
	std::cout << "char: ";
	if (d != d || d < 0 || d > 127)
		std::cout << "impossible";
	else {
		char c = static_cast<char>(d);
		if (!std::isprint(c))
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";
	}
	std::cout << std::endl;
}

void printInt(double d){
	std::cout << "int: ";
	if (d != d || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
}

void printFloat(double d){
	std::cout << "float: ";
	if (d != d)
		std::cout << "nanf";
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "+inff";
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inff";
	else if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "impossible";
	else
		std::cout << formatNumber(static_cast<double>(static_cast<float>(d))) << "f";
	std::cout << std::endl;
}

void printDouble(double d){
	std::cout << "double: ";
	if (d != d)
		std::cout << "nan";
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "+inf";
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inf";
	else
		std::cout << formatNumber(d);
	std::cout << std::endl;
}

void fromChar(const std::string& str){
	char c = str[0];
	printChar(static_cast<double>(c));
	printInt(static_cast<double>(c));
	printFloat(static_cast<double>(static_cast<float>(c)));
	printDouble(static_cast<double>(c));
}

void fromDouble(const std::string& str){
	double d = std::strtod(str.c_str(), NULL);
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

void fromInt(const std::string& str){
	errno = 0;
	long l = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || l < INT_MIN || l > INT_MAX){
		fromDouble(str);
		return;
	}
	int i = static_cast<int>(l);
	printChar(static_cast<double>(i));
	printInt(static_cast<double>(i));
	printFloat(static_cast<double>(static_cast<float>(i)));
	printDouble(static_cast<double>(i));
}

void fromFloat(const std::string& str){
	double d = std::strtod(str.c_str(), NULL);
	if (d > FLT_MAX || d < -FLT_MAX){
		fromDouble(str.substr(0, str.length() - 1));
		return;
	}
	float f = static_cast<float>(d);
	printChar(static_cast<double>(f));
	printInt(static_cast<double>(f));
	printFloat(static_cast<double>(f));
	printDouble(static_cast<double>(f));
}

void fromPseudo(const std::string& str){
	double d;
	if (str[0] == 'n')
		d = std::numeric_limits<double>::quiet_NaN();
	else if (str[0] == '-')
		d = -std::numeric_limits<double>::infinity();
	else
		d = std::numeric_limits<double>::infinity();
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

void ScalarConverter::convert(const std::string& literal){
	switch (detectType(literal)){
		case CHAR:   fromChar(literal);   break;
		case INT:    fromInt(literal);    break;
		case FLOAT:  fromFloat(literal);  break;
		case DOUBLE: fromDouble(literal); break;
		case PSEUDO: fromPseudo(literal); break;
		case INVALID:
			std::cout << "char: impossible" << std::endl
					  << "int: impossible" << std::endl
					  << "float: impossible" << std::endl
					  << "double: impossible" << std::endl;
			break;
	}
}