#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        mGrade = bureaucrat.mGrade;
    }

    return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : mName(name)
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    mGrade = grade;
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
    if (mGrade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }

    mGrade++;
}

void Bureaucrat::decreaseGrade()
{
    if (mGrade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    mGrade--;
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