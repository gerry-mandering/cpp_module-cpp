#include "AForm.hpp"

AForm::AForm()
    : mName(std::string()), mIsSigned(false), mRequiredGradeToSign(150), mRequiredGradeToExecute(150),
      mTarget(std::string())
{
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : mName(other.mName), mRequiredGradeToSign(other.mRequiredGradeToSign),
      mRequiredGradeToExecute(other.mRequiredGradeToExecute)
{
    mIsSigned = other.mIsSigned;
}

AForm &AForm::operator=(const AForm &other)
{
    (void)other;
    return *this;
}

AForm::AForm(const std::string &name, const int requiredGradeToSign, const int requiredGradeToExecute,
             const std::string &target)
    : mName(name), mIsSigned(false), mRequiredGradeToSign(requiredGradeToSign),
      mRequiredGradeToExecute(requiredGradeToExecute), mTarget(target)
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

const std::string &AForm::getTarget() const
{
    return mTarget;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= mRequiredGradeToSign)
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

    if (executor.getGrade() >= mRequiredGradeToExecute)
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

std::ostream &operator<<(std::ostream &output, const AForm &form)
{
    output << form.getName() << ", IsSigned: " << (form.getIsSigned() ? "true" : "false")
           << ", RequiredGradeToSign: " << form.getRequiredGradeToSign()
           << ", RequiredGradeToExecute: " << form.getRequiredGradeToExecute() << ", Target: " << form.getTarget();
    return output;
}