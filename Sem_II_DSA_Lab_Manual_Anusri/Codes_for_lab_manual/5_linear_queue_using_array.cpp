#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = item;
        cout << "Enqueued " << item << endl;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front++];
        cout << "Dequeued " << item << endl;
        return item;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    int choice, value;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if empty\n";
        cout << "5. Exit\n";
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
                value = q.peek();
                if (value != -1)
                    cout << "Front element: " << value << endl;
                break;
            case 4:
                if (q.isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;
            case 5:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
