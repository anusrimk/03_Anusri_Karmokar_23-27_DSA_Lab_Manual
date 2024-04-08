#include <iostream>

using namespace std;


int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, left half ko ignore karna hai
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore right half vale ko since sorted
        else
            right = mid - 1;
    }

    // If the element is not present in the array
    return -1;
}

int main() {
    int n; 
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;


    int index = binarySearch(arr, n, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
