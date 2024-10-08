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

    cout <<  count_prime_sum_digits(digits) << endl;

    return 0;
}