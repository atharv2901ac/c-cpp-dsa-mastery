#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << "Top Element: " << arr[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << "Stack Elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 99);
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    s.peek();

    return 0;
}