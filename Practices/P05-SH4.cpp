#include "bits/stdc++.h"

using namespace std;

long long sum_all_divisors(long long num)
{
    long long sum = 0;
    for (long long i = 1; i <= sqrt(num); i++) {
        long long t1 = i * (num / i - i + 1); // adding i every time it appears with numbers greater than or equal to itself
        long long t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2); // adding numbers that appear with i and are greater than i
        sum += t1 + t2;
    }
    return sum;
}

int main()
{
    int n;

    cin >> n;

    if (n > 1e12){
        return -1;
    }

    long long sum = sum_all_divisors(n);
    cout << sum << endl;
    return 0;
}