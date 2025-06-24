#include<iostream>
using namespace std;

// Node class to represent each element of the list
class Node {
public:
    int data;       // data stored in the node
    Node* prev;     // pointer to previous node
    Node* next;     // pointer to next node

    // Constructor (called when new Node is created)
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to insert node at the beginning
void insertAtHead(Node* &head, Node* &tail, int value) {
    Node* newNode = new Node(value);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert node at the end
void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* newNode = new Node(value);
    if(tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to insert at a specific position (1-based index)
void insertAtPosition(Node* &head, Node* &tail, int pos, int value) {
    if(pos == 1) {
        insertAtHead(head, tail, value);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail, value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at a given position
void deleteAtPosition(Node* &head, Node* &tail, int pos) {
    if(head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if(pos == 1) {
        Node* temp = head;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            head = tail = NULL;
        }
        delete temp;
        return;
    }

    Node* curr = head;
    int count = 1;

    while(count < pos && curr != NULL) {
        curr = curr->next;
        count++;
    }

    if(curr == NULL) {
        cout << "Position out of bounds.\n";
        return;
    }

    if(curr->next == NULL) {
        tail = curr->prev;
        tail->next = NULL;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
}

// Function to print list from head to tail
void printForward(Node* head) {
    cout << "List (Forward): ";
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to print list from tail to head
void printBackward(Node* tail) {
    cout << "List (Backward): ";
    while(tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

// ✅ Main function with menu
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value, pos;
        switch(choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head, tail, value);
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(head, tail, value);
                break;

            case 3:
                cout << "Enter position and value to insert: ";
                cin >> pos >> value;
                insertAtPosition(head, tail, pos, value);
                break;

            case 4:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, tail, pos);
                break;

            case 5:
                printForward(head);
                break;

            case 6:
                printBackward(tail);
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while(choice != 7);

    return 0;
}
