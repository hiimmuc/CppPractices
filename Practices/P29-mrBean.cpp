/**
 * @file P29-mrBean.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to calculate the largest rectangular area in a histogram
long long largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    long long maxArea = 0;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, (long long)height * width);
        }
        s.push(i);
    }
    
    // Process any remaining heights in the stack
    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, (long long)height * width);
    }
    
    return maxArea;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }
    
    long long result = largestRectangleArea(heights);
    cout << result << endl;
    
    return 0;
}
