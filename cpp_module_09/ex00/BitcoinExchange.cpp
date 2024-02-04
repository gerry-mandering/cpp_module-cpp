#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

// Used by the Builder
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        mDataFileName = other.mDataFileName;
        mInputFileName = other.mInputFileName;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &dataFileName, const std::string &inputFileName)
    : mDataFileName(dataFileName), mInputFileName(inputFileName)
{
}

void BitcoinExchange::run()
{
    try
    {
        // Parse data.csv and store in database
        Parser *dataParser = ParserFactory::createParser("csv");
        dataParser->parse(mDataFileName);
        delete dataParser;

        // Parse input.txt and calculate exchange rate
        Parser *inputParser = ParserFactory::createParser("txt");
        inputParser->parse(mInputFileName);
        delete inputParser;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

BitcoinExchange::Builder::Builder() {}

BitcoinExchange::Builder::~Builder() {}

BitcoinExchange::Builder::Builder(const Builder &other)
{
    (void)other;
}

BitcoinExchange::Builder &BitcoinExchange::Builder::operator=(const Builder &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::Builder &BitcoinExchange::Builder::setDataFileName(const std::string &dataFileName)
{
    mDataFileName = dataFileName;
    return *this;
}

BitcoinExchange::Builder &BitcoinExchange::Builder::setInputFileName(const std::string &inputFileName)
{
    mInputFileName = inputFileName;
    return *this;
}

BitcoinExchange BitcoinExchange::Builder::build()
{
    return BitcoinExchange(mDataFileName, mInputFileName);
}