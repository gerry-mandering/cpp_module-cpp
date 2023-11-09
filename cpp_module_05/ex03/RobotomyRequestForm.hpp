#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
  public:
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);

  public:
    RobotomyRequestForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
};

#endif