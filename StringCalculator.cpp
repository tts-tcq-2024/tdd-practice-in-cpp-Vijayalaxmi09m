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
    std::vector<int> numbers;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        int number = std::stoi(token);
        numbers.push_back(number);  // Store the numbers
        sum += number;
    }

    // Check for negatives after accumulating the numbers
    checkForNegatives(numbers);

    return sum;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }

    if (!negatives.empty()) {
        throw std::runtime_error("Negatives not allowed: " + std::to_string(negatives[0]));
    }
}
