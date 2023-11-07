#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{

  public:
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

  public:
    Bureaucrat(const std::string &name, const int grade);

  public:
    const std::string &getName() const;
    const int &getGrade() const;

  public:
    void increaseGrade();
    void decreaseGrade();
    void signForm(AForm &form);
    void executeForm(AForm const &form);

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
    Bureaucrat();

  private:
    const std::string mName;
    int mGrade;
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif