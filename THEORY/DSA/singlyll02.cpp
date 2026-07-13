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
        void deleteAtStart(){
            if (Head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            Node* temp = Head;
            Head = Head->next;
            delete temp;
        }

        void deleteAtEnd(){
            
            if (Head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            if (Head->next == NULL) {
                delete Head;
                Head = NULL;
                return;
            }

            Node* temp = Head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        }

        void deleteAtPosition(int pos) {
            if (Head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            if (pos == 1) {
                deleteAtStart();
                return;
            }

            Node* temp = Head;

            for (int i = 1; i < pos - 1 && temp != NULL; i++) {
                temp = temp->next;
            }

            if (temp == NULL || temp->next == NULL) {
                cout << "Invalid position!" << endl;
                return;
            }

            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }

    // Update
        void update(int pos, int newData) {
            if (Head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            Node* temp = Head;

            for (int i = 1; i < pos && temp != NULL; i++) {
                temp = temp->next;
            }

            if (temp == NULL) {
                cout << "Invalid Position!" << endl;
                return;
            }

            temp->data = newData;
            cout << "Node updated successfully!" << endl;
        }
    // Sort
        void sort() {
            if (Head == NULL || Head->next == NULL) {
                return;
            }

            Node* current;
            Node* index;

            for (current = Head; current != NULL; current = current->next) {

                for (index = current->next; index != NULL; index = index->next) {

                    if (current->data > index->data) {
                        int temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }

                }
            }

            cout << "List sorted successfully!" << endl;
        }
    // Search
        void search(int key) {
            if (Head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            Node* temp = Head;
            int position = 1;

            while (temp != NULL) {
                if (temp->data == key) {
                    cout << "Element found at position " << position << endl;
                    return;
                }

                temp = temp->next;
                position++;
            }

            cout << "Element not found!" << endl;
        }
    // Reverse
        void reverse() {
            Node* prev = NULL;
            Node* current = Head;
            Node* next = NULL;

            while (current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            Head = prev;

            cout << "List reversed successfully!" << endl;
        }
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
    list.insertAtposition(95,1);
    list.insertAtposition(75,3);
    list.deleteAtPosition(2);
    list.search(75);
    list.update(1,35);
    list.sort();
    list.reverse();
    cout << list.size() << endl;
    list.display();
    return 0;
}
