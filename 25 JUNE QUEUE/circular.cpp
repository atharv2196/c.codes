#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add element to circular queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        }
        else {
            // Move rear in circular way
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;
    }

    // Remove element from circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        // Queue has only one element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            // Move front in circular way
            front = (front + 1) % SIZE;
        }
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Circular Queue: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); // Queue is full here
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.display();
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}
