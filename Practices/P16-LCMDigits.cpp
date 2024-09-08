/**
 * @file P16-.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>


int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  
}

int main() {
    long long a, b;

    // Input two numbers
    std::cin >> a >> b;

    // Compute and output the LCM
    std::cout <<  lcm(sumOfDigits(a),  sumOfDigits(b)) << std::endl;

    return 0;
}
