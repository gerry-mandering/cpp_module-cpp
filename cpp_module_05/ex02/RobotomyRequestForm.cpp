#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    (void)other;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Brrrrr.. (Loud Drilling Noise) Brrrrr.." << std::endl;

    if (rand() % 2 == 0)
    {
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << getTarget() << " robotomization has failed" << std::endl;
    }
}