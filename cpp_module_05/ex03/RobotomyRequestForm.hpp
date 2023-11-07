#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
  public:
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);

  public:
    RobotomyRequestForm(const std::string &target);

  public:
    void executeAction() const;

  private:
    RobotomyRequestForm();

  private:
    std::string mTarget;
};

#endif