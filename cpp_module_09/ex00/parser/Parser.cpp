#include "Parser.hpp"

Parser::Parser() {}

Parser::~Parser()
{
    delete mValidator;
}

Parser::Parser(const Parser &other)
{
    (void)other;
}

Parser &Parser::operator=(const Parser &other)
{
    (void)other;
    return *this;
}

Parser::Parser(Validator *validator) : mValidator(validator) {}

void Parser::parse(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::invalid_argument("Cannot open file");
    }

    std::string line;
    std::getline(file, line);
    if (!mValidator->isHeaderValid(line))
    {
        throw std::invalid_argument("Invalid header");
    }

    while (std::getline(file, line))
    {
        // Ignore empty lines and lines starting with '#'
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        if (mValidator->isValid(line))
        {
            processValidLine(line);
        }
    }
}
