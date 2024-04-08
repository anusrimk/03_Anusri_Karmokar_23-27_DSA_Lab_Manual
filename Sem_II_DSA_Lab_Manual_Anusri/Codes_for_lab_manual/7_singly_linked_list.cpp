#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
  int data;
  Node* next;
};

// SinglyLinkedList class
class SinglyLinkedList {
 public:
  // Constructor
  SinglyLinkedList() {
    head = nullptr;
  }


  // Function to insert a node at the beginning of the list
  void insertAtBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printChange("Inserted " + to_string(data) + " at beginning");
  }

  // Function to insert a node at the end of the list
  void insertAtEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      printChange("Inserted " + to_string(data) + " at end");
      return;
    }

    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
    printChange("Inserted " + to_string(data) + " at end");
  }

  // Function to delete a node with a specific value
  void deleteNode(int value) {
    if (head == nullptr) {
      return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
      previous = current;
      current = current->next;
    }

    if (current == nullptr) {
      // Value not found
      return;
    }


    if (previous == nullptr) {
      // Delete head node
      head = current->next;
    } else {
      previous->next = current->next;
    }

    delete current;
    printChange("Deleted node with value " + to_string(value));
  }

  // Function to print the contents of the list
  void printList() {
    Node* current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "NULL" << endl;
  }

  // Function to check if the list is empty
  bool isEmpty() {
    return head == nullptr;
  }

 private:
  Node* head;  // Head pointer of the linked list

  // Function to clear the list (optional)
  void clear() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Helper function to print change message
  void printChange(const string& message) {
    cout << message << endl;
    printList();
  }
};

int main() {
  SinglyLinkedList list;

  list.insertAtEnd(10);
  list.insertAtBeginning(5);
  list.insertAtEnd(15);
  list.insertAtBeginning(2);

  cout << "Final List: ";
  list.printList();

  list.deleteNode(10);

  cout << "After delete(10): ";
  list.printList();

  return 0;
}
