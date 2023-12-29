#ifndef PARSER_HPP
#define PARSER_HPP

#include "../validator/Validator.hpp"
#include "../util/StringTrimmer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

class Parser
{
  protected:
    Validator *mValidator;

  protected:
    Parser();
    virtual void processValidLine(const std::string &line) = 0;

  public:
    Parser(Validator *validator);
    virtual ~Parser();
    void parse(const std::string &filename);

  private:
    Parser(const Parser &other);
    Parser &operator=(const Parser &other);
};

#endif