/**
 * @file demnt_fix.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Given a number N, the task is to count the number of integers 
 * ------ less than or equal to N with a prime sum of digits.
 * ------FIXED:
 * ------1. The DP table size is adjusted to MAX_DIGITS * MAX_SUM * MAX_DIGITS
 * ------2. cnt is changed to count the sum of digits of the number only
 * ------3. compare current digit with the limit to determine the next digit
 * 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<int>::max() 

#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end); i > (start); i--)
#define FOR_INC(i,start,end,inc) for (int i = (start); i < (end); i += (inc))
#define FORA(i, arr) for (auto& i: arr)
#define fill_array(a, x) memset(a, x, sizeof(a))

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// DP table: [index][tight_constraint][current sum]
const int MAX_DIGITS = 19; // Maximum digits for numbers up to 1e18
const int MAX_SUM = 171;   // Maximum possible sum of digits for a 19-digit number
bool is_prime[MAX_SUM + 1]; // Prime check array
int dp[MAX_DIGITS][2][MAX_DIGITS]; // DP table for digit DP

// Precompute prime numbers up to 200 using Sieve of Eratosthenes
void sieve_of_eratosthenes() {
    fill_array(is_prime, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    FOR(i, 2, MAX_SUM + 1) {
        if (is_prime[i]) {
            FOR_INC(j, i * i, MAX_SUM + 1, i)is_prime[j] = false;
        }
    }
}

// Function to count numbers with a prime sum of digits using digit DP
int solve(const string &s, int index, int reach_the_limit, int last_digit_sum) {
    if (index == s.length()) {
        return is_prime[last_digit_sum] ? 1 : 0;  // Check if the digit sum is prime
    }

    if (dp[index][reach_the_limit][last_digit_sum] != -1) return dp[index][reach_the_limit][last_digit_sum];

    int limit = reach_the_limit ? s[index] - '0' : 9;  // Determine the upper limit of the current digit
    int ans = 0;

    // Try all possible digits from 0 to limit
    for (int digit = 0; digit <= limit; digit++) {
        ans += solve(s, index + 1, reach_the_limit & (digit == limit), last_digit_sum + digit);
    }

    return dp[index][reach_the_limit][last_digit_sum] = ans;
}


// Driver Code
int main() {
    faster;

    sieve_of_eratosthenes();  // Precompute prime numbers up to 200

    ll n;
    cin >> n;

    string s = to_string(n);  // Convert number to string representation of its digits
    fill_array(dp, -1);  // Initialize the DP table to -1

    // Solve the problem using digit DP with a string representation
    cout << solve(s, 0, 1, 0) << '\n';

    return 0;
}
