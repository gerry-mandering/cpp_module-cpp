#include "Form.hpp"

Form::Form() : mName(std::string()), mIsSigned(false), mRequiredGradeToSign(0), mRequiredGradeToExecute(0) {}

Form::~Form() {}

Form::Form(const Form &form)
    : mName(form.mName), mRequiredGradeToSign(form.mRequiredGradeToSign),
      mRequiredGradeToExecute(form.mRequiredGradeToExecute)
{
    *this = form;
}

Form &Form::operator=(const Form &form)
{
    if (this != &form)
    {
        mIsSigned = form.mIsSigned;
    }

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
    if (bureaucrat.getGrade() > mRequiredGradeToSign)
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
    output << form.getName() << " form, IsSigned: " << form.getIsSigned()
           << ", RequiredGradeToSign: " << form.getRequiredGradeToSign()
           << ", RequiredGradeToExecute: " << form.getRequiredGradeToExecute();
    return output;
}