#include <iostream>
using namespace std;
// Stack implementation using an array
class StackArray {
private:
    int top;
    int arr[MAX_SIZE];

public:
    StackArray() {
        top = -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int isEmpty() {
        return (top == -1);
    }

    int isFull() {
        return (top == MAX_SIZE-1);
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "StackArr: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};