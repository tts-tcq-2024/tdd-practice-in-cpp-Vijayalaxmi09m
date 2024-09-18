#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>  // For std::replace

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    // Step-by-step processing: Extract numbers, check for negatives, then sum
    std::string normalizedInput = normalizeDelimiters(input);
    std::vector<int> numbers = extractNumbers(normalizedInput);
    checkForNegatives(numbers);
    return calculateSum(numbers);
}

std::string StringCalculator::normalizeDelimiters(const std::string& input) {
    std::string normalized = input;
    std::replace(normalized.begin(), normalized.end(), '\n', ',');  // Replace newlines with commas
    return normalized;
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
        if (number <= 1000) {  // Ignore numbers greater than 1000
            sum += number;
        }
    }
    return sum;
}
