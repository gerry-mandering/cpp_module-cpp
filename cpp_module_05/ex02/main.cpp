#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

int main(void)
{

    // Top level bureaucrat
    Bureaucrat topLevelBureaucrat("Top Level Bureaucrat", 1);
    std::cout << topLevelBureaucrat << std::endl;
    std::cout << std::endl;

    AForm *shruberryCreationFormA = new ShruberryCreationForm("Cluster");
    AForm *robotomyRequestFormA = new RobotomyRequestForm("AlphaGO");
    AForm *presidentialPardonFormA = new PresidentialPardonForm("Innocent Hitchhiker");

    AForm *formsA[] = {shruberryCreationFormA, robotomyRequestFormA, presidentialPardonFormA};

    for (int i = 0; i < 3; i++)
    {
        topLevelBureaucrat.signForm(*formsA[i]);
        topLevelBureaucrat.executeForm(*formsA[i]);
        std::cout << std::endl;
        delete formsA[i];
    }

    // Low level bureaucrat
    Bureaucrat lowLevelBureaucrat("Low Level Bureaucrat", 150);
    std::cout << lowLevelBureaucrat << std::endl;
    std::cout << std::endl;

    AForm *shruberryCreationFormB = new ShruberryCreationForm("Cluster");
    AForm *robotomyRequestFormB = new RobotomyRequestForm("AlphaGO");
    AForm *presidentialPardonFormB = new PresidentialPardonForm("Innocent Hitchhiker");

    AForm *formsB[] = {shruberryCreationFormB, robotomyRequestFormB, presidentialPardonFormB};

    for (int i = 0; i < 3; i++)
    {
        lowLevelBureaucrat.signForm(*formsB[i]);
        lowLevelBureaucrat.executeForm(*formsB[i]);
        std::cout << std::endl;
        delete formsB[i];
    }

    return 0;
}