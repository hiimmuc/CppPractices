#include <iostream>

using namespace std;


void selectionSort(int arr[], int n) {
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        cout << "minIndex: " << minIndex << endl;

        for (int j = i + 1; j < n; j++) {
            cout << "Compare: " << arr[j]  << " vs " << arr[minIndex] << " ";

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }

            cout << "New minIndex: " << minIndex << endl;

        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        cout << "Array is " << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << "\n" << endl;
        
    }
}

void selectionSort_dumb(int arr[], const int n) {
    
    int minIndex;
    int res[n];
    bool picked[n];

    // init values
    for (int i = 0; i < n; i++) {
        picked[i] = false;
        res[i] = 0;
    }
    
    for (int i = 0; i < n  ; i++) {
        int minIndex = 0;
        
        // Find the minimum element in the unsorted part of the array
        for (int j = 0; j < n; j++) {
            if ((arr[j] < arr[minIndex] || minIndex == 0) && !picked[j]) {
                // neu vi tri minIndex o dau hoac la arr[j] < arr[minIndex va so do chua duoc chon (!picked[j])
                minIndex = j;
            }
        }

        res[i] = arr[minIndex];
        picked[minIndex] = true;
        
    }

    // copy to original array
    for(int i = 0; i < n; i++) arr[i] = res[i]; 

}



int main() {
    int arr[] = {50, 30, 40, 10, 20};
    const int n = sizeof(arr) / sizeof(arr[0]);
    int res[n];
    bool picked[n];

    cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;

    // khong hoan

    int arr2[] = {50, 30, 40, 10, 20};
    cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    selectionSort_dumb(arr2,  n);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;


    return 0;
}