#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int top; 
    int arr[MAX_SIZE]; 

public:
    Stack() {
        top = -1; 
    }


    void push(int val) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val; 
    }


    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--; 
    }


    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1; 
        }
        return arr[top]; 

    }
    bool isEmpty() {
        return top == -1;
    
    }

};

int main() {
    Stack stack;

    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Top element after pop: " << stack.peek() << ::endl;

    return 0;
}
