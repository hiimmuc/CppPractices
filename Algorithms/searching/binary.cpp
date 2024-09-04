#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Target might be in the right half
        } else {
            right = mid - 1; // Target might be in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int index = binarySearch(nums, 0, nums.size() - 1, target);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}