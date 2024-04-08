#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Dequeue all elements and deallocate memory
        }
    }

    // Function to enqueue an element
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << endl;
    }

    // Function to dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr; // If queue becomes empty, rear also becomes null
        }
        cout << "Dequeued " << value << endl;
        return value;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    int choice, value;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if empty\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;
            case 4:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
