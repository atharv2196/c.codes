#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Add element to queue
    void enqueue(int val) {
        if (rear == SIZE - 1) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) {front = 0;}  // first insertion
        arr[++rear] = val;
    }
    //front bcome 0
    //1

    // Remove element from queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Removed: " << arr[front++] << endl;
    }

    // Display queue elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
// #include <iostream>
// using namespace std;

// template <typename T>
// class Queue {
//     int front, rear, size;
//     T* arr;

// public:
//     Queue(int cap) {
//         size = cap;
//         arr = new T[size];
//         front = rear = -1;
//     }

//     void enqueue(T val) {
//         if (rear == size - 1) {
//             cout << "Queue is full\n";
//             return;
//         }
//         if (front == -1) front = 0;
//         arr[++rear] = val;
//     }

//     void dequeue() {
//         if (front == -1 || front > rear) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << "Removed: " << arr[front++] << endl;
//     }

//     void display() {
//         if (front == -1 || front > rear) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << "Queue: ";
//         for (int i = front; i <= rear; ++i)
//             cout << arr[i] << " ";
//         cout << endl;
//     }

//     ~Queue() {
//         delete[] arr;
//     }
// };

// // 🔽 Usage:
// int main() {
//     Queue<int> q(5);  // <--- Here's your 'Queue<int>' like 'enqueue<int>'
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.display();
//     q.dequeue();
//     q.display();

//     return 0;
// }
