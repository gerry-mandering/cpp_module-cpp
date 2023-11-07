#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : mTarget(std::string()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm)
{
    *this = robotomyRequestForm;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
    if (this != &robotomyRequestForm)
    {
        mTarget = robotomyRequestForm.mTarget;
    }

    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), mTarget(target)
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Brrrrr.. (Loud Drilling Noise) Brrrrr.." << std::endl;

    srand(time(NULL));

    if (rand() % 2 == 0)
    {
        std::cout << mTarget << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << mTarget << " robotomization has failed" << std::endl;
    }
}