#include<iostream>
using namespace std;

// Node representing a service request
class Node {
public:
    int id;
    string name;
    string type;
    Node* next;

    Node(int id, string name, string type) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->next = NULL;
    }
};

// Queue front and rear
Node* front = NULL;
Node* rear = NULL;

// Enqueue: Add new request to rear
void enqueue(int id, string name, string type) {
    Node* newNode = new Node(id, name, type);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Request added successfully.\n";
}

// Dequeue: Process request from front
void dequeue() {
    if (front == NULL) {
        cout << "No requests to process.\n";
        return;
    }

    Node* temp = front;
    cout << "Processing Request ID: " << temp->id << ", Name: " << temp->name << ", Type: " << temp->type << endl;

    front = front->next;
    if (front == NULL) rear = NULL; // If list became empty

    delete temp;
}

// Display all pending requests
void displayQueue() {
    if (front == NULL) {
        cout << "No pending requests.\n";
        return;
    }

    Node* temp = front;
    cout << "\nPending Requests:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Type: " << temp->type << endl;
        temp = temp->next;
    }
}

// Main function with menu
int main() {
    // Add initial requests
    

    int choice;
    do {
        cout << "\n--- Call Center Service Request Manager ---\n";
        cout << "1. Add New Request\n";
        cout << "2. Process Next Request\n";
        cout << "3. Display Pending Requests\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string name, type;

        switch (choice) {
            case 1:
                cout << "Enter Request ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Customer Name: ";
                getline(cin, name);
                cout << "Enter Service Type: ";
                getline(cin, type);
                enqueue(id, name, type);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
