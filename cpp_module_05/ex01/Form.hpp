#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{

  public:
    ~Form();
    Form(const Form &other);

  public:
    Form(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute);

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
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

  private:
    Form();
    Form &operator=(const Form &other);

  private:
    const std::string mName;
    bool mIsSigned;
    const int mRequiredGradeToSign;
    const int mRequiredGradeToExecute;
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif