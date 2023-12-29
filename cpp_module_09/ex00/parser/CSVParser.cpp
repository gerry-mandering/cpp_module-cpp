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
    std::stringstream ss(line);
    std::string date, exchangeRateStr;

    std::getline(ss, date, ',');
    std::getline(ss, exchangeRateStr);

    date = StringTrimmer::trim(date);
    exchangeRateStr = StringTrimmer::trim(exchangeRateStr);

    double exchangeRate = std::strtod(exchangeRateStr.c_str(), NULL);

    Database::getInstance()->addExchangeRate(date, exchangeRate);
}