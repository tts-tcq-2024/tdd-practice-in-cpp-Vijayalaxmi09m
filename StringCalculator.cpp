// StringCalculator.cpp
#include "StringCalculator.h"
#include <string>
#include <sstream>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    // Delegate to a helper function to sum the numbers
    return sumNumbers(input);
}

int StringCalculator::sumNumbers(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        sum += std::stoi(token);  // Convert string to int and accumulate sum
    }

    return sum;
}
