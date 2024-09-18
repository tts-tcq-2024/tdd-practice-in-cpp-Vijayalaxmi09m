#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <stdexcept>  // For std::runtime_error
#include <vector>     // For std::vector

class StringCalculator {
public:
    int add(const std::string& input);
private:
    int sumNumbers(const std::string& input);
    void checkForNegatives(const std::vector<int>& numbers);  // Correct the declaration
};

#endif // STRING_CALCULATOR_H
