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

void insertion(Node* head,int data,int pos)
{
    Node* newNode=new Node(data);

    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }

    Node* temp=head;
    int count=1;

    while(temp!=nullptr && count<pos-1)
    {
        temp=temp->next;
        count++;
    }

    if(temp==nullptr)
    {
        cout<<"Invalid position\n";
        delete newNode;
        return ;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

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

    cout<<"Linked Lists Before Insertion:";
    traversel(head);

    int val,pos;
    cout<<"Which number do you insert:";
    cin>>val;
    cout<<"Which position do you insert:";
    cin>>pos;

    insertion(head,val,pos);

    cout<<"After Insertion:";
    traversel(head);

    return 0;
}
