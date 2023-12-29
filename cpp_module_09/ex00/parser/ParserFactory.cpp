#include "ParserFactory.hpp"

ParserFactory::ParserFactory() {}

ParserFactory::~ParserFactory() {}

ParserFactory::ParserFactory(const ParserFactory &other)
{
    (void)other;
}

ParserFactory &ParserFactory::operator=(const ParserFactory &other)
{
    (void)other;
    return *this;
}

Parser *ParserFactory::createParser(const std::string &type)
{
    if (type == "csv")
    {
        Validator *csvValidator = new CSVValidator();
        return new CSVParser(csvValidator);
    }
    else if (type == "txt")
    {
        Validator *txtValidator = new TXTValidator();
        return new TXTParser(txtValidator);
    }
    else
    {
        throw std::invalid_argument("Invalid parser type");
    }
}