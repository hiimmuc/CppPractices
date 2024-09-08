
/**
 * @brief Idea:gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(a, gcd(b, c)) = gcd(gcd(a, c), b)
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */

#include "bits/stdc++.h"

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

int gcd2(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd2(b, a % b); 
} 

int gcd(int a, int b, int& x, int& y){
   if(b == 0){
       x=1;
       y=0;
       return a;
   }
   int x1, y1;
   int d = gcd(b, a % b, x1, y1);
   x = y1;
   y = x1 - y1 * (a / b);
   return d;
}

int gcd3(int a, int b, int c) { 
    // euclidean algorithm
    return gcd2(gcd2(a, b), c); 
} 
 

int main () {
    bool debug = false;
    if(debug){
        int correct = 0;
        // read from files and compare results
    }
    else{
        ll a,b,c;
        cin >> a >> b >> c;
        cout << gcd3(a, b, c);
    }
    return 0;
}