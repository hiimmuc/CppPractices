/**
 * @file P25-Zapina.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Assign N tasks to N programmers. 
 * -----  Programmer ith will be satisfied if he is assigned exactly i tasks.
 * -----  Find the number of ways to assign tasks to programmers such that at least one programmer is satisfied.
 * -----  Input: 1 <= N <= 350 Output: Print the number of ways modulo 10^9 + 7.
 * -----  Example: Input: 1 Output: 1 || Input: 2 Output: 3 || Input: 314 Output: 192940893
 * -----  => IDEA: .
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
const int MAX_N = 351 + 1;
const int MOD = 1e9 + 7;

int N, choose[MAX_N][MAX_N];

int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (ll)a * b % MOD; }
int pow(int a, int b) {
    int r = 1;
    for (; b; b >>= 1) {
        if (b & 1) r = mul(r, a);
        a = mul(a, a);
    }
    return r;
}

void precalc() {
    choose[0][0] = 1;
    FOR(i, 1, MAX_N) {
        choose[i][0] = 1;
        FOR(j, 1, MAX_N) {
            choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
        }
    }
}

int solve(int N) {
    int sol = 0;
    FOR(mask, 1, (1 << N)) {
        int sum = 0, k = __builtin_popcount(mask);
        FOR(i, 0, N) if ((1 << i) & mask) sum += i + 1;
        if (sum > N) continue;
        int tmp = 1, tot = N;
        FOR(i, 0, N) {
            if ((1 << i) & mask) {
                tmp = mul(tmp, choose[tot][i + 1]);
                tot -= i + 1;
            }
        }
        tmp = mul(tmp, pow(N - k, tot));
        if (!(k & 1)) tmp = MOD - tmp;
        sol = add(sol, tmp);
    }
    return sol;
}
  
int main() {
    faster;
    cin >> N;

    precalc();

    cout << solve(N) << endl;

    return 0;
}