#include "CSVParser.hpp"

CSVParser::CSVParser() {}

CSVParser::~CSVParser() {}

CSVParser::CSVParser(const CSVParser &other)
{
    (void)other;
}

CSVParser &CSVParser::operator=(const CSVParser &other)
{
    (void)other;
    return *this;
}

CSVParser::CSVParser(Validator *validator) : Parser(validator) {}

void CSVParser::processValidLine(const std::string &line)
{
    std::string::size_type commaPos = line.find(',');

    std::string date = StringTrimmer::trim(line.substr(0, commaPos));
    std::string exchangeRateStr = StringTrimmer::trim(line.substr(commaPos + 1));

    double exchangeRate = std::strtod(exchangeRateStr.c_str(), NULL);

    Database::getInstance()->addExchangeRate(date, exchangeRate);
}