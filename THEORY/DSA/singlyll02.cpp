#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = nullptr;
};

class LinkedList{
    Node* Head = nullptr;
    public:
    // Insert
    void insert(int value)
{
        /*Create a new node*/
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        /*If the list is empty*/
        if (Head == nullptr)
        {
            Head = newNode;
            return;
        }

        /*Traverse to the last node*/
        Node* temp = Head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        /*Link the last node to the new node*/
        temp->next = newNode;
}
    // Delete
    // Update
    // Sort
    // Search
    // Traversal
    // Print
        void display()
        {
        Node* temp = Head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    LinkedList list;
    list.insert(20);
    list.insert(50);
    list.insert(90);
    list.display();
    return 0;
}
