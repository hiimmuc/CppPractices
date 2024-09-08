/**
 * @file P08-ERASE.cpp (done)
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


// Function to add two large numbers represented as strings
string addLargeNumbers(const string& num1, const string& num2) {
    // Convert strings to integers
    long long int n1 = stoll(num1);
    long long int n2 = stoll(num2);
    
    // Add the numbers and convert back to string
    long long int result = n1 + n2 + 10;
    return to_string(result);
}

// Function to process the sequence
string processSequence(vector<string>& nums) {
    // Min-heap (priority queue) to handle large numbers
    priority_queue<string, vector<string>, greater<string>> minHeap;

    // Insert all numbers into the heap
    for (const string& num : nums) {
        minHeap.push(num);
    }

    // Process until only one number remains
    while (minHeap.size() > 1) {
        // Extract the two smallest numbers
        string x = minHeap.top();
        minHeap.pop();
        string y = minHeap.top();
        minHeap.pop();

        // Compute the new number
        string newNum = addLargeNumbers(x, y);

        // Insert the new number back into the heap
        minHeap.push(newNum);
    }

    // The last remaining number is the result
    return minHeap.top();
}

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout  << processSequence(nums) << endl;

    return 0;
}