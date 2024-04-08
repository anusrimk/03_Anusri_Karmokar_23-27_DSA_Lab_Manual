#include <iostream>

using namespace std;

// Node class for circular linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head; // Pointer to the head of the circular linked list

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr)
            return;

        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

    // Function to insert a new node at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Pointing back to itself for circularity
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a new node at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Pointing back to itself for circularity
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;
        }
    }

    // Function to delete a node from the beginning of the circular linked list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty. Deletion not possible." << endl;
            return;
        }
        Node* temp = head;
        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    // Function to delete a node from the end of the circular linked list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty. Deletion not possible." << endl;
            return;
        }
        Node* temp = head;
        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next->next != head) {
                last = last->next;
            }
            Node* toDelete = last->next;
            last->next = head;
            delete toDelete;
        }
    }

    // Function to display the elements of the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.display();

    // Inserting elements into the circular linked list
    cll.insertAtBeginning(5);
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(15);

    // Displaying elements of the circular linked list
    cout << "Circular Linked List after inserting at beginning: ";
    cll.display();

    // Inserting elements at the end
    cll.insertAtEnd(20);
    cll.insertAtEnd(25);

    // Displaying elements of the circular linked list
    cout << "Circular Linked List after inserting at end: ";
    cll.display();

    // Deleting elements from the beginning and end
    cll.deleteFromBeginning();
    cll.deleteFromEnd();

    // Displaying elements of the circular linked list
    cout << "Circular Linked List after deletion from beginning and end: ";
    cll.display();

    return 0;
}
