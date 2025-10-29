class Node
{
    int data;
    Node next;

    Node(int data)
    {
        this.data=data;
        this.next=null;
    }

}

public class Searching
{
    public static boolean search(Node head,int key)
    {
        Node curr=head;

        while(head!=null)
        {
            if(curr.data==key) return true;

            curr=curr.next;
        }
        return false;
    }

    public static void main(String[] args) 
    {
        Node head=new Node(1);
        head.next=new Node(2);
        head.next.next=new Node(3);
        head.next.next.next=new Node(4);
        head.next.next.next.next=new Node(5);

        int key=5;

        if(search(head, key)) System.out.println(":Ture");
        else System.out.println("False");
        
    }
}
