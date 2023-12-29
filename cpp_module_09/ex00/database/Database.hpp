#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <map>
#include <cstddef>
#include <cstdlib>
#include <string>

class Database
{
  private:
    static Database *mInstance;
    std::map< std::string, double > mExchangeRates;

  private:
    Database();
    ~Database();
    Database(const Database &other);
    Database &operator=(const Database &other);

  public:
    static Database *getInstance();
    static void deleteInstance();
    void addExchangeRate(const std::string &date, double exchangeRate);
    double getExchangeRate(const std::string &date) const;

  private:
    double getClosetLowerPrice(const std::string &date) const;
};

#endif