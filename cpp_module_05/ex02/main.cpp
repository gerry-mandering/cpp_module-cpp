#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    // Normal Case
    Bureaucrat bureaucratA("BureaucratA", 1);
    std::cout << bureaucratA << std::endl;

    Form formA("formA", 1, 1);
    std::cout << formA << std::endl;

    bureaucratA.signForm(formA);

    // GradeTooLowException
    Bureaucrat bureaucratB("BureaucratB", 150);
    std::cout << bureaucratB << std::endl;

    Form formB("formB", 1, 1);
    std::cout << formB << std::endl;

    bureaucratB.signForm(formB);

    return 0;
}