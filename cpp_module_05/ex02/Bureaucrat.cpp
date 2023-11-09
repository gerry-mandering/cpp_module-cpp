#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : mName(std::string()), mGrade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : mName(other.mName), mGrade(other.mGrade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    (void)other;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : mName(name), mGrade(grade)
{
    if (mGrade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (mGrade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

const std::string &Bureaucrat::getName() const
{
    return mName;
}

const int &Bureaucrat::getGrade() const
{
    return mGrade;
}

void Bureaucrat::increaseGrade()
{
    if (mGrade == 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }

    mGrade--;
}

void Bureaucrat::decreaseGrade()
{
    if (mGrade == 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    mGrade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << mName << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << mName << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << mName << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << mName << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
    output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

    return output;
}