#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : mTarget(std::string()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm)
{
    *this = presidentialPardonForm;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
    if (this != &presidentialPardonForm)
    {
        mTarget = presidentialPardonForm.mTarget;
    }

    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), mTarget(target)
{
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << mTarget << " has been pardoned by Zafod Beeblebrox" << std::endl;
}