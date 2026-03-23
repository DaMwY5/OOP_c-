#include "rational.h"
#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
        return 1;
    }
    
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output.txt" << std::endl;
        return 1;
    }
    
    Rational numbers[5];
    
    for (int i = 0; i < 5; i++) {
        if (!(inputFile >> numbers[i])) {
            std::cerr << "Error: Could not read " << i + 1 << "th number" << std::endl;
            return 1;
        }
    }
    
    inputFile.close();
    
    outputFile << std::fixed << std::setprecision(2);
    
    for (int i = 0; i < 5; i++) {
        Rational result = numbers[i] * Rational(3);
        outputFile << result.toDouble() << std::endl;
    }
    
    outputFile.close();
    
    std::cout << "Successfully processed 5 numbers. Results written to output.txt" << std::endl;
    
    return 0;
}