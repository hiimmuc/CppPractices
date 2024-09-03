// C++ array list implementation of Queue

#include <iostream>
#include "queue-exception.cpp"

using namespace std;

template <class T>
class Queue
{
    private:
        static const int MAX_SIZE = 100;
        T data[MAX_SIZE];
        int front, rear;
    public:
        Queue(){
            front = 0;
            rear = 0;
        };

        void enqueue(T element){
            if (rear >= MAX_SIZE)
            {
                QueueFullException e;
                throw e;
            }
            else
            {
                data[rear] = element;
                rear = ++rear % MAX_SIZE;
            }
        };

        T dequeue(){
            if (isEmpty())
            {
                QueueEmptyException e;
                throw e;
            }
            else
            {
                T ret = data[front];
                front = ++front % MAX_SIZE;
                return ret;
            }
        };

        T getFront(){
            if (isEmpty())
            {
                QueueEmptyException e;
                throw e;
            }
            else
            {
                return data[front];
            }
        };

        int Size()
        {
            return abs(rear - front);
        }

        bool isEmpty()
        {
            return (front == rear);
        }

        void print(){
            if (isEmpty())
            {
                QueueEmptyException e;
                throw e;
            }
            else
            {
                int i = front;
                while (i != rear)
                {
                    cout << data[i] << " ";
                    i = ++i % MAX_SIZE;
                }
                cout << endl;
            }
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
            case 1: cout << "\nEnter a value: ";
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