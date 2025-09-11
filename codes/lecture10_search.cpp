// lecture10_search.cpp
// Examples of searching algorithms using arrays and functions

#include <iostream>
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

// Binary Search Function (for sorted arrays)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid; // Found at index mid
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    // Example array
    int arr[] = {12, 45, 23, 67, 89, 34, 56, 78};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Test Linear Search
    int target1 = 67;
    int result1 = linearSearch(arr, size, target1);
    if(result1 != -1) {
        cout << "Linear Search: " << target1 << " found at index " << result1 << endl;
    } else {
        cout << "Linear Search: " << target1 << " not found" << endl;
    }

    // Test with element not in array
    int target2 = 100;
    int result2 = linearSearch(arr, size, target2);
    if(result2 != -1) {
        cout << "Linear Search: " << target2 << " found at index " << result2 << endl;
    } else {
        cout << "Linear Search: " << target2 << " not found" << endl;
    }

    // Binary Search requires sorted array
    // Let's sort the array first (we'll implement bubble sort)
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Test Binary Search
    int result3 = binarySearch(arr, size, target1);
    if(result3 != -1) {
        cout << "Binary Search: " << target1 << " found at index " << result3 << endl;
    } else {
        cout << "Binary Search: " << target1 << " not found" << endl;
    }

    return 0;
}
