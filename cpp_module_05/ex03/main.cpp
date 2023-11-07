#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    Intern newIntern;

    AForm *formA;
    formA = newIntern.makeForm("robotomy request", "Bender");

    AForm *formB;
    formB = newIntern.makeForm("random doodle", "hmm..");

    return 0;
}