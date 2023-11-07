#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

Intern::Intern()
{
    initFormCreators();
}

Intern::~Intern() {}

Intern::Intern(Intern const &intern)
{
    *this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
    if (this != &intern)
    {
        mFormCreators = intern.mFormCreators;
    }

    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::map< std::string, FormCreator >::iterator it = mFormCreators.find(formName);

    if (it == mFormCreators.end())
    {
        std::cerr << "Form " << formName << " not found" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << formName << std::endl;

    return (this->*(it->second))(target);
}

AForm *Intern::makeShruberryCreationForm(const std::string &target)
{
    return new ShruberryCreationForm(target);
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
    mFormCreators.insert(std::make_pair(std::string("shruberry creation"), &Intern::makeShruberryCreationForm));
    mFormCreators.insert(std::make_pair(std::string("robotomy request"), &Intern::makeRobotomyRequestForm));
    mFormCreators.insert(std::make_pair(std::string("presidential pardon"), &Intern::makePresidentialPardonForm));
}