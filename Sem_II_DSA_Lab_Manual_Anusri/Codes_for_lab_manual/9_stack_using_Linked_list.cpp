#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Stack {
    private:
        Node* top;

    public:
    Stack() {
        top = nullptr; 
    }

    void push(int data) {
        Node* newNode = new Node; 
        newNode->data = data;
        newNode->next = top; 
        top = newNode; 
        cout << "Element " << data << " pushed successfully." << endl;
    }

    int pop() {
        if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1; 
        }
        Node* temp = top;  
        int data = temp->data;
        top = top->next; 
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
  Stack s;
  s.push(1);
  s.push(22);
  s.push(10);
  cout << s.pop() << " popped\n"; 
  cout << s.pop() << " popped\n";
  return 0;
}
