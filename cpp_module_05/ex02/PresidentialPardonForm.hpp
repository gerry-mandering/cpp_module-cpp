#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &other);

  public:
    PresidentialPardonForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
};

#endif