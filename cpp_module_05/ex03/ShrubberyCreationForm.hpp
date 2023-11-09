#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  public:
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &other);

  public:
    ShrubberyCreationForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
};

#endif