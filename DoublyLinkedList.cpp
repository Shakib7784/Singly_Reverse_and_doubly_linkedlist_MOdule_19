#include<bits/stdc++.h>
using namespace std;
class DoublyNode
{
public:
    int value;
    DoublyNode *prev;
    DoublyNode *Next;
    DoublyNode(int val)
    {
        value=val;
        prev=NULL;
        Next=NULL;
    }
};
void  Insert_at_tail(DoublyNode *&head, int val)
{
    DoublyNode *newnode = new DoublyNode(val);
    if(head==NULL)
    {
        head= newnode;
    }
    else
    {
        DoublyNode *temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next = newnode;
        newnode->prev  = temp;
    }
}
void Inset_at_head(DoublyNode *&head,int val)
{
    DoublyNode * newnode = new DoublyNode(val);
     if(head==NULL)
    {
        head= newnode;
    }
    else
    {
        DoublyNode *temp=head;
        head=newnode;
        newnode->Next=temp;
        temp->prev=newnode;
    }

}
void Display(DoublyNode *head)
{
    if(head==NULL)
    {
        cout<<"there is no value"<<endl;
    }
    else
    {
        DoublyNode *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->Next;
        }
    }
}
void DisplayReverse(DoublyNode *&head)
{
    if(head==NULL)
    {
        cout<<"there is no value"<<endl;
    }
    else
    {
            DoublyNode * temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->prev;
        }
    }


}
int length(DoublyNode *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        DoublyNode *temp=head;
        int i=1;
        while(temp->Next!=NULL)
        {
            i++;
            temp=temp->Next;
        }
        return i;
    }
}
int main()
{
    DoublyNode *head = NULL;
     cout<<"Give your choice"<<endl;
    cout<<"Choice 0: Exist"<<endl;
    cout<<"Choice 1: Insert value at tail"<<endl;
    cout<<"Choice 2: Insert value at head"<<endl;
     cout<<"Choice 3: Reversed Linked List"<<endl;
    int choice;
    cin>>choice;
    while(choice!=0)
    {
        int value,position;

        switch(choice)
        {
             case 1:
                cout<<"Insert Value: "<<endl;
                cin>>value;
                Insert_at_tail(head,value);
                break;

                case 2:
                cout<<"Insert Value: "<<endl;
                cin>>value;
                Inset_at_head(head,value);
               break;

                case 3:
                    cout<<"Reverse Linked LIst"<<endl;
                    DisplayReverse(head);

                default:
                break;
        }

        cout<<"Next Choice"<<endl;
        cin>>choice;
    }

    cout<<"Linked List: "<<endl;
    Display(head);
    cout<<"Length is: "<<endl;
    int len=length(head);
    if(len==-1)
    {
        cout<<"Length is 0 "<<endl;
    }
    else
    {
        cout<<len<<endl;
    }


}
