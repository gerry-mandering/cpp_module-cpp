#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);

  public:
    PresidentialPardonForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    PresidentialPardonForm();

  private:
    std::string mTarget;
};

#endif