
/**
 * @file P6-DONGDU.cpp (done)
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

typedef long long ll;
typedef unsigned long long ull;

#define INF 1e9

#define EL printf("\n")
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll gcd2(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd2(b, a % b); 
} 

// Function to compute the largest d such that a%d == b%d == c%d
ll largest_common_modulo(ll a, ll b, ll c) {
    // Calculate absolute differences
    ll diff1 = std::abs(a - b);
    ll diff2 = std::abs(b - c);
    ll diff3 = std::abs(a - c);
    
    // The largest d must divide the GCD of the differences
    return gcd2(diff1, gcd2(diff2, diff3));
}
 

int main () {
    faster;
    ll a, b, c;
    cin >> a >> b >> c;
    cout << largest_common_modulo(a, b, c) << endl;
    return 0;
}