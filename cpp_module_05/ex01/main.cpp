#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    Bureaucrat bureaucrat("Bureaucrat", 100);
    std::cout << bureaucrat << std::endl;
    std::cout << std::endl;

    // Normal Case
    Form normalForm("Normal Form", 120, 120);
    std::cout << normalForm << std::endl;

    bureaucrat.signForm(normalForm);
    std::cout << std::endl;

    // GradeTooLowException
    Form topLevelForm("Top Level Form", 1, 1);
    std::cout << topLevelForm << std::endl;

    bureaucrat.signForm(topLevelForm);

    return 0;
}