#include "BoundaryChecker.hpp"

const std::string BoundaryChecker::FLOAT_MIN = "-340282346638528859811704183484516925440";

const std::string BoundaryChecker::FLOAT_MAX = "340282346638528859811704183484516925440";

const std::string BoundaryChecker::DOUBLE_MIN =
    "-17976931348623157081452742373170435679807056752584499659891747680315726078002853876058955863276687817154045895351"
    "438246423432132688946418276846754670353751698604991057655128207624549009038932894407586850845513394230458323690322"
    "2948165808559332123348274797826204144723168738177180919299881250404026184124858368";

const std::string BoundaryChecker::DOUBLE_MAX =
    "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514"
    "382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222"
    "948165808559332123348274797826204144723168738177180919299881250404026184124858368";

BoundaryChecker::BoundaryChecker() {}

BoundaryChecker::~BoundaryChecker() {}

BoundaryChecker::BoundaryChecker(BoundaryChecker const &other)
{
    (void)other;
}

BoundaryChecker &BoundaryChecker::operator=(BoundaryChecker const &other)
{
    (void)other;
    return *this;
}

bool BoundaryChecker::isFloat(const std::string &input)
{
    std::string floatBoundary = (input[0] == '-') ? FLOAT_MIN : FLOAT_MAX;
    std::string integerPart = truncateAfterDecimalPoint(input);

    // compare length
    if (integerPart.length() > floatBoundary.length())
    {
        return false;
    }
    else if (integerPart.length() < floatBoundary.length())
    {
        return true;
    }

    if (strcmp(integerPart.c_str(), floatBoundary.c_str()) > 0)
    {
        return false;
    }
    else if (strcmp(integerPart.c_str(), floatBoundary.c_str()) == 0)
    {
        std::string decimalPart = truncateBeforeDecimalPoint(input);

        if (decimalPart.empty())
        {
            return true;
        }

        for (size_t i = 0; i < decimalPart.size(); ++i)
        {
            if (decimalPart[i] != '0')
            {
                return false;
            }
        }
    }

    return true;
}

bool BoundaryChecker::isDouble(const std::string &input)
{
    std::string doubleBoundary = (input[0] == '-') ? DOUBLE_MIN : DOUBLE_MAX;
    std::string integerPart = truncateAfterDecimalPoint(input);

    // compare length
    if (integerPart.length() > doubleBoundary.length())
    {
        return false;
    }
    else if (integerPart.length() < doubleBoundary.length())
    {
        return true;
    }

    if (strcmp(integerPart.c_str(), doubleBoundary.c_str()) > 0)
    {
        return false;
    }
    else if (strcmp(integerPart.c_str(), doubleBoundary.c_str()) == 0)
    {
        std::string decimalPart = truncateBeforeDecimalPoint(input);

        if (decimalPart.empty())
        {
            return true;
        }

        for (size_t i = 0; i < decimalPart.size(); ++i)
        {
            if (decimalPart[i] != '0')
            {
                return false;
            }
        }
    }

    return true;
}

std::string BoundaryChecker::truncateAfterDecimalPoint(const std::string &input)
{
    size_t decimalPointPos = input.find('.');
    if (decimalPointPos != std::string::npos)
    {
        return input.substr(0, decimalPointPos);
    }
    return input;
}

std::string BoundaryChecker::truncateBeforeDecimalPoint(const std::string &input)
{
    size_t decimalPointPos = input.find('.');
    if (decimalPointPos != std::string::npos)
    {
        return input.substr(decimalPointPos + 1);
    }
    return std::string();
}
