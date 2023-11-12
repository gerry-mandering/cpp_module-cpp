#ifndef STRINGTRIMMER_HPP
#define STRINGTRIMMER_HPP

#include <string>

class StringTrimmer
{
  public:
    static std::string &leftTrim(std::string &input);
    static std::string &rightTrim(std::string &input);
    static std::string &trim(std::string &input);

  private:
    StringTrimmer();
    ~StringTrimmer();
    StringTrimmer(StringTrimmer const &other);
    StringTrimmer &operator=(StringTrimmer const &other);
};

#endif