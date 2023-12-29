#ifndef STRINGTRIMMER_HPP
#define STRINGTRIMMER_HPP

#include <string>

class StringTrimmer
{
  public:
    static std::string trim(const std::string &str);

  private:
    StringTrimmer();
    ~StringTrimmer();
    StringTrimmer(const StringTrimmer &other);
    StringTrimmer &operator=(const StringTrimmer &other);
};

#endif