#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;     // Data part
    Node* next;   // Pointer to the next node

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);  // Create a new node

    if (head == nullptr) {
        head = newNode;  // If list is empty, make newNode the head
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;  // Move to the last node
    }
    temp->next = newNode;   // Attach the new node
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";  // Print data
        temp = temp->next;            // Move to the next node
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;  // Start with an empty list
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Taking input and inserting into the linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insert(head, value);
    }

    // Display the linked list
    cout << "Linked List: ";
    display(head);

    return 0;
} 