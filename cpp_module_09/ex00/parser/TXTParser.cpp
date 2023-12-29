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
    std::stringstream ss(line);
    std::string date, valueStr;

    std::getline(ss, date, '|');
    std::getline(ss, valueStr);

    date = StringTrimmer::trim(date);
    valueStr = StringTrimmer::trim(valueStr);

    float value = std::strtof(valueStr.c_str(), NULL);
    double price = Database::getInstance()->getExchangeRate(date);

    std::cout << date << " => " << value << " = " << value * price << std::endl;
}
