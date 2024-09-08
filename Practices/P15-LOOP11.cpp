/**
 * @file P15-LOOP11.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cmath>

// Euler-Mascheroni constant
const double gamma = 0.57721566490153286060;

// Function to compute the harmonic sum S = 1 + 1/2 + ... + 1/n
double harmonicSum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

// Function to find the smallest n such that S > A using approximation and refinement
int findSmallestN(double A) {
    // Approximate the initial guess for n using the harmonic number approximation
    int n = std::exp(A - gamma);  // Initial guess: n ~ exp(A - gamma)
    
    // Refine n by calculating the exact harmonic sum and adjusting n
    while (harmonicSum(n) <= A) {
        n++;  // Increment n until the sum exceeds A
    }

    return n;  // Return the smallest n such that S > A
}

int main() {
    double A;

    // Input the real number A
    std::cin >> A;

    // Output the result
    std::cout << findSmallestN(A) << std::endl;

    return 0;
}
