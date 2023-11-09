#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    Intern newIntern;

    AForm *formA;
    formA = newIntern.makeForm("robotomy request", "Bender");
    if (formA != NULL) {
        std::cout << *formA << std::endl;
        std::cout << std::endl;
        delete formA;
    }

    AForm *formB;
    formB = newIntern.makeForm("random doodle", "hmm..");
    if (formB != NULL) {
        std::cout << *formB << std::endl;
        std::cout << std::endl;
        delete formB;
    }

    return 0;
}