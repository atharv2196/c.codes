#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // 1. Vector: Dynamic array that can grow or shrink in size
    cout << "=== Vector Example ===\n";
    vector<int> vec = {1, 2, 3}; // Initialize vector with elements 1, 2, 3
    vec.push_back(4); // Add 4 to the end
    vec.emplace_back(5); // Add 5 to the end (more efficient than push_back)
    cout << "Vector elements: ";
    for (int x : vec) { // Print each element
        cout << x << " ";
    }
    // Output: Vector elements: 1 2 3 4 5
    // Explanation: Shows the vector's contents after adding 4 and 5
    cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    // Output: Size: 5, Capacity: 8 (or similar)
    // Explanation: Size is the number of elements (5). Capacity is the allocated memory space (may be >= size, e.g., 8 due to internal resizing)
    vec.pop_back(); // Remove the last element (5)
    cout << "After pop_back, size: " << vec.size() << endl;
    // Output: After pop_back, size: 4
    // Explanation: Size reduced to 4 after removing the last element

    // 2. List: Doubly-linked list, allows fast insertion/deletion
    cout << "\n=== List Example ===\n";
    list<int> lst = {10, 20, 30}; // Initialize list with 10, 20, 30
    lst.push_front(5); // Add 5 to the front
    lst.push_back(40); // Add 40 to the back
    cout << "List elements: ";
    for (int x : lst) {
        cout << x << " ";
    }
    // Output: List elements: 5 10 20 30 40
    // Explanation: Shows the list after adding 5 at the front and 40 at the back
    cout << "\nFront: " << lst.front() << ", Back: " << lst.back() << endl;
    // Output: Front: 5, Back: 40
    // Explanation: Front is the first element (5), back is the last element (40)
    lst.remove(20); // Remove all occurrences of 20
    cout << "After removing 20: ";
    for (int x : lst) {
        cout << x << " ";
    }
    // Output: After removing 20: 5 10 30 40
    // Explanation: The element 20 is removed from the list
    cout << endl;

    // 3. Deque: Double-ended queue, allows insertion/deletion at both ends
    cout << "\n=== Deque Example ===\n";
    deque<int> dq = {2, 3, 4}; // Initialize deque with 2, 3, 4
    dq.push_front(1); // Add 1 to the front
    dq.push_back(5); // Add 5 to the back
    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    // Output: Deque elements: 1 2 3 4 5
    // Explanation: Shows the deque after adding 1 at the front and 5 at the back
    cout << "\nFront: " << dq.front() << ", Back: " << dq.back() << endl;
    // Output: Front: 1, Back: 5
    // Explanation: Front is the first element (1), back is the last element (5)

    // 4. Array: Fixed-size array, safer than C-style arrays
    cout << "\n=== Array Example ===\n";
    array<int, 5> arr = {1, 2, 3, 4, 5}; // Fixed-size array of 5 elements
    cout << "Array elements: ";
    for (int x : arr) {
        cout << x << " ";
    }
    // Output: Array elements: 1 2 3 4 5
    // Explanation: Shows all elements in the fixed-size array
    cout << "\nElement at index 2: " << arr[2] << endl;
    // Output: Element at index 2: 3
    // Explanation: Accesses the element at index 2 (0-based indexing)

    // 5. Set: Sorted collection of unique elements
    cout << "\n=== Set Example ===\n";
    set<int> s = {3, 1, 4, 1, 5}; // Initialize set with elements (duplicates ignored)
    s.insert(2); // Insert 2 into the set
    cout << "Set elements (sorted, unique): ";
    for (int x : s) {
        cout << x << " ";
    }
    // Output: Set elements (sorted, unique): 1 2 3 4 5
    // Explanation: Set automatically removes duplicates (second 1 ignored) and sorts elements
    cout << "\nIs 4 present? " << (s.find(4) != s.end() ? "Yes" : "No") << endl;
    // Output: Is 4 present? Yes
    // Explanation: Checks if 4 exists in the set using find()

    // 6. Unordered Set: Unsorted collection of unique elements, faster operations
    cout << "\n=== Unordered Set Example ===\n";
    unordered_set<int> us = {3, 1, 4, 1, 5}; // Initialize unordered set (duplicates ignored)
    us.insert(2); // Insert 2
    cout << "Unordered Set elements: ";
    for (int x : us) {
        cout << x << " ";
    }
    // Output: Unordered Set elements: (e.g., 3 2 1 4 5, order may vary)
    // Explanation: Elements are unique but not sorted; order depends on hash function
    cout << "\nIs 4 present? " << (us.find(4) != us.end() ? "Yes" : "No") << endl;
    // Output: Is 4 present? Yes
    // Explanation: Checks if 4 exists in the unordered set

    // 7. Map: Sorted key-value pairs, unique keys
    cout << "\n=== Map Example ===\n";
    map<string, int> m; // Initialize empty map
    m["Alice"] = 25; // Add key "Alice" with value 25
    m["Bob"] = 30; // Add key "Bob" with value 30
    m.insert({"Charlie", 35}); // Add key "Charlie" with value 35
    cout << "Map elements: ";
    for (auto& p : m) { // Loop through key-value pairs
        cout << p.first << ":" << p.second << " ";
    }
    // Output: Map elements: Alice:25 Bob:30 Charlie:35
    // Explanation: Keys are sorted alphabetically; shows key-value pairs
    cout << "\nBob's age: " << m["Bob"] << endl;
    // Output: Bob's age: 30
    // Explanation: Accesses the value associated with key "Bob"

    // 8. Unordered Map: Unsorted key-value pairs, faster operations
    cout << "\n=== Unordered Map Example ===\n";
    unordered_map<string, int> um; // Initialize empty unordered map
    um["Alice"] = 25; // Add key "Alice" with value 25
    um["Bob"] = 30; // Add key "Bob" with value 30
    um.emplace("Charlie", 35); // Add key "Charlie" with value 35
    cout << "Unordered Map elements: ";
    for (auto& p : um) {
        cout << p.first << ":" << p.second << " ";
    }
    // Output: Unordered Map elements: (e.g., Bob:30 Alice:25 Charlie:35, order may vary)
    // Explanation: Keys are not sorted; order depends on hash function
    cout << "\nAlice's age: " << um["Alice"] << endl;
    // Output: Alice's age: 25
    // Explanation: Accesses the value associated with key "Alice"

    // 9. Stack: LIFO (Last In, First Out) container
    cout << "\n=== Stack Example ===\n";
    stack<int> stk; // Initialize empty stack
    stk.push(1); // Push 1
    stk.push(2); // Push 2
    stk.push(3); // Push 3
    cout << "Stack top: " << stk.top() << endl;
    // Output: Stack top: 3
    // Explanation: Top element is the last one pushed (LIFO)
    stk.pop(); // Remove top element (3)
    cout << "After pop, top: " << stk.top() << endl;
    // Output: After pop, top: 2
    // Explanation: After removing 3, 2 is now the top element

    // 10. Queue: FIFO (First In, First Out) container
    cout << "\n=== Queue Example ===\n";
    queue<int> q; // Initialize empty queue
    q.push(1); // Enqueue 1
    q.push(2); // Enqueue 2
    q.push(3); // Enqueue 3
    cout << "Queue front: " << q.front() << ", Back: " << q.back() << endl;
    // Output: Queue front: 1, Back: 3
    // Explanation: Front is the first element enqueued (1), back is the last (3)
    q.pop(); // Dequeue front element (1)
    cout << "After pop, front: " << q.front() << endl;
    // Output: After pop, front: 2
    // Explanation: After removing 1, 2 is now the front element

    // 11. Priority Queue: Queue with elements sorted by priority
    cout << "\n=== Priority Queue Example ===\n";
    priority_queue<int> pq; // Initialize max heap (highest value has highest priority)
    pq.push(3); // Add 3
    pq.push(1); // Add 1
    pq.push(4); // Add 4
    cout << "Priority Queue top: " << pq.top() << endl;
    // Output: Priority Queue top: 4
    // Explanation: Top element is the largest (max heap)
    pq.pop(); // Remove top element (4)
    cout << "After pop, top: " << pq.top() << endl;
    // Output: After pop, top: 3
    // Explanation: After removing 4, 3 is now the largest element

    // 12. Algorithm: sort - Sorting a vector
    cout << "\n=== Sort Example ===\n";
    vector<int> vec_sort = {5, 2, 9, 1, 5, 6}; // Initialize vector
    cout << "Before sorting: ";
    for (int x : vec_sort) {
        cout << x << " ";
    }
    // Output: Before sorting: 5 2 9 1 5 6
    // Explanation: Shows the unsorted vector
    sort(vec_sort.begin(), vec_sort.end()); // Sort in ascending order
    cout << "\nAfter ascending sort: ";
    for (int x : vec_sort) {
        cout << x << " ";
    }
    // Output: After ascending sort: 1 2 5 5 6 9
    // Explanation: Vector is sorted in ascending order
    sort(vec_sort.begin(), vec_sort.end(), greater<int>()); // Sort in descending order
    cout << "\nAfter descending sort: ";
    for (int x : vec_sort) {
        cout << x << " ";
    }
    // Output: After descending sort: 9 6 5 5 2 1
    // Explanation: Vector is sorted in descending order
    cout << endl;

    // 13. Algorithm: find - Searching in a vector
    cout << "\n=== Find Example ===\n";
    auto it = find(vec_sort.begin(), vec_sort.end(), 5); // Find element 5
    if (it != vec_sort.end()) {
        cout << "Element 5 found at position: " << (it - vec_sort.begin()) << endl;
    } else {
        cout << "Element 5 not found\n";
    }
    // Output: Element 5 found at position: 2
    // Explanation: Finds the first occurrence of 5 in the sorted vector (at index 2)

    return 0;
}