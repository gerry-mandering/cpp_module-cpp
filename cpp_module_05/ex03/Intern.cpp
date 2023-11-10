#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    initFormCreators();
    initFormNames();
}

Intern::~Intern() {}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            mFormCreators[i] = other.mFormCreators[i];
            mFormNames[i] = other.mFormNames[i];
        }
    }

    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    int formCreatorIndex = getFormCreatorIndex(formName);

    if (formCreatorIndex == -1)
    {
        std::cout << "Form " << formName << " not found" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << formName << std::endl;

    return (this->*mFormCreators[formCreatorIndex])(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

void Intern::initFormCreators()
{
    mFormCreators[0] = &Intern::makeShrubberyCreationForm;
    mFormCreators[1] = &Intern::makeRobotomyRequestForm;
    mFormCreators[2] = &Intern::makePresidentialPardonForm;
}

void Intern::initFormNames() {
    mFormNames[0] = "shrubbery creation";
    mFormNames[1] = "robotomy request";
    mFormNames[2] = "presidential pardon";
}

int Intern::getFormCreatorIndex(const std::string &formName)
{
    for (int i = 0; i < 3; i++)
    {
        if (mFormNames[i] == formName)
        {
            return i;
        }
    }

    return -1;
}