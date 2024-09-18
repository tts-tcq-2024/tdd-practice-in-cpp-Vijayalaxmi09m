// StringCalculator.h
#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <stdexcept>  // For std::runtime_error

class StringCalculator {
public:
    int add(const std::string& input);
private:
    int sumNumbers(const std::string& input);
};

#endif // STRING_CALCULATOR_H
