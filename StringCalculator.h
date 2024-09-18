#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <stdexcept>  // For std::runtime_error
#include <vector>     // For std::vector

class StringCalculator {
public:
    int add(const std::string& input);
private:
    std::vector<int> extractNumbers(const std::string& input);  // Extract numbers
    void checkForNegatives(const std::vector<int>& numbers);    // Check negatives
    int calculateSum(const std::vector<int>& numbers);          // Sum numbers, ignore > 1000
    std::string normalizeDelimiters(const std::string& input);  // Normalize delimiters
};

#endif // STRING_CALCULATOR_H
