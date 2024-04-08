#include <iostream>
using namespace std;


class Stack {
private:
    int top; 
    int arr[100]; 

public:
    Stack() {
        top = -1; 
    }


    void push(int val) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val; 
    }


    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--]; 
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

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int evaluatePostfix(char exp[], int length) {
    Stack stack;
    for (int i = 0; i < length; ++i) {
        char c = exp[i];
        if (isDigit(c)) {
            stack.push(c - '0'); 
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid expression\n";
                    return -1;
            }
        }
    }
    return stack.pop();
}

int main() {
    char exp[100];
    cout << "Enter postfix expression: ";
    cin.getline(exp, 100);

    int length = 0;
    while (exp[length] != '\0') {
        length++;
    }

    cout << "Result: " << evaluatePostfix(exp, length) << endl;
    return 0;
}
