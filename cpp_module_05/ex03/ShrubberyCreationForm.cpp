#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    (void)other;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream writeFile(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

    if (writeFile.is_open() == false)
    {
        throw std::ofstream::failure("could not open file");
    }

    writeFile
        << "                                                                                                           "
           "                                                                                               \n"
        << "                                                                                                           "
           "                                                                                               \n"
        << "                                                                                                           "
           "   ░░░░░░      ░░░░                                                                            \n"
        << "                                                                                                          "
           "░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒░░                                                                            \n"
        << "                                                                                ░░    ░░░░░░              "
           "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                                        \n"
        << "                                                                        ░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░      "
           "░░░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░                                                                      \n"
        << "                                                                    "
           "░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                     "
           "                           \n"
        << "                                                                  "
           "░░░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒░░                               "
           "                             \n"
        << "                                                                "
           "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░                       "
           "                               \n"
        << "                                                                "
           "░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░                     "
           "                               \n"
        << "                                                        "
           "░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒░░             "
           "                                       \n"
        << "                                                        "
           "▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒░░░░         "
           "                                       \n"
        << "                                                    "
           "░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒░░     "
           "                                           \n"
        << "                                                  "
           "▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓████▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░   "
           "                                             \n"
        << "                                              "
           "░░░░▒▒▒▒▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓████████▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒"
           "▒                                                \n"
        << "                                            "
           "░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒"
           "▒▒▒▒▒                                              \n"
        << "                                          "
           "░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓██▓"
           "▓▓▓▓▓▒▒                                              \n"
        << "                                          "
           "░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓"
           "▓▓▓▒▒░░                                              \n"
        << "                                            "
           "▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒"
           "▒▒▒▒▒                                              \n"
        << "                                          "
           "░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓"
           "▓▓▓▒▒▒▒░░                                            \n"
        << "                                            "
           "▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓██▓▓▓▓████▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓"
           "▓▒▒▒▒▒▒░░                                          \n"
        << "                                          "
           "▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓██████████▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓██▓▓▓▓████▓▓▒▒▒▒▓▓░░▓▓▓▓██▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓"
           "▓▓▓▒▒▒▒▓▓▒▒░░                                        \n"
        << "                                          "
           "░░░░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓"
           "▓▓▓▓▓▓▓▒▒▒▒░░                                        \n"
        << "                                      "
           "░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓"
           "▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░                                    \n"
        << "                                    "
           "░░▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓██▓▓██▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓"
           "▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒░░                                    \n"
        << "                                    "
           "▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒"
           "▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒░░                                      \n"
        << "                                    "
           "▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓"
           "▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▒▒░░                                  \n"
        << "                                    "
           "▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒"
           "▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░░░                            \n"
        << "                                    "
           "▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓"
           "▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                              \n"
        << "                          "
           "░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓████████▓▓██▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓▓▓▒▒▓▓██▓▓▓▓▓"
           "▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒                                \n"
        << "                        "
           "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓████████████▓▓▓▓██████▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓"
           "▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▒▒▓▓▒▒▒▒▒▒░░                        \n"
        << "                      "
           "░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓████▓▓████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓"
           "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒                        \n"
        << "                      "
           "░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓"
           "▓██▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓░░                        \n"
        << "                      "
           "░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓"
           "▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓░░                        \n"
        << "                        "
           "▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓"
           "▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒░░                      \n"
        << "                      ░░▒▒▒▒  "
           "░░▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓████████▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒████▓▓▓▓▓▓▓▓▓"
           "▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓██▓▓▒▒░░                      \n"
        << "                                "
           "▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▓▓████▓▓▓▓▓▓███"
           "█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒                        \n"
        << "                                "
           "▓▓▓▓▓▓▒▒▒▒▒▒░░░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒░░▓▓▒▒▒▒▓▓▒▒▓▓▓▓██▓▓▓▓██▓▓░░░░██▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓  "
           "▒▒▒▒░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒                            \n"
        << "                                ░░      ▒▒░░  ░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒  ░░▒▒████▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒  "
           "░░▒▒▓▓▓▓░░▒▒██▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓      ░░░░░░░░░░▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒                         "
           "   \n"
        << "                                      ░░▒▒░░    ░░▒▒░░    ░░▓▓▒▒░░▒▒▓▓██▓▓▓▓▒▒░░██▒▒▒▒▓▓▓▓▓▓  "
           "░░▓▓▓▓░░▓▓██▒▒▒▒░░▓▓░░  ░░▓▓▒▒          ░░░░    ▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒                           "
           " \n"
        << "                                                                ░░▓▓▓▓▓▓▓▓▒▒░░░░░░▒▒    ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ "
           "   ▒▒▒▒      ░░              ▒▒░░▒▒▒▒▓▓██▓▓▒▒▓▓▒▒▓▓░░▓▓▓▓▓▓▓▓▒▒▒▒░░                            \n"
        << "                                                                      ░░░░▒▒                ░░▓▓▓▓▓▓▓▓▓▓░░ "
           "   ▓▓                        ░░▒▒░░▒▒████░░░░░░▒▒▒▒▓▓░░  ▒▒▒▒▒▒░░                              \n"
        << "                                                                        ░░░░                    ▓▓▓▓▓▓▓▓   "
           " ▓▓▒▒                        ▒▒▓▓▒▒▓▓▒▒▓▓        ▒▒▒▒░░                                        \n"
        << "                                                                                                  "
           "▓▓▓▓▓▓░░▓▓▒▒                            ▓▓░░▒▒░░░░          ░░                                          \n"
        << "                                                                                                  "
           "▓▓▓▓▓▓▒▒░░                                                                                              \n"
        << "                                                                                                  ▓▓▓▓▓▓▒▒ "
           "                                                                                               \n"
        << "                                                                                                  ▓▓▓▓▓▓░░ "
           "                                                                                               \n"
        << "                                                                                                  ▓▓▓▓▓▓░░ "
           "                                                                                               \n"
        << "                                                                                                  ▓▓▒▒▓▓▒▒ "
           "                                                                                               \n"
        << "                                                                                                  ▓▓▓▓▓▓▒▒ "
           "                                                                                               \n"
        << "                                                                                                  ▓▓▓▓▓▓▓▓ "
           "                                                                                               \n"
        << "                                                                                                  ▒▒▓▓▓▓▓▓ "
           "                                                                                               \n"
        << "                                                                                                ░░▒▒▓▓▓▓▓▓ "
           "                                                                                               \n"
        << "                                                                                            "
           "░░▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░░░                                                                                       "
           "   \n"
        << "                                                                              "
           "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒▒░░                                                           "
           "                 ";

    writeFile.close();
}