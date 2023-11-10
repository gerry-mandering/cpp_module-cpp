#include "Bureaucrat.hpp"

int main(void) {

    // Normal Case
    try {
        Bureaucrat normalBureaucrat("Normal Bureaucrat", 50);
        std::cout << normalBureaucrat << std::endl;
        normalBureaucrat.decreaseGrade();
        std::cout << normalBureaucrat << std::endl;
        normalBureaucrat.increaseGrade();
        std::cout << normalBureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // GradeTooLowException while constructing
    try {
        Bureaucrat weirdBureaucrat("Weird Bureaucrat", 151);
        std::cout << weirdBureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // GradeTooHighException
    try {
        Bureaucrat topLevelBureaucrat("Top Level Bureaucrat", 1);
        std::cout << topLevelBureaucrat << std::endl;
        topLevelBureaucrat.increaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}