/**
 * @file P19-ARR11.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// Function to swap two elements
void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function to place the pivot in the correct position
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) { // Chang to sort from smallest to largest
            ++i;
            swap(arr, i, j);  // Swap if element is smaller than pivot
        }
    }
    swap(arr, i + 1, high);  // Place the pivot in the correct position
    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index
        quickSort(arr, low, pi - 1);  // Recursively sort the left sub-array
        quickSort(arr, pi + 1, high);  // Recursively sort the right sub-array
    }
}

float findMedian(std::vector<int>& arr) {
    size_t n = arr.size();
    
    quickSort(arr, 0, n - 1);
        
    if (n % 2 == 1) {
        // If the number of elements is odd, return the middle element
        return arr[n / 2];
    } else {
        // If the number of elements is even, return the average of the two middle elements
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }


    std::cout << findMedian(arr) << std::endl;

    return 0;
}