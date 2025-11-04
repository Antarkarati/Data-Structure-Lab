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

void deletion(Node*& head,int pos)
{
    if(head==nullptr)
    {
        cout<<"List is empty\n";
        return;
    }
    
    if(pos==1)
    {
        Node* temp=head;//this for delete this node and save space
        head=head->next;
        delete temp;
        return;
    }

    Node* temp=head;
    int count=1;

    while(temp!=nullptr && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==nullptr || temp->next ==nullptr)
    {
        cout<<"Invalid position\n";
        return;
    }
    Node* nodeToDelete =temp->next;
    temp->next=temp->next->next;
    delete nodeToDelete;
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

    cout<<"Linked Lists Before Deletion:";
    traversel(head);

    int pos;
    cout<<"Which position do you Delete:";
    cin>>pos;

    deletion(head,pos);

    cout<<"After Deletion:";
    traversel(head);

    return 0;
}
