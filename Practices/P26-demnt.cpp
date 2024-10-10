/**
 * @file demnt.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Given a number N, the task is to count the number of integers 
 * ------ less than or equal to N with a prime sum of digits.
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

// NOTE: start here
const int MAX_DIGITS = 19; // Maximum digits for numbers up to 1e18
const int MAX_SUM = 171;   // Maximum possible sum of digits for a 19-digit number
bool is_prime[MAX_SUM + 1]; // Prime check array
ll dp[MAX_DIGITS][2][MAX_DIGITS]; // DP table for digit DP

/**
 * @brief Implements the Sieve of Eratosthenes algorithm to find all prime numbers up to a given limit.
 *
 * This function marks non-prime numbers in a boolean array `is_prime` where the index represents the number.
 * Initially, all numbers are assumed to be prime. The algorithm iteratively marks the multiples of each prime number starting from 2.
 * 
 * @note The array `is_prime` and the constant `MAX_SUM` should be defined globally.
 *       The array `is_prime` should have a size of at least `MAX_SUM + 1`.
 */
void sieve_of_eratosthenes() {
    fill_array(is_prime, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    FOR(i, 2, MAX_SUM + 1) {
        if (is_prime[i]) {
            FOR_INC(j, i * i, MAX_SUM + 1, i)is_prime[j] = false;
        }
    }
}

/**
 * @brief Count the number of integers less than or equal to n with a prime sum of digits.
 * 
 * @param n The upper limit of the numbers to consider.
 * @return The number of integers less than or equal to n with a prime sum of digits.
 */
ll count_prime_sum_digits(vi &digits, int pos = 0, int sum = 0, bool tight = true) {
    if (pos == digits.size()) return is_prime[sum]; // Check if the sum of digits is prime
    
    if (dp[pos][tight][sum] != -1) return dp[pos][tight][sum];

    int limit = tight ? digits[pos] : 9; // Determine the upper limit of the current digit
    ll ans = 0;

    // Try all possible digits from 0 to limit
    FOR(digit, 0, limit + 1) {
        ans += count_prime_sum_digits(digits, pos + 1, sum + digit, tight && (digit == limit));
    }

    return dp[pos][tight][sum] = ans;
}


/**
 * @brief Recursively solves the problem by exploring all possible digit combinations.
 * 
 * This function uses dynamic programming to count the number of valid digit combinations
 * that satisfy certain conditions. It checks if the sum of the digits is a prime number.
 * 
 * @param s The input string representing the number.
 * @param index The current index in the string being processed.
 * @param reach_the_limit A flag indicating whether the current digit is constrained by the input number.
 * @param last_digit_sum The sum of the digits processed so far.
 * @return int The number of valid digit combinations that satisfy the conditions.
 */
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


// Main function
int main() {
    faster;
    sieve_of_eratosthenes(); // Precompute prime numbers up to MAX_SUM

    ll n;
    cin >> n;
    // Get the digits of the number
    vi digits;
    while (n > 0) { digits.push_back(n % 10); n /= 10; }
    reverse(digits.begin(), digits.end());
    fill_array(dp, -1); // Initialize the DP table to -1
    // using vector representation
    cout <<  count_prime_sum_digits(digits) << endl;
    // using string representation
    string s = to_string(n); 
    cout << solve(s, 0, 1, 0) << endl;

    return 0;
}