// lecture10_stack.cpp
// Stack implementation using arrays and structures

#include <iostream>
using namespace std;

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;

    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int x) {
        if(top >= MAX_SIZE-1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " onto stack" << endl;
    }

    // Pop operation
    int pop() {
        if(top < 0) {
            cout << "Stack Underflow! Stack is empty" << endl;
            return -1;
        }
        int popped = arr[top--];
        cout << "Popped " << popped << " from stack" << endl;
        return popped;
    }

    // Peek operation
    int peek() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Get stack size
    int size() {
        return top + 1;
    }

    // Display stack
    void display() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    cout << "--- Stack Operations Demo ---" << endl;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    // Peek at top
    cout << "Top element: " << s.peek() << endl;

    // Pop elements
    s.pop();
    s.display();

    // Push more
    s.push(40);
    s.push(50);
    s.display();

    // Check size
    cout << "Stack size: " << s.size() << endl;

    // Pop all
    while(!s.isEmpty()) {
        s.pop();
    }
    s.display();

    // Try to pop from empty stack
    s.pop();

    return 0;
}
