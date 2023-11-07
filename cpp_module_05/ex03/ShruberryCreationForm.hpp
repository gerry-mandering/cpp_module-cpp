#ifndef SHRUBERRYCREATIONFORM_H
#define SHRUBERRYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm : public AForm
{
  public:
    ~ShruberryCreationForm();
    ShruberryCreationForm(ShruberryCreationForm const &shruberryCreationForm);
    ShruberryCreationForm &operator=(ShruberryCreationForm const &shruberryCreationForm);

  public:
    ShruberryCreationForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    ShruberryCreationForm();

  private:
    std::string mTarget;
};

#endif