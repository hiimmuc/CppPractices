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

//1 Function to calculate the largest rectangle area in a matrix
bool validRectangle(vector<vector <int>>&mat , int x1, int y1, int x2, int y2) {
    //check all elements in the rectangle are 1 or not
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (mat[i][j] == 0) return false;
        }
    }
    return true;
}

int solution1(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int res = 0;
    //iterate over all possible rectangles
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < m; y2++) {
                    if (validRectangle(mat, x1, y1, x2, y2)) {
                        res = max(res, (x2 - x1 + 1) * (y2 - y1 + 1));
                    }
                }
            }
        }
    }
    return res;
}

//2 Function to calculate the largest rectangle area in a histogram
int largestRectangleInHistogram(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        s.push(i);
    }

    // Handle remaining elements in the stack
    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

// Function to find the largest rectangle that contains only 1s
int solution2(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int M = matrix.size();
    int N = matrix[0].size();
    vector<int> height(N, 0);
    int maxArea = 0;
    
    // Traverse each row of the matrix
    for (int i = 0; i < M; ++i) {
        // Update the histogram heights for the current row
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 1) {
                height[j] += 1;
            } else {
                height[j] = 0;
            }
        }
        
        // Find the largest rectangle in the updated histogram
        maxArea = max(maxArea, largestRectangleInHistogram(height));
    }

    return maxArea;
}
//3 Function to calculate the largest rectangle area in a matrix using DP

int solution3(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    int maxArea = 0;

    for (const auto& row : matrix) {
        int curLeft = 0, curRight = n;

        // Update height array
        for (int j = 0; j < n; j++) {
            if (row[j] == 1) {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        // Update left boundary array
        for (int j = 0; j < n; j++) {
            if (row[j] == 1) {
                left[j] = max(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // Update right boundary array
        for (int j = n - 1; j >= 0; j--) {
            if (row[j] == 1) {
                right[j] = min(right[j], curRight);
            } else {
                right[j] = n;
                curRight = j;
            }
        }

        // Calculate maximum area for each cell
        for (int j = 0; j < n; j++) {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}

int main() {
    FILE* file = freopen("INP/MAT.TXT", "r", stdin);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int result = solution3(matrix);
    cout << "The area of the largest rectangle containing only 1s is: " << result << endl;
    return 0;
}