/**
 * @file P14-MOD1.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

// Function to perform modular addition
long long modularAddition(long long a, long long b, long long mod) {
    a = a % mod;  // Reduce a modulo mod
    b = b % mod;  // Reduce b modulo mod
    long long result = (a + b) % mod;  // Add the reduced values and take modulo
    return result;
}

int main() {
    long long a, b, mod;

    // Input values
    std::cin >> a >> b >> mod;

    // Output result
    std::cout << modularAddition(a, b, mod) << std::endl;

    return 0;
}
