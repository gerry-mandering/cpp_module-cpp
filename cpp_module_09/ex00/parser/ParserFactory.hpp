#ifndef PARSERFACTORY_HPP
#define PARSERFACTORY_HPP

#include "../validator/CSVValidator.hpp"
#include "../validator/TXTValidator.hpp"
#include "../validator/Validator.hpp"
#include "CSVParser.hpp"
#include "Parser.hpp"
#include "TXTParser.hpp"
#include <stdexcept>

class ParserFactory
{
  public:
    static Parser *createParser(const std::string &type);

  private:
    ParserFactory();
    ~ParserFactory();
    ParserFactory(const ParserFactory &copy);
    ParserFactory &operator=(const ParserFactory &copy);
};

#endif