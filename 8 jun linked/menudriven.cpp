#include<iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;       // value in the node
    Node* next;     // pointer to next node

    // constructor to initialize a node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Head pointer to the start of the list
Node* head = NULL;

// Function to insert a node at given position
void insertAtPosition(int val, int pos) {
    Node* newNode = new Node(val);

    // insert at beginning
    if (pos == 1) {
        newNode->next = head;//next declare null here
        head = newNode;//val inserted at head through objected name d newnode
        cout << "Inserted " << val << " at position " << pos << endl;
        return;
    }

    // Traverse to (pos - 1)th node
    Node* temp = head;//recent head stored in temp
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;//next declare null here if pos is greater than length of list
    }

    // Invalid position
    if (temp == NULL) {//head is null or pos is greater than length of list
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    // Insert new node
    newNode->next = temp->next;//next of newnode is pointing to next of temp
    temp->next = newNode;//next of temp is pointing to newnode indirectly to val 

    cout << "Inserted " << val << " at position " << pos << endl;
}

// Function to delete node at given position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }           

    Node* temp = head;

    // Delete head node
    if (pos == 1) {
        head = head->next;
        cout << "Deleted element: " << temp->data << endl;
        delete temp;
        return;
    }

    // Traverse to (pos - 1)th node
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Delete the node
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted element: " << nodeToDelete->data << endl;
    delete nodeToDelete;
}

// Function to display the list
void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function with menu
int main() {
    int choice, value, position;

    do {
        cout << "\nWhat to do\n";
        cout << "1. Insert at reqn position\n";
        cout << "2. Delete at req position\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to u want to insert: ";
            cin >> value;
            cout << "Enter position to insert at :(st from 1): ";
            cin >> position;
            insertAtPosition(value, position);
            break;
        case 2:
            cout << "Enter position to delete from (1-based): ";
            cin >> position;
            deleteAtPosition(position);
            break;
        case 3:
            displayList();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
