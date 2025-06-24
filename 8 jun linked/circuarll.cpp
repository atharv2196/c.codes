#include<iostream>
using namespace std;

// 🧱 Step 1: Make a Node class (like one box in a chain)
class Node {
public:
    int data;     // this will store the number (like 5, 10, etc.)
    Node* next;   // this will point to the next box

    // 🚪 This is a constructor - it's called when you create a new box
    Node(int value) {
        data = value;    // put the number inside the box
        next = NULL;     // right now, it's not connected to anyone
    }
};

// 🧩 Step 2: Add a new node at the BEGINNING of the circle
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node(value);  // make a new box with value

    if (head == NULL) {
        // if there is no box yet, make a circle with just one box
        newNode->next = newNode;
        head = newNode;
        return;
    }

    // if boxes already exist, go to the last one
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // now connect everything in a circle
    newNode->next = head;  // new box points to old first box
    temp->next = newNode;  // last box now points to new box
    head = newNode;        // new box becomes the first box
}

// 🧩 Step 3: Add a new node at the END of the circle
void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node(value);  // make a new box

    if (head == NULL) {
        newNode->next = newNode;  // only one box points to itself
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;     // last box points to new box
    newNode->next = head;     // new box points back to first
}

// 🧹 Step 4: Remove a box from a certain position
void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    // 🗑 Deleting the first box
    if (position == 1) {
        Node* temp = head;

        // if only one box exists
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        // more than one box
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        head = head->next;     // move head to next box
        last->next = head;     // last box points to new head
        delete temp;           // delete the old head
        return;
    }

    // 📍 Deleting from middle or end
    Node* curr = head;
    int count = 1;

    while (count < position - 1 && curr->next != head) {
        curr = curr->next;
        count++;
    }

    // If position is too big
    if (curr->next == head || curr->next == NULL) {
        cout << "Position is out of range.\n";
        return;
    }

    Node* toDelete = curr->next;        // the box to delete
    curr->next = toDelete->next;        // skip over it
    delete toDelete;                    // delete the box
}

// 👀 Step 5: Show all boxes one by one
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";  // print the number in the box
        temp = temp->next;          // go to next box
    } while (temp != head);         // stop when we reach the start
    cout << endl;
}

// 🎮 Step 6: Menu to let user choose actions
int main() {
    Node* head = NULL;   // list starts empty

    int choice, value, pos;

    do {
        // 📋 Menu shown to the user
        cout << "\n--- Circular Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 🕹️ What the user chooses
        switch(choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Bye! Program ended.\n";
                break;

            default:
                cout << "That's not a valid option! Try again.\n";
        }

    } while(choice != 5);  // keep going until user chooses to exit

    return 0;
}
