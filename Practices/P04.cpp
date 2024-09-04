// calculate mod of power of a number

#include <iostream>
// #include "bits/stdc++.h"
#include <cmath>

using namespace std;

FILE *inp, *out;

int main() {
    inp=freopen("INP/P04.TXT", "r", stdin);
    out=freopen("OUT/P04.TXT", "w", stdout);

    int a, b, c;
    
    cin >> a >> b >> c;

    cout << (int)pow(a, b) % c << endl;

}