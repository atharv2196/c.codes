#include<iostream>
#include<map>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int value;         // Stores data
    Node* next;        // Pointer to next node

    // Constructor
    Node(int data) {
        value = data;
        next = NULL;
    }

    // Destructor (automatically frees memory of next nodes)
    ~Node() {
        int data = value;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with value " << data << endl;
    }
};

// Insert node at the beginning (head)
void insertAtStart(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insert node at the end (tail)
void insertAtEnd(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Insert node at a specific position
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    // Insert at the beginning
    if (position == 1) {
        insertAtStart(head, data);
        return;
    }

    Node* current = head;
    int count = 1;

    // Traverse to (position - 1)th node
    while (count < position - 1) {
        current = current->next;
        count++;
    }

    // If inserting at end
    if (current->next == NULL) {
        insertAtEnd(tail, data);
        return;
    }

    // Insert in the middle
    Node* newNode = new Node(data);
    newNode->next = current->next;
    current->next = newNode;
}

// Delete a node at given position
void deleteNode(int position, Node* &head) {
    // If deleting the first node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* current = head;
        Node* previous = NULL;
        int count = 1;

        while (count < position) {
            previous = current;
            current = current->next;
            count++;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

// Print the linked list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Check if the list is circular
bool isCircular(Node* head) {
    if (head == NULL) return true;

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

// Detect loop using a map
bool hasLoop(Node* head) {
    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != NULL) {
        if (visited[temp]) {
            cout << "Loop detected at node with value " << temp->value << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// Floyd’s Cycle Detection Algorithm (fast and slow pointer)
Node* detectLoop(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Loop found at node with value " << slow->value << endl;
            return slow;
        }
    }

    return NULL;
}

// Find the starting node of the loop
Node* findLoopStart(Node* head) {
    Node* intersection = detectLoop(head);
    if (!intersection) return NULL;

    Node* start = head;
    while (start != intersection) {
        start = start->next;
        intersection = intersection->next;
    }

    return start;
}

// Remove the loop from the list
void removeLoop(Node* head) {
    Node* loopStart = findLoopStart(head);
    if (!loopStart) return;

    Node* temp = loopStart;
    while (temp->next != loopStart) {
        temp = temp->next;
    }

    temp->next = NULL;  // Break the loop
}
