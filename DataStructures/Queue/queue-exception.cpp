#include <iostream>

using namespace std;

class QueueFullException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nQueue is full\n";
    }
};
class QueueEmptyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nQueue is empty\n";
    }
};