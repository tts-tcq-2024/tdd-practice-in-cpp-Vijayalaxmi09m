// StringCalculator.cpp
#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>

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
    std::vector<int> negatives;

    while (std::getline(ss, token, ',')) {
        int number = std::stoi(token);
        if (number < 0) {
            negatives.push_back(number);  // Collect negative numbers
        }
        sum += number;
    }

    // If there are negative numbers, throw an exception
    if (!negatives.empty()) {
        throw std::runtime_error("Negatives not allowed: " + std::to_string(negatives[0]));
    }

    return sum;
}
