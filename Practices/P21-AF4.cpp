/**
 * @file P21-AF4.cpp 
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
#define sum(a, start, end) accumulate(a + start, a + end, 0)

#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


// Function to calculate GCD using Euclidean algorithm
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0; 
    return (a * b) / gcd(a, b);
}

// Function to count pairs with LCM less than K
int count_pairs(std::vector<ll>& arr, ll K) {
    if (K <= 0) return -1;
    
    std::unordered_map<ll, int> freq;
    int count = 0;

    for (ll num : arr) {
        freq[num]++;
    }

    std::vector<ll> unique;
    for (auto it : freq) {
        unique.push_back(it.first);
    }

    std::sort(unique.begin(), unique.end());

    FOR(i, 0, unique.size()) {
        FOR(j, i + 1, unique.size()) {
            if (lcm(arr[i], arr[j]) <= K) {
                if (i == j) count += freq[unique[i]] * (freq[unique[j]] - 1) / 2;
                else count += freq[unique[i]] * freq[unique[j]];
            }
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    if (n < 0 || n > 100) cout << -1 << endl;
    
    ll K;
    std::cin >> K;

    std::vector<ll> arr(n);
    FOR(i, 0, n) std::cin >> arr[i];

    std::cout << count_pairs(arr, K) << std::endl;

    return 0;
}
