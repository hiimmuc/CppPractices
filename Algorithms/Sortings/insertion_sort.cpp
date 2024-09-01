#include <iostream>

using namespace std;




void insertionSort(int arr[], int n) {
    int temp;
    int j;

    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        cout << "\nCurrent choosen element: " << temp << endl;

        while (j >= 0 && arr[j] > temp) {
            cout << " - Shit element at " << j  << " (" << arr[j] << ")" << " to position " << j + 1  << " (" << arr[j + 1] << ")" << endl;
            
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;

        cout << "Insert choosen element to position: " << j + 1 << endl;

        for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
        }
        cout << endl;
    }
}




int main() {
    int arr[] = {50, 30, 40, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}