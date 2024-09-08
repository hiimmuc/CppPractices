/**
 * @file P11-CHAT4.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

#define INF 1e9

#define EL printf("\n")
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)

#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ll countLessEqual(ll m, ll n, ll x) {
    ll count = 0;
    for (int i = 1; i <= m; ++i) {
        count += min(x / i, n);
    }
    return count;
}

// Function to find the k-th smallest element
ll kthSmallest(ll m, ll n, ll k) {
    ll low = 1;
    ll high = m * n;
    ll ans = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (countLessEqual(m, n, mid) < k) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}    

int main() {
    faster;
    ll n, m, k;
    cin >> m >> n;
    cin >> k;

    // solution here
    cout << kthSmallest(m, n, k) << endl;
    //
    return 0;
}