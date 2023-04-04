#include <iostream>
using namespace std;
class StackLL {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;

public:
    StackLL() : top(nullptr) {}

    ~StackLL() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        // Since a linked list can grow dynamically, it is never full.
        // However, you can add a limit on the size of the stackArray if needed.
        return false;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        cout << "StackLL: ";
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};