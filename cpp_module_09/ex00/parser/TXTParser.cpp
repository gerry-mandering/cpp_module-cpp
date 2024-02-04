#include "TXTParser.hpp"

TXTParser::TXTParser() {}

TXTParser::~TXTParser() {}

TXTParser::TXTParser(const TXTParser &other)
{
    (void)other;
}

TXTParser &TXTParser::operator=(const TXTParser &other)
{
    (void)other;
    return *this;
}

TXTParser::TXTParser(Validator *validator) : Parser(validator) {}

void TXTParser::processValidLine(const std::string &line)
{
    std::string::size_type pipePos = line.find('|');

    std::string date = StringTrimmer::trim(line.substr(0, pipePos));
    std::string valueStr = StringTrimmer::trim(line.substr(pipePos + 1));

    float value = std::strtof(valueStr.c_str(), NULL);

    try
    {
        double price = Database::getInstance()->getExchangeRate(date);
        std::cout << date << " => " << value << " = " << value * price << std::endl;
    }
    catch (const Database::InvalidDateException &e)
    {
        std::cerr << "Error: " << e.what() << " => " << date << std::endl;
    }
}
