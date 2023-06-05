#include <iostream>

using namespace std;

// Node class representing a node in the linked list
class Node {
public:
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class representing the overall linked list
class LinkedList {
private:
    Node* head;       // Pointer to the head (first) node of the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the list
    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert a new node at the middle of the list
    void insertAtMiddle(int value, int position) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            int count = 1;
            while (temp != nullptr && count < position - 1) {
                temp = temp->next;
                count++;
            }
            if (temp == nullptr) {
                cout << "Position out of range" << endl;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;

    // Inserting nodes at first, middle, and last positions
    list.insertAtFirst(10);
    list.insertAtFirst(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtMiddle(25, 2);

    // Displaying the linked list
    cout << "Linked List: ";
    list.display();

    return 0;
}
