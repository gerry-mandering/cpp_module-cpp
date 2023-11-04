#include "Bureaucrat.hpp"

int main(void) {

    // Normal Case
    try {
        Bureaucrat bureaucrat("Bureaucrat", 20);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // GradeTooLowException while constructing
    try {
        Bureaucrat bureaucrat("Bureaucrat", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // GradeTooHighException
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}