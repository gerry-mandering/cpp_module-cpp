#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "./parser/ParserFactory.hpp"
#include "./parser/Parser.hpp"
#include <string>

// Bitcoin 환전소
class BitcoinExchange
{
  private:
    std::string mDataFileName;
    std::string mInputFileName;

  public:
    BitcoinExchange(const std::string &dataFileName, const std::string &inputFileName);
    BitcoinExchange(const BitcoinExchange &other);

  private:
    BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

  public:
    ~BitcoinExchange();

  public:
    void run();

    class Builder
    {
      private:
        std::string mDataFileName;
        std::string mInputFileName;

      public:
        Builder();
        ~Builder();

      private:
        Builder(const Builder &other);
        Builder &operator=(const Builder &other);

      public:
        Builder &setDataFileName(const std::string &dataFileName);
        Builder &setInputFileName(const std::string &inputFileName);
        BitcoinExchange build();
    };
};
#endif