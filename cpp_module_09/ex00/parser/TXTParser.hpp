#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP

#include "Parser.hpp"
#include "../database/Database.hpp"

class TXTParser : public Parser
{
  public:
    TXTParser(Validator *validator);
    ~TXTParser();

  protected:
    void processValidLine(const std::string &line);

  private:
    TXTParser();
    TXTParser(const TXTParser &other);
    TXTParser &operator=(const TXTParser &other);
};

#endif