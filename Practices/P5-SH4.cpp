/**
 * @file P5-SH4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>

using namespace std;

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to compute the sum of divisors using prime factorization
long long sumOfDivisors(long long n) {
    long long sum = 1;  // Start with 1 to account for the divisor 1
    long long originalN = n;
    
    // Check for number of 2s
    if (n % 2 == 0) {
        long long currentSum = 1;
        while (n % 2 == 0) {
            n /= 2;
            currentSum = currentSum * 2 + 1;
        }
        sum *= currentSum;
    }
    
    // Check for odd factors from 3 to sqrt(n)
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            long long currentSum = 1;
            while (n % i == 0) {
                n /= i;
                currentSum = currentSum * i + 1;
            }
            sum *= currentSum;
        }
    }
    
    // If n is still greater than 1, then it must be a prime factor
    if (n > 1) {
        sum *= (n + 1);
    }
    
    return sum;
}

int main() {
    long long n;
    cin >> n;  // Input the number

    // Calculate and print the sum of divisors
    cout << sumOfDivisors(n) << endl;

    return 0;
}
