// C++ linked list implementation of Queue

#include <iostream>
#include "queue-exception.cpp"

using namespace std;

template <class T>
class Node
{
public:
    int data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    };
};


template <class T>
class Queue
{
    public:
        Node<T> *front, *rear;
        int nodeCount;

        Queue(){ front = rear = NULL; };

        void enqueue(T value){
            Node<T> *temp = new Node<T>(value);
            if(front == NULL){
                front = rear = temp;
                return ;
            }
            rear->next = temp;
            rear = temp;
            nodeCount++;
        };

        void dequeue(){
            if(front == NULL){
                QueueFullException e;
                throw e;
            }
            Node<T> *temp = front;
            front = front->next;
            delete temp;
            nodeCount--;
        };

        void getFront(){
            if(front == NULL){
                QueueEmptyException e;
                throw e;
            }
            cout << "\n" << front->data << "\n";
        };

        int size(){
            return nodeCount;
        };

        bool isEmpty(){
            if(front == NULL)
                return true;
            return false;
        };

        void print(){
            if(front == NULL){
                cout << "\nThe queue is empty.\n";
                return ;
            }
            Node<T> *temp = front;
            cout << "\n";
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        };
};


int main()
{
    Queue<int> var;
    int option, input;
    do {
        cout << "\n\nQUEUE:\n";
        cout << "\n(1) Enqueue";
        cout << "\n(2) Dequeue";
        cout << "\n(3) Get the element at the front of the queue";
        cout << "\n(4) Check whether the queue is empty or not";
        cout << "\n(5) Print the elements of the queue";
        cout << "\n(6) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.enqueue(input);
                    break;
            case 2: var.dequeue();
                    break;
            case 3: var.getFront();
                    break;
            case 4: if(var.isEmpty())
                    cout << "\nThe queue is empty.\n";
                    else
                    cout << "\nThe queue is NOT empty.\n";
                    break;
            case 5: var.print();
                    break;
        }
    } while(option != 6);
    return 0;
}