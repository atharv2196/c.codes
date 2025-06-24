#include<iostream>
using namespace std;

// Node class to represent each element of the list
class Node {
public:
    string name;
    int quantity; 
    float price;      // data stored in the node
    Node* prev;     // pointer to previous node
    Node* next;     // pointer to next node

    // Constructor (called when new Node is created)
    Node(float price,string name,int quantity) {
        this->price=price;
        this->name=name;
        this->quantity=quantity;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to insert node at the beginning
void insertAtHead(Node* &head, Node* &tail, int quan,string nm,float pr) {
    Node* newNode = new Node(pr,nm,quan);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert node at the end
void insertAtTail(Node* &head, Node* &tail, int quan,string nm,float pr) {
    Node* newNode = new Node(pr,nm,quan);
    if(tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to insert at a specific position (1-based index)
void insertAtPosition(Node* &head, Node* &tail, int pos, int quan,string nm,float pr) {
    if(pos == 1) {
        insertAtHead(head, tail, quan,nm,pr);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail,quan,nm,pr);
        return;
    }

    Node* newNode = new Node(pr,nm,quan);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at a given position
void deleteAtPosition(Node* &head, Node* &tail, int pos ) {
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
    cout << "List (Forward): \n";

    while(head != NULL) {
        cout << head->name<<endl;
        cout << head->quantity<<endl;
        cout << head->price<<endl;
        head = head->next;
        cout<<"V"<<endl;
    }
    cout << endl;
}

// Function to print list from tail to head
void printBackward(Node* tail) {
    cout << "List (Backward): \n";
    while(tail != NULL) {
        cout << tail->name<<endl;
        cout << tail->quantity<<endl;
        cout << tail->price<<endl;
        tail = tail->prev;
        cout<<"V"<<endl;
    }
    cout << endl;
}

// ✅ Main function with menu
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    do {
        cout << "\n--- welcome to stocks ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int quan, pos;
        string nm;
        float pr;
        switch(choice) {
            case 1:
                cout << "name enter ";
                cin >> nm;
                cout << "Price enter ";
                cin >> pr;
                cout << "quantity enter ";
                cin >> quan;
                
                

                insertAtHead(head, tail, quan,nm,pr);
                break;

            case 2:
                cout << "name enter ";
                cin >> nm;
                cout << "Price enter ";
                cin >> pr;
                cout << "quantity enter ";
                cin >> quan;
                insertAtTail(head, tail, quan,nm,pr);
                break;

            case 3:
                cout << "Enter position  ";
                cin >> pos;
                cout << "name enter ";
                cin >> nm;
                cout << "Price enter ";
                cin >> pr;
                cout << "quantity enter ";
                cin >> quan;

                insertAtPosition(head, tail, pos,quan,nm,pr);
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
//Implement a doubly circular linked list to efficiently manage customer orders in a retail management system. Each order consists of items with details like name, quantity, and price. The linked list structure should represent each order, with nodes corresponding to individual items. Essential functionalities include adding, removing, and updating items, as well as displaying order contents. The system must dynamically adjust to varying order sizes and offer search and retrieval capabilities for specific items. This implementation aims to streamline the order management process, ensuring quick access and updates within the retail system 