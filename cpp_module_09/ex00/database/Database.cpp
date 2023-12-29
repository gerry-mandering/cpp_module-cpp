#include "Database.hpp"

Database *Database::mInstance = NULL;

Database::Database() {}

Database::~Database() {}

Database::Database(const Database &other)
{
    (void)other;
}

Database &Database::operator=(const Database &other)
{
    (void)other;
    return *this;
}

Database *Database::getInstance()
{
    if (mInstance == NULL)
    {
        mInstance = new Database();
        std::atexit(deleteInstance);
    }

    return mInstance;
}

void Database::deleteInstance()
{
    if (mInstance != NULL)
    {
        delete mInstance;
        mInstance = NULL;
    }
}

void Database::addExchangeRate(const std::string &date, double exchangeRate)
{
    mExchangeRates[date] = exchangeRate;
}

double Database::getExchangeRate(const std::string &date) const
{
    std::map< std::string, double >::const_iterator iter = mExchangeRates.upper_bound(date);
    --iter;

    return iter->second;
}
