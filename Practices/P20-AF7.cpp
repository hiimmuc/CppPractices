/**
 * @file P20-AF7.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

// Function to count the number of divisors of a number
int countDivisors(int num) {
    if (num <= 0) return 0;
    int count = 0;
    int sqrtNum = static_cast<int>(std::sqrt(num));
    
    for (int i = 1; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            if (i * i == num) {
                count += 1;  // Perfect square
            } else {
                count += 2;  // i and num/i are distinct
            }
        }
    }
    
    return count;
}

// Function to find the number of pairs (i, j) with the required property
int countValidPairs(const std::vector<int>& arr) {
    int n = arr.size();
    int validPairs = 0;

    // Iterate over all pairs (i, j)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int numDivisors = countDivisors(arr[i]) + countDivisors(arr[j]);
            if (numDivisors % 7 == 0) {
                ++validPairs;
            }
        }
    }

    return validPairs;
}

int main() {
    int n;

    // Read the number of elements
    std::cin >> n;
    std::vector<int> arr(n);

    // Read the array elements
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Find and print the number of valid pairs
    std::cout << countValidPairs(arr) << std::endl;

    return 0;
}
