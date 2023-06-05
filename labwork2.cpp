#include <iostream>

using namespace std;

// Node class to represent each element in the linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to search for a given key in the linked list
Node *search(Node *head, int key)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

// Function to split a linked list into two halves
void split(Node *head, Node **firstHalf, Node **secondHalf)
{
    if (head == nullptr || head->next == nullptr)
    {
        *firstHalf = head;
        *secondHalf = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = nullptr;
}

// Function to merge two sorted linked lists
Node *merge(Node *first, Node *second)
{
    if (first == nullptr)
    {
        return second;
    }
    if (second == nullptr)
    {
        return first;
    }

    Node *result = nullptr;
    if (first->data <= second->data)
    {
        result = first;
        result->next = merge(first->next, second);
    }
    else
    {
        result = second;
        result->next = merge(first, second->next);
    }

    return result;
}

// Function to display the linked list
void display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // Create a sample linked list
    Node *head = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(7);
    Node *fifth = new Node(9);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Original Linked List: ";
    display(head);

    // Search for a key in the linked list
    int key = 5;
    Node *foundNode = search(head, key);
    if (foundNode != nullptr)
    {
        cout << key << " is found in the linked list." << endl;
    }
    else
    {
        cout << key << " not found in the linked list." << endl;
    }

    // Split the linked list into two halves
    Node *firstHalf = nullptr;
    Node *secondHalf = nullptr;
    split(head, &firstHalf, &secondHalf);
    cout << "First Half of Linked List: ";
    display(firstHalf);
    cout << "Second Half of Linked List: ";
    display(secondHalf);

    // Merge two sorted linked lists
    Node *list1 = new Node(2);
    Node *list2 = new Node(4);
    list1->next = new Node(6);
    list2->next = new Node(8);

    cout << "After merge Linked List: ";
    display(merge(list1, list2));

    return 0;
}
