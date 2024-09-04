#include <iostream>  
#include <vector>  

using namespace std;
  
int linearSearch(const vector<int>& arr, int target) {  
    for (int i = 0; i < arr.size(); i++) {  
        if (arr[i] == target) {  
            return i; // Return the index of the element  
        }  
    }  
    return -1; // If the target is not found, return -1  
}  
  
int main() {  
    vector<int> myVector = {4, 7, 2, 1, 9, 5};  
    int targetValue = 9;  
  
    int result = linearSearch(myVector, targetValue);  
    if (result != -1) {  
        cout << "The target value " << targetValue 
        << " is found at index " << result << "." << endl;  
    } else {  
        cout << "The target value is not present in the vector." << endl;  
    }  
  
    return 0;  
}  