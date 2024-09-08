/**
 * @file P13-MOD2.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

// Function to perform modular multiplication
long long modularMultiplication(long long a, long long b, long long mod) {
    long long result = 0;  // Initialize result
    a = a % mod;  // Ensure a is within mod

    while (b > 0) {
        // If b is odd, add 'a' to the result (modulo mod)
        if (b % 2 == 1) {
            result = (result + a) % mod;
        }
        // Double the value of 'a' and halve 'b'
        a = (a * 2) % mod;
        b /= 2;
    }

    return result;
}

int main() {
    long long a, b, mod;
    
    // Input values
    std::cin >> a >> b >> mod;
    
    // Output result
    std::cout <<  modularMultiplication(a, b, mod) << std::endl;
    
    return 0;
}
