#include <iostream>
using namespace std;

//  Bubble Sort in ascending order
void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Bubble Sort in descending order
void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n; 
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bubbleSortAscending(arr, n);

    // in ascending order
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

  
    bubbleSortDescending(arr, n);

    //  in descending order
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
