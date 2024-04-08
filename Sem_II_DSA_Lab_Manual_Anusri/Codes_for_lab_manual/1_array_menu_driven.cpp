#include <iostream>
using namespace std;

void displayMenu() {
  cout << "Select an option" << endl;
  cout << "1. Insert Element at Beginning" << endl;
  cout << "2. Insert Element at End (Appending)" << endl;
  cout << "3. Insert Element Before an element" << endl;
  cout << "4. Insert Element After an element" << endl;
  cout << "5. Delete Element at Beginning" << endl;
  cout << "6. Delete Element at End" << endl;
  cout << "7. Delete Element Before the Reference" << endl;
  cout << "8. Delete Element After the Reference" << endl;
  cout << "9. Search Element" << endl;
  cout << "10. Sort Array" << endl;
  cout << "11. Display Array" << endl;
  cout << "0. Exit" << endl;
}

void insertElementAtBeginning(int arr[], int &size, int element) {
  if (size == 0) {
    arr[size++] = element;
  } else {
    for (int i = size; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
  }
  cout << "Element inserted at the beginning successfully!" << endl;
}

void insertElementAtEnd(int arr[], int &size, int element) {
  arr[size++] = element;
  cout << "Element inserted at the end successfully!" << endl;
}

void insertElementBeforeReference(int arr[], int &size, int element,
  int reference) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == reference) { 
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = size; i > index; i--) {
      arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
    cout << "Element inserted before the reference successfully!" << endl;
  } else {
    cout << "Reference element not found!" << endl;
  }
}

void insertElementAfterReference(int arr[], int &size, int element,
                                 int reference) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == reference) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = size; i > index + 1; i--) {
      arr[i] = arr[i - 1];
    }
    arr[index + 1] = element;
    size++;
    cout << "Element inserted after the reference successfully!" << endl;
  } else {
    cout << "Reference element not found!" << endl;
  }
}

void deleteElementAtBeginning(int arr[], int &size) {
  if (size == 0) {
    cout << "Array is empty, no elements to delete!" << endl;
    return;
  }
  for (int i = 0; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
  cout << "Element at the beginning deleted successfully!" << endl;
}

void deleteElementAtEnd(int arr[], int &size) {
  if (size == 0) {
    cout << "Array is empty, no elements to delete!" << endl;
    return;
  }
  size--;
  cout << "Element at the end deleted successfully!" << endl;
}

void deleteElementBeforeReference(int arr[], int &size, int reference) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == reference) {
      index = i - 1;
      break;
    }
  }
  if (index != -1 && index < size) {
    deleteElementAtBeginning(arr + index, size);
  } else {
    cout << "Reference element not found or it is the first element!" << endl;
  }
}

void deleteElementAfterReference(int arr[], int &size, int reference) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == reference) {
      index = i + 1;
      break;
    }
  }
  if (index != -1 && index < size) {
    deleteElementAtBeginning(arr + index - 1, size);
  } else {
    cout << "Reference element not found or it is the last element!" << endl;
  }
}

void displayArray(const int arr[], int size) {
  cout << "Array: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int searchElement(const int arr[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == element)
      return i;
  }
  return -1;
}

void sortArray(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  cout << "Array sorted successfully!" << endl;
}

int main() {
  const int MAX_SIZE = 100;
  int arr[MAX_SIZE];
  int size = 0;

  int choice;
  do {
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int element;
      cout << "Enter element to insert at the beginning: ";
      cin >> element;
      insertElementAtBeginning(arr, size, element);
      break;
    }
    case 2: {
      int element;
      cout << "Enter element to append at the end: ";
      cin >> element;
      insertElementAtEnd(arr, size, element);
      break;
    }
    case 3: {
      int element, reference;
      cout << "Enter element to insert: ";
      cin >> element;
      cout << "Enter reference element: ";
      cin >> reference;
      insertElementBeforeReference(arr, size, element, reference);
      break;
    }
    case 4: {
      int element, reference;
      cout << "Enter element to insert: ";
      cin >> element;
      cout << "Enter reference element: ";
      cin >> reference;
      insertElementAfterReference(arr, size, element, reference);
      break;
    }
    case 5: {
      deleteElementAtBeginning(arr, size);
      break;
    }
    case 6: {
      deleteElementAtEnd(arr, size);
      break;
    }
    case 7: {
      int reference;
      cout << "Enter reference element: ";
      cin >> reference;
      deleteElementBeforeReference(arr, size, reference);
      break;
    }
    case 8: {
      int reference;
      cout << "Enter reference element: ";
      cin >> reference;
      deleteElementAfterReference(arr, size, reference);
      break;
    }
    case 9: {
      int element;
      cout << "Enter element to search: ";
      cin >> element;
      int index = searchElement(arr, size, element);
      if (index != -1)
        cout << "Element found at index " << index << endl;
      else
        cout << "Element not found in the array!" << endl;
      break;
    }
    case 10: {
      sortArray(arr, size);
      break;
    }
    case 11: {
      displayArray(arr, size);
      break;
    }
    case 0: {
      cout << "Exiting..." << endl;
      break;
    }
    default:
      cout << "Invalid choice!" << endl;
    }
  } while (choice);

  return 0;
}
