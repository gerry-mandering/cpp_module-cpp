#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <cstddef>
#include <cstdlib>
#include <map>
#include <string>
#include <exception>

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

  public:
    class InvalidDateException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif