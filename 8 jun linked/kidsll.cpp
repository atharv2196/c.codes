#include<iostream>
using namespace std;

// This is a class (like a template or blueprint) to create each item in the list.
// Think of each Node as a "record" or "entry" in your list, holding some data (a number) and a link to the next one.
class Node {
public:
    int data;       // This holds the value for the current item (like an ID or value).
    Node* next;     // This is a pointer (a link) to the next item in the list.

    // This constructor is used when we create a new Node. It stores the value and sets the next link to NULL (no link yet).
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// This is the starting point of our list. It's like the name of your list or the pointer to the first record.
Node* head = NULL;

// Function to insert a value at a specific position in the list.
void insertAtPosition(int val, int pos) {
    // Create a new item (Node) to insert
    Node* newNode = new Node(val);

    // If inserting at the start (position 1), update the head
    if (pos == 1) {
        newNode->next = head;  // New item will point to the current first item
        head = newNode;        // Head now becomes this new item
        cout << "Inserted " << val << " at position " << pos << endl;
        return;
    }

    // If inserting somewhere else, we need to move to the previous item (position - 1)
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;  // Move forward one item at a time
    }

    // If we reached the end before finding the correct place, it's an invalid position
    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;  // Delete the unused item to avoid memory waste
        return;
    }

    // Link the new item between previous and next
    newNode->next = temp->next;  // New item points to the next item in the list
    temp->next = newNode;        // Previous item points to the new item

    cout << "Inserted " << val << " at position " << pos << endl;
}

// Function to delete an item at a given position
void deleteAtPosition(int pos) {
    // If list is empty, there’s nothing to delete
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    // If deleting the first item
    if (pos == 1) {
        head = head->next;                // Move head to point to the next item
        cout << "Deleted element: " << temp->data << endl;
        delete temp;                      // Free the memory for removed item
        return;
    }

    // Move to the item just before the one we want to delete
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid or next item doesn't exist
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Remove the item from the list
    Node* nodeToDelete = temp->next;        // This is the item to be removed
    temp->next = nodeToDelete->next;        // Link previous item directly to the one after the deleted item
    cout << "Deleted element: " << nodeToDelete->data << endl;
    delete nodeToDelete;                    // Free the memory of removed item
}

// Function to display all items in the list
void displayList() {
    Node* temp = head;

    // If no items in list, show message
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // Display the list like a chain of values
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";  // Show the current value and point to next
        temp = temp->next;             // Move to next item
    }
    cout << "NULL" << endl;           // Indicate the end of the list
}

// Main function with menu for user to choose options
int main() {
    int choice, value, position;

    do {
        // Show options to the user
        cout << "\nWhat do you want to do?\n";
        cout << "1. Insert a number at a specific position\n";
        cout << "2. Delete a number from a specific position\n";
        cout << "3. Show all numbers in the list\n";
        cout << "4. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user choice
        switch (choice) {
        case 1:
            cout << "Enter the number to insert: ";
            cin >> value;
            cout << "Enter the position (start from 1): ";
            cin >> position;
            insertAtPosition(value, position);
            break;
        case 2:
            cout << "Enter the position to delete from (start from 1): ";
            cin >> position;
            deleteAtPosition(position);
            break;
        case 3:
            displayList();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);  // Repeat until user chooses to exit

    return 0;
}
