// lecture10_queue.cpp
// Queue implementation using linked list

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor to free memory
    ~Queue() {
        while(!isEmpty()) {
            dequeue();
        }
    }

    // Enqueue: Add element to rear
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if(rear == nullptr) {
            // Queue is empty
            front = rear = newNode;
        } else {
            // Add to rear
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued: " << x << endl;
    }

    // Dequeue: Remove element from front
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }

        int dequeuedValue = front->data;
        Node* temp = front;

        if(front == rear) {
            // Only one element
            front = rear = nullptr;
        } else {
            // Move front to next
            front = front->next;
        }

        delete temp;
        size--;
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    // Get front element
    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Get queue size
    int getSize() {
        return size;
    }

    // Display queue
    void display() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";
        Node* current = front;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Queue Implementation Demo ---" << endl;

    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    // Show front and rear
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    // Dequeue elements
    q.dequeue();
    q.display();

    // Add more elements
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    // Dequeue all
    cout << "\nDequeuing all elements:" << endl;
    while(!q.isEmpty()) {
        q.dequeue();
    }
    q.display();

    // Try to dequeue from empty queue
    q.dequeue();

    return 0;
}
