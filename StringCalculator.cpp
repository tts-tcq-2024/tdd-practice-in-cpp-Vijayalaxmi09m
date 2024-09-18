// StringCalculator.cpp
#include "StringCalculator.h"
#include <string>
#include <sstream>  // For string stream
#include <vector>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    // Handle single input "0"
    if (input == "0") {
        return 0;
    }

    // Handle two numbers separated by a comma
    std::stringstream ss(input);
    std::string token;
    std::vector<int> numbers;
    
    while (std::getline(ss, token, ',')) {
        numbers.push_back(std::stoi(token));  // Convert string to int and store
    }

    int sum = 0;
    for (const int num : numbers) {
        sum += num;  // Sum all numbers in the vector
    }

    return sum;
}
