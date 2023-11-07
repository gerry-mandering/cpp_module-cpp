#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include <map>

class Intern
{

  public:
    Intern();
    ~Intern();
    Intern(Intern const &intern);
    Intern &operator=(Intern const &intern);

  public:
    AForm *makeForm(const std::string &formName, const std::string &target);

  private:
    typedef AForm *(Intern::*FormCreator)(const std::string &target);
    std::map<std::string, FormCreator> mFormCreators;

  private:
    AForm *makeShruberryCreationForm(const std::string &target);
    AForm *makeRobotomyRequestForm(const std::string &target);
    AForm *makePresidentialPardonForm(const std::string &target);

  private:
    void initFormCreators();
};

#endif