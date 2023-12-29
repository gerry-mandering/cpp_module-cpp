#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include "Parser.hpp"
#include "../database/Database.hpp"
#include <cstdlib>

class CSVParser : public Parser
{
  public:
    CSVParser(Validator *validator);
    ~CSVParser();

  protected:
    void processValidLine(const std::string &line);

  private:
    CSVParser();
    CSVParser(const CSVParser &other);
    CSVParser &operator=(const CSVParser &other);
};

#endif