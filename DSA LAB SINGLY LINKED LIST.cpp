#include <iostream>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;
    Node* next;
};

// Traverse the list, print it, and return the number of nodes
int displayAndCount(Node* head)
{
    int count = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
    return count;
}

// Release every node safely using a loop
void freeList(Node* head)
{
    while (head != NULL)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

int main()
{
    // ---------- Lab Practice Tasks (fixed values 5,10,15,20,25) ----------
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;

    head->data = 5;    head->next = second;
    second->data = 10; second->next = third;
    third->data = 15;  third->next = fourth;
    fourth->data = 20; fourth->next = fifth;
    fifth->data = 25;  fifth->next = NULL;

    cout << "Part 1 - Fixed values" << endl;
    cout << "Linked List: ";
    int total = displayAndCount(head);
    cout << "Total nodes: " << total << endl << endl;
    freeList(head);

    // ---------- Challenge Question (values from the user) ----------
    cout << "Part 2 - User input" << endl;
    cout << "Enter 5 integer values: ";

    Node* userHead = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = NULL;

        if (userHead == NULL)
            userHead = newNode;      // first node becomes head
        else
            tail->next = newNode;    // link previous last node to new one
        tail = newNode;
    }

    cout << "Linked List: ";
    total = displayAndCount(userHead);
    cout << "Total nodes: " << total << endl;

    freeList(userHead);
    return 0;
}
