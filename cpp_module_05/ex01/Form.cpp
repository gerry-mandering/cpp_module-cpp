#include "Form.hpp"

Form::Form() : mName(std::string()), mIsSigned(false), mRequiredGradeToSign(150), mRequiredGradeToExecute(150) {}

Form::~Form() {}

Form::Form(const Form &other)
    : mName(other.mName), mRequiredGradeToSign(other.mRequiredGradeToSign),
      mRequiredGradeToExecute(other.mRequiredGradeToExecute)
{
    mIsSigned = other.mIsSigned;
}

Form &Form::operator=(const Form &other)
{
    (void)other;
    return *this;
}

Form::Form(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute)
    : mName(name), mIsSigned(false), mRequiredGradeToSign(requiredGradeToSign),
      mRequiredGradeToExecute(requiredGradeToExecute)
{
    if (mRequiredGradeToSign < 1 || mRequiredGradeToExecute < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (mRequiredGradeToSign > 150 || mRequiredGradeToExecute > 150)
    {
        throw Form::GradeTooLowException();
    }
}

const std::string &Form::getName() const
{
    return mName;
}

const bool &Form::getIsSigned() const
{
    return mIsSigned;
}

const int &Form::getRequiredGradeToSign() const
{
    return mRequiredGradeToSign;
}

const int &Form::getRequiredGradeToExecute() const
{
    return mRequiredGradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= mRequiredGradeToSign)
    {
        throw Form::GradeTooLowException();
    }

    mIsSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
    output << form.getName() << ", IsSigned: " << (form.getIsSigned() ? "true" : "false")
           << ", RequiredGradeToSign: " << form.getRequiredGradeToSign()
           << ", RequiredGradeToExecute: " << form.getRequiredGradeToExecute();
    return output;
}