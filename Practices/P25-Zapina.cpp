/**
 * @file P25-Zapina.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Assign N tasks to N programmers. 
 * -----  Programmer ith will be satisfied if he is assigned exactly i tasks.
 * -----  Find the number of ways to assign tasks to programmers such that at least one programmer is satisfied.
 * -----  Input: 1 <= N <= 350 Output: Print the number of ways modulo 10^9 + 7.
 * -----  Example: Input: 1 Output: 1 || Input: 2 Output: 3 || Input: 314 Output: 192940893
 * -----  => IDEA: pre-calculate nCk assign tasks to programmers. 
 *                 Then using Inclusion-Exclusion Principle to calculate the number of ways to assign tasks to programmers.
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<int>::max() 

#define FORA(i, arr) for (auto& i: arr)
#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end); i > (start); i--)
#define FOR_INC(i,start,end,inc) for (int i = (start); i < (end); i += (inc))

#define fill_array(a, x) memset(a, x, sizeof(a))

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// start here
const int MAX_N = 351;
const int MOD = 1e9 + 7;

int N;
int dp[MAX_N + 1][MAX_N + 1];
int nCk[MAX_N + 1][MAX_N + 1];

// re-define add and mul functions with modulo to avoid overflow
int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (ll)a * b % MOD; }
int pow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int half = pow(base, exp >> 1);
    if (exp & 1) return mul(mul(half, half), base);
    return mul(half, half);
}

// pre-calculate the number of ways to choose i elements from a set of a elements
void precalc(int N) {
    nCk[0][0] = 1;
    FOR(i, 1, N + 1) {
        nCk[i][0] = 1;
        FOR(j, 1, i + 1) {
            nCk[i][j] = add(nCk[i -1][j], nCk[i - 1][j - 1]);
        }
    }
}

/**
 * @brief dp[i][j]: number of ways to assign j tasks to i programmers which cause the programmer ith is not satisfied.
 * Start: 
 * -----  dp[0][0] = 1 (no programmer, no task)
 * -----  dp[i][0] = 0 (no task, i programmers)
 * -----  dp[0][j] = 0 (j tasks, no programmer)
 * Update dp[i][j]:
 * -----  if k != i: dp[i][j] = dp[i][j] + dp[i-1][j-k] * nCk[j][k] (programmer ith is not satisfied with k tasks)
 *      => dp[N][N]: number of ways to assign tasks to programmers which cause all programmers are not satisfied.
 * Total number of ways to assign tasks to programmers: pow(N, N)
 * Number of ways to assign tasks to programmers such that at least one programmer is satisfied: pow(N, N) - dp[N][N] (Inclusion-Exclusion Principle)
 * 
 * @param N 
 * @return int 
 */
int assign_tasks(int N) {
    dp[0][0] = 1;
    FOR(i, 1, N + 1) { // i: number of programmers
        FOR(j, 0, N + 1) { // j: number of tasks
            FOR(k, 0, j + 1) { // k: number of tasks assigned to programmer i
                if (k != i) dp[i][j] = add(dp[i][j], mul(dp[i-1][j-k], nCk[j][k]));
            }
        }
    }
    return (pow(N, N) - dp[N][N] + MOD) % MOD;
}

int main() {
    faster;
    cin >> N;
    // 
    precalc(N);
    // 
    cout << assign_tasks(N) << endl;
    return 0;
}