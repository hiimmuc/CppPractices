// C++ array list implementation of Stack

#include <iostream>
#include "stack-exceptions.cpp"

using namespace std;

template <class T>
class Stack
{
    private:
        static const int MAX_SIZE = 100;
        T data[MAX_SIZE];

    public:
        int size, index, top;

        Stack(){
            top = -1;
            index = 0;
        };

        void push(const T element){
            if (top >= MAX_SIZE)
            {
                StackFullException e;
                throw e;
            }
            else
            {
                data[++top] = element;
            }
        };

        T pop(){
            if (top <= -1)
            {
                StackEmptyException e;
                throw e;
            }
            else
            {
                return data[top--];
            }
        };

        T getTop(){
            if (top <= -1)
            {
                StackEmptyException e;
                throw e;
            }
            else
            {
                return data[top];
            }
        };

        int getSize(){
            if (top <= -1)
            {
                StackEmptyException e;
                throw e;
            }
            else
            {
                return top + 1;
            }
        }

        bool isEmpty(){
            return (top <= -1) ? true : false;
        };

        T print(){
            if(top == -1)
            {
                cout << "\nThe stack is empty.\n";
                return ;
            }
            cout << "\n";
            for(int i = top; i >= 0; --i)
                cout << data[i] << " ";
            cout << "\n";
        };
};


int main()
{
    Stack<int> s;
    if (s.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    // Push elements
    s.push(100);
    s.push(200);
    // Size of stack
    cout << "Size of stack = " << s.getSize() << endl;
    // Top element
    cout << s.pop() << endl;
    // Pop element
    cout << s.pop() << endl;
    // Pop element
    cout << s.pop() << endl;
    // Pop element
    cout << s.pop() << endl;
    return 0;
}