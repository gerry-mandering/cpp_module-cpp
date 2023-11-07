#include "AForm.hpp"

AForm::AForm() : mName(std::string()), mIsSigned(false), mRequiredGradeToSign(0), mRequiredGradeToExecute(0) {}

AForm::~AForm() {}

AForm::AForm(const AForm &aForm)
    : mName(aForm.mName), mRequiredGradeToSign(aForm.mRequiredGradeToSign),
      mRequiredGradeToExecute(aForm.mRequiredGradeToExecute)
{
    *this = aForm;
}

AForm &AForm::operator=(const AForm &aForm)
{
    if (this != &aForm)
    {
        mIsSigned = aForm.mIsSigned;
    }

    return *this;
}

AForm::AForm(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute)
    : mName(name), mIsSigned(false), mRequiredGradeToSign(requiredGradeToSign),
      mRequiredGradeToExecute(requiredGradeToExecute)
{
    if (mRequiredGradeToSign < 1 || mRequiredGradeToExecute < 1)
    {
        throw AForm::GradeTooHighException();
    }
    else if (mRequiredGradeToSign > 150 || mRequiredGradeToExecute > 150)
    {
        throw AForm::GradeTooLowException();
    }
}

const std::string &AForm::getName() const
{
    return mName;
}

const bool &AForm::getIsSigned() const
{
    return mIsSigned;
}

const int &AForm::getRequiredGradeToSign() const
{
    return mRequiredGradeToSign;
}

const int &AForm::getRequiredGradeToExecute() const
{
    return mRequiredGradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > mRequiredGradeToSign)
    {
        throw AForm::GradeTooLowException();
    }

    mIsSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (mIsSigned == false)
    {
        throw AForm::FormIsNotSignedException();
    }

    if (executor.getGrade() > mRequiredGradeToExecute)
    {
        throw AForm::GradeTooLowException();
    }

    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &output, const AForm &aForm)
{
    output << aForm.getName() << ", IsSigned: " << (aForm.getIsSigned() ? "true" : "false")
           << ", RequiredGradeToSign: " << aForm.getRequiredGradeToSign()
           << ", RequiredGradeToExecute: " << aForm.getRequiredGradeToExecute();
    return output;
}