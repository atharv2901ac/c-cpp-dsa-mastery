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
    void insertAtStart(int value){
        
        Node* newNode = new Node();
        newNode->data = value;
        if(Head == NULL){
            Head = newNode;
        }else{
            newNode->next = Head;
            Head = newNode;
        }
    }


    void InsertAtEnd(int value){
        
        Node* newNode = new Node();
        newNode->data = value;
        if(Head == NULL){
            Head = newNode;
        }
        else{
            Node* temp = Head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
            
        }
    }

     void insertAtposition(int value,int position){
        
        Node* newNode = new Node();
        newNode->data = value;
        if(Head == NULL){
            Head = newNode;
        }else if(position == 0){
            insertAtStart(value);
        }
        else{
            Node* temp = Head;
            for(int i=0;i<position-1;i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            
        }
    }

    int size(){
        if(Head == NULL){
            return 0;
        }else{
            int count = 1;
            Node* temp = Head;
            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;

        }
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
    list.insertAtStart(20);
    list.InsertAtEnd(45);
    list.insertAtposition(80,2);
    cout << list.size();
    list.display();
    return 0;
}
