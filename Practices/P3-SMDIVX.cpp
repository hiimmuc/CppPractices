#include <bits/stdc++.h>
using namespace std;

// Function to compute the remainder of a large number (as string) modulo X
long long largeNumberMod(const string& numStr, long long X) {
    long long remainder = 0;
    for (char c : numStr) {
        remainder = (remainder * 10 + (c - '0')) % X;
    }
    return remainder;
}

// Function to find the smallest K-digit number divisible by X
string smallestKDigitNumberDivisibleByX(int K, int X) {
    // Generate the smallest K-digit number, which is '1' followed by (K-1) '0's
    string minKDigitNumber(K, '0');
    minKDigitNumber[0] = '1'; // Smallest K-digit number is '100...0' (K-1 zeros)
    
    // Compute the remainder of this number modulo X
    long long remainder = largeNumberMod(minKDigitNumber, X);

    // If it is already divisible by X, return this number
    if (remainder == 0) {
        return minKDigitNumber;
    }
    
    // Compute the adjustment needed
    long long adjustment = X - remainder;
    
    // Convert the adjustment to string
    string adjustmentStr = to_string(adjustment);

    // If the adjustment has more than K digits, return -1
    if (adjustmentStr.length() > K) {
        return "-1";
    }
    
    // Create the smallest K-digit number divisible by X
    // It is minKDigitNumber + adjustment
    // We add leading zeros to make it a K-digit number
    string result = minKDigitNumber;
    reverse(result.begin(), result.end()); // Reverse for easy concatenation
    result += adjustmentStr;
    reverse(result.begin(), result.end()); // Reverse back
    
    // If the result is larger than the largest K-digit number, return -1
    string maxKDigitNumber(K, '9'); // Largest K-digit number
    if (result > maxKDigitNumber) {
        return "-1";
    }
    
    return result;
}

// Main function

int main() {
    int K;
    long long X;

    cin >> K >> X;  // Input K and X
    
    // Compute and output the result
    cout << smallestKDigitNumberDivisibleByX(K, X) << endl;
    
    return 0;
}
