#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include <map>

class Intern
{

  public:
    Intern();
    ~Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);

  public:
    AForm *makeForm(const std::string &formName, const std::string &target);

  private:
    typedef AForm *(Intern::*FormCreator)(const std::string &target);
    FormCreator mFormCreators[3];
    std::string mFormNames[3];

  private:
    AForm *makeShrubberyCreationForm(const std::string &target);
    AForm *makeRobotomyRequestForm(const std::string &target);
    AForm *makePresidentialPardonForm(const std::string &target);

  private:
    void initFormCreators();
    void initFormNames();
    int getFormCreatorIndex(const std::string &formName);
};

#endif