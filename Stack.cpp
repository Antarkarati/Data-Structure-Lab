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

        capacity = cap;
        arr = new int[capacity]; // declear a empty array
        top = -1;
    }

    // push operation
    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    //pop operation
    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        return arr[top--];

    }


    // peek operation
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    //Display

    void display()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty\n";
            return;
        }

        cout<<"Stack (bottom to top):[";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i];
            if (i != top) cout << ", ";
        }
        cout << "]\n";

    }
};


int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.display();

    st.pop();
    st.display();
    
    st.push(100);
    st.display();

    st.push(59);
    st.display();
    //backtrack

    // for(int i=0;i<5;i++)
    // {
    //     cout<<st.peek()<<" ";
    //     st.pop();
    // }
    
    
    
    
    // Stack st2(5);
    // for(int i=0;i<5;i++)
    // {
    //     st2.push(st.peek());
    //     st.pop();
    // }
    
    // for(int i=0;i<5;i++)
    // {
    //     cout<<st2.peek()<<" ";
    //     st2.pop();
    // }


    return 0;
}
