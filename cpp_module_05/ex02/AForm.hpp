#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class AForm
{

  public:
    ~AForm();
    AForm(const AForm &aForm);
    AForm &operator=(const AForm &aForm);

  public:
    AForm(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute);

  public:
    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getRequiredGradeToSign() const;
    const int &getRequiredGradeToExecute() const;

  public:
    void beSigned(const Bureaucrat &bureaucrat);

  public:
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

  private:
    AForm();

  private:
    const std::string mName;
    bool mIsSigned;
    const int mRequiredGradeToSign;
    const int mRequiredGradeToExecute;
};

std::ostream &operator<<(std::ostream &output, const AForm &aForm);

#endif