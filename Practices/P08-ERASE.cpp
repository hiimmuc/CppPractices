/**
 * @file P08-ERASE.cpp
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


int sum2(int a, int b, int &carry)
{
    int result = a+b+carry;
    if (result >= 10) {
        result -= 10;
        carry = 1;
    } else {
        carry = 0;
    }
    return result;
}

string add(string a, string b)
{
    int s {0}, carry {0};

    if (b.length() > a.length() ||
        (b.length() == a.length() && b[0] - '0' > a[0] - '0')) {
        swap(a, b);
    }
    string c = "";
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0) {
        if (j < 0) {
            s = sum2(a[i] - '0', 0, carry);
            // c += sum(a[i] - '0', m, 1);
            i--;
        } else {
            s = sum2(a[i] - '0', b[j] - '0', carry);
            i--;
            j--;
        }
        c += s+'0';
    }
    if (carry)
        c += '1';
    for (int i = 0; i <= (c.length() - 1) / 2; i++)
        swap(c[i], c[c.length() - 1 - i]);
    return c;
}


int main () {
    faster;
    
    ll n;
    cin >> n;
    if (n < 1 || n > 100000){
        cout << -1;
        return 0;
    }

    // Method 1: Using std::accumulate, not good for large arrays
    ull A[100000];
    FOR(i, 0, n){
        cin >> A[i];
    }
    cout << 10 * (n-1) + sum(A, 0, n) << endl;

    // Method 2: Using string-int conversion to store large numbers

    // string A[100000];
    // FOR(i, 0, n){
    //     cin >> A[i];
    // }

    // string temp;
    // for (int i = 0; i < n - 1; i++){
    //     temp = add(A[i], A[i+1]);
    //     temp = add(temp, "10");
    // }
    // cout << stol(temp) << endl;
    return 0;
}