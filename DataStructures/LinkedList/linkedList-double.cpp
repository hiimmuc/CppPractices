// C++ implementation of Doubly Linked List

#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *prev, *next;
    Node<T>(T data)
    {
        this->data = data;
        prev = next = NULL;
    };
};

template <class T>
class DLL
{
public:
    Node<T> *head, *tail;

    DLL(){
        head = tail = NULL;
    };

    void insertBeg(T value){
        Node<T> *temp = new Node<T>(value);
        if(head == NULL)
        {
            head = tail = temp;
            return ;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    };

    void insertEnd(T value){
        Node<T> *temp = new Node<T>(value);
        if(head == NULL)
        {
            head = tail = temp;
            return ;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    };

    void print(){
        if(head == NULL)
        {
            cout << "\nThe list is empty.\n";
            return ;
        }
        Node<T> *temp = head;
        cout << "\n";
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    };

    void printReverse(){
        if(head == NULL)
        {
            cout << "\nThe list is empty.\n";
            return ;
        }
        Node<T> *temp = tail;
        cout << "\n";
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    };
};



int main()
{
    DLL<float> var;
    int option, input;
    do {
        cout << "\n\nDOUBLY LINKED LIST:\n\n";
        cout << "\n(1) Insert at the beginning";
        cout << "\n(2) Insert at the end";
        cout << "\n(3) Print the list";
        cout << "\n(4) Print the list in reverse order";
        cout << "\n(5) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter a value: ";
                    cin >> input;
                    var.insertBeg(input);
                    break;
            case 2: cout << "\nEnter a value: ";
                    cin >> input;
                    var.insertEnd(input);
                    break;
            case 3: var.print();
                    break;
            case 4: var.printReverse();
                    break;
        }
    } while(option != 5);
    return 0;
}