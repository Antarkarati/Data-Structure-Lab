#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int capacity;
    int top;

public:
    Stack(int cap)
    {
        capacity=cap;
        arr=new int[capacity];
        top=-1;

    }

};

 int main()
{
    return 0;
}