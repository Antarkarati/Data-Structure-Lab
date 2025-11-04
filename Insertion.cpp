#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

void traversel(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data;
        if(head->next!=nullptr)
        cout<<"->";
        head=head->next;


    }
    cout<<"\n";
}

void insertion

int main()
{
    int n;
    cout<<"Enter num of input:";
    cin>>n;
    int a;
    cout<<"Enter the elements:";
    Node* head=nullptr;//for first node
    Node* tail =nullptr;//for last node
    while(n--)
    {
        cin>>a;
        Node* newNode=new Node(a);

        if(head==nullptr)//for first node
        {
            head=newNode;
            tail=newNode;
        }
        else//for others Node
        {
            tail->next=newNode;
            tail=newNode;
        }

    }

    cout<<"Linked Lists:";
    traversel(head);

    return 0;
}
