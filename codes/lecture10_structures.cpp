// lecture10_structures.cpp
// Using structures for complex data and simple queue implementation

#include <iostream>
#include <string>
using namespace std;

// Student structure from Module 4
struct Student {
    string name;
    int rollNumber;
    float marks;
    char grade;

    // Function to display student info
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
        cout << "------------------------" << endl;
    }

    // Function to calculate grade
    void calculateGrade() {
        if(marks >= 90) grade = 'A';
        else if(marks >= 80) grade = 'B';
        else if(marks >= 70) grade = 'C';
        else if(marks >= 60) grade = 'D';
        else grade = 'F';
    }
};

// Simple Queue structure
struct Queue {
    int arr[100];
    int front, rear, size;

    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue (add to rear)
    void enqueue(int x) {
        if(size >= 100) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
        cout << "Enqueued: " << x << endl;
    }

    // Dequeue (remove from front)
    int dequeue() {
        if(size <= 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int dequeued = arr[front];
        front = (front + 1) % 100;
        size--;
        cout << "Dequeued: " << dequeued << endl;
        return dequeued;
    }

    // Get front element
    int getFront() {
        if(size <= 0) return -1;
        return arr[front];
    }

    // Check if empty
    bool isEmpty() {
        return size == 0;
    }

    // Display queue
    void display() {
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for(int i = 0; i < size; i++) {
            cout << arr[(front + i) % 100] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Structures and Data Organization ---" << endl;

    // Create student records
    Student students[3];

    // Initialize students
    students[0] = {"Alice Johnson", 101, 95.5};
    students[1] = {"Bob Smith", 102, 87.2};
    students[2] = {"Charlie Brown", 103, 76.8};

    // Calculate grades and display
    for(int i = 0; i < 3; i++) {
        students[i].calculateGrade();
        students[i].display();
    }

    cout << "--- Simple Queue Demo ---" << endl;

    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    // Dequeue elements
    q.dequeue();
    q.display();

    // Add more
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    // Show front
    cout << "Front element: " << q.getFront() << endl;

    // Dequeue all
    while(!q.isEmpty()) {
        q.dequeue();
    }
    q.display();

    return 0;
}
