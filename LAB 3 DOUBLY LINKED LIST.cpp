#include <iostream>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

int main()
{
    const int N = 5;

    // Create five nodes dynamically using new
    Node* nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node;

    // Take five integer values from the user
    cout << "Enter " << N << " integer values: ";
    for (int i = 0; i < N; i++)
        cin >> nodes[i]->data;

    // Connect all nodes using prev and next pointers
    for (int i = 0; i < N; i++)
    {
        nodes[i]->prev = (i == 0)     ? NULL : nodes[i - 1];  // first node's prev = NULL
        nodes[i]->next = (i == N - 1) ? NULL : nodes[i + 1];  // last node's next = NULL
    }

    Node* head = nodes[0];
    Node* last = nodes[N - 1];

    // Forward traversal (head -> last)
    cout << "\nForward Traversal:\n";
    Node* temp = head;
    int count = 0;                  // counter incremented once per visited node
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;

    // Backward traversal (last -> head)
    cout << "\nBackward Traversal:\n";
    temp = last;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;

    // Display total number of nodes
    cout << "\nTotal Nodes: " << count << endl;

    // Release memory: save next pointer before deleting current node
    temp = head;
    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
