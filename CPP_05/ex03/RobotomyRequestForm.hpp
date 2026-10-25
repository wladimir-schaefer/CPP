#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	void executeAction() const;
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
};

#endif