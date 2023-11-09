#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class AForm
{

  public:
    virtual ~AForm();
    AForm(const AForm &other);

  public:
    AForm(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute, const std::string &target);

  public:
    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getRequiredGradeToSign() const;
    const int &getRequiredGradeToExecute() const;
    const std::string &getTarget() const;

  public:
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(const Bureaucrat &executor) const;
    virtual void executeAction() const = 0;

  public:
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
    class FormIsNotSignedException : public std::exception
    {
        const char *what() const throw();
    };

  protected:
    AForm();
    AForm &operator=(const AForm &other);

  private:
    const std::string mName;
    bool mIsSigned;
    const int mRequiredGradeToSign;
    const int mRequiredGradeToExecute;
    std::string mTarget;
};

std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif