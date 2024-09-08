/**
 * @file P22-SUBMATRIX.cpp (done)
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

// Function to count distinct elements in a submatrix using a sliding window
bool is_valid_submatrix(const vector<vector<int>>& matrix, int M, int N, int K, int size) {
    for (int i = 0; i <= M - size; ++i) {
        unordered_map<int, int> freq;

        // Initialize the frequency map for the first submatrix of this row
        for (int x = i; x < i + size; ++x) {
            for (int y = 0; y < size; ++y) {
                freq[matrix[x][y]]++;
            }
        }

        // Check if the first submatrix is valid
        if (freq.size() <= K) return true;

        // Slide the window across the row
        for (int j = 1; j <= N - size; ++j) {
            // Update frequency map by removing the left column and adding the right column
            for (int x = i; x < i + size; ++x) {
                // Remove the element from the previous column (left side of the window)
                int to_remove = matrix[x][j - 1];
                freq[to_remove]--;
                if (freq[to_remove] == 0) {
                    freq.erase(to_remove); // Remove from map if frequency is 0
                }

                // Add the element from the new column (right side of the window)
                int to_add = matrix[x][j + size - 1];
                freq[to_add]++;
            }

            // Check if the updated submatrix is valid
            if (freq.size() <= K) return true;
        }
    }

    return false;
}

// Binary search for the largest possible square submatrix
int find_largest_square(const vector<vector<int>>& matrix, int M, int N, int K) {
    int left = 1, right = min(M, N), largest_size = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_valid_submatrix(matrix, M, N, K, mid)) {
            largest_size = mid;  // This size is valid, try larger
            left = mid + 1;
        } else {
            right = mid - 1;  // Too large, try smaller
        }
    }

    return largest_size;
}

int main() {
    int M, N, K;
    FILE *inp = freopen("INP/P22.TXT", "r", stdin);

    // Input matrix dimensions and K
    cin >> M >> N >> K;

    vector<vector<int>> matrix(M, vector<int>(N));

    // Input the matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find and print the largest square submatrix that satisfies the condition
    cout << find_largest_square(matrix, M, N, K) << endl;

    return 0;
}
