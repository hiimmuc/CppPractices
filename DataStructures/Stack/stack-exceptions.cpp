#include <iostream>
using namespace std;

class StackFullException : public exception

{
    virtual const char *what() const throw()
    {
        return "\nStack Full\n";
    }
};
class StackEmptyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nStack Empty\n";
    }
};