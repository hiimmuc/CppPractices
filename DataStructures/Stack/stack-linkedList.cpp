// C++ array list implementation of Stack

#include <iostream>
#include "stack-exceptions.cpp"

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T>(T data){
        this->data = data;
        next = NULL;
    };
};


template <class T>
class Stack
{
    public:
        int size;
        Node<T> *top;

        Stack(){
            size = 0;
            top = NULL;
        };

        void push(const T element){
            Node<T> *temp = new Node<T>(element);
            if(top == NULL)
            {
                top = temp;
                return ;
            }
            temp->next = top;
            top = temp;
            size++;
        };

        void pop(){
            if(top == NULL)
            {
                StackEmptyException e;
                throw e;
            }
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        };

        T getTop(){
            if (top == NULL)
            {
                StackFullException e;
                throw e;
            }
            else
            {
                return top->data;
            }
        };

        int getSize(){
            return size;
        };


        bool isEmpty(){
            return (top == NULL) ? true : false;
        };

        void print(){
            if(top == NULL)
            {
                StackEmptyException e;
                throw e;
            }
            Node<T> *temp = top;
            cout << "\n";
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        };
};


int main()
{
    Stack<float> var;
    int option, input;
    do {
        cout << "\n\nSTACK:\n";
        cout << "\n(1) Push";
        cout << "\n(2) Pop";
        cout << "\n(3) Get the top-most element of the stack";
        cout << "\n(4) Check whether the stack is empty or not";
        cout << "\n(5) Print the elements of the stack";
        cout << "\n(6) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.push(input);
                    break;
            case 2: var.pop();
                    break;
            case 3: var.getTop();
                    break;
            case 4: if(var.isEmpty())
                        cout << "\nThe stack is empty.\n";
                    else
                        cout << "\nThe stack is NOT empty.\n";
                    break;
            case 5: var.print();
                    break;
        }
    } while(option != 6);
    return 0;
}