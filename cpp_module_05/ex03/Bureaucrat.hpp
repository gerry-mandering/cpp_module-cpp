#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{

  public:
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);

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
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

  private:
    Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

  private:
    const std::string mName;
    int mGrade;
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif