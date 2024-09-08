/**
 * @file P23-CHIAKEO.cpp (done)
 * @author your name (you@domain.com)
 * @brief prefix sum, binary search
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    freopen("INP/P23.TXT", "r", stdin);

    // Input the number of candy packages
    cin >> N;

    vector<int> A(N), prefixSum(N + 1, 0);

    // Input candy packages and compute prefix sums
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        prefixSum[i + 1] = prefixSum[i] + A[i];  // Cumulative sum up to index i
    }

    int minT = INT_MAX;  // Minimum value of T = max(x, y, z) - min(x, y, z)

    // Iterate over all possible values of i (splitting into parts 1 and 2)
    for (int i = 1; i < N - 1; i++) {
        // x = sum of elements from 1 to i (prefix sum from 1 to i)
        int x = prefixSum[i];

        int left = i + 1, right = N - 1;

        // Now we need to balance the sum of part 2 (y) and part 3 (z)
        while (left < right) {
            int mid = (left + right) / 2;

            // y = sum of elements from i+1 to mid
            int y = prefixSum[mid] - prefixSum[i];
            // z = sum of elements from mid+1 to N
            int z = prefixSum[N] - prefixSum[mid];

            // Calculate T = max(x, y, z) - min(x, y, z)
            int maxVal = max({x, y, z});
            int minVal = min({x, y, z});
            int T = maxVal - minVal;

            // Update the minimum T
            minT = min(minT, T);

            // Move pointers to balance y and z
            if (y < z) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }

    // Output the result
    cout << minT << endl;

    return 0;
}
