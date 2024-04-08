#include <iostream>
using namespace std;


class CircularQueue {
private:
    int front, rear;
    int capacity;
    int* arr;

public:
    CircularQueue(int size) {
        capacity = size + 1; 
        arr = new int[capacity];
        front = rear = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rear] = item;
        rear = (rear + 1) % capacity;
        cout << "Enqueued " << item << endl;
    }

    int dequeue() {
        if (front == rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        cout << "Dequeued " << item << endl;
        return item;
    }

    int peek() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    int choice, value;
    do {
        cout << "\nCircular Queue Operations:\n";
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
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                value = cq.peek();
                if (value != -1)
                    cout << "Front element: " << value << endl;
                break;
            case 4:
                if (cq.isEmpty())
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
