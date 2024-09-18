#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    // Step-by-step processing: Extract numbers, check for negatives, then sum
    std::vector<int> numbers = extractNumbers(input);
    checkForNegatives(numbers);
    return calculateSum(numbers);
}

std::vector<int> StringCalculator::extractNumbers(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    std::vector<int> numbers;

    while (std::getline(ss, token, ',')) {
        numbers.push_back(std::stoi(token));  // Convert string to int and store
    }

    return numbers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    for (int number : numbers) {
        if (number < 0) {
            throw std::runtime_error("Negatives not allowed: " + std::to_string(number));
        }
    }
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}
