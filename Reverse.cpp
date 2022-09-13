
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node * Next;
    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};
struct Duplicate
{
    int position[1000];
};
void Insert_at_tail(Node *&head, int value)
{
    Node *newnode = new Node(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node *temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newnode;
    }
}
void Display(Node *head)
{
    if(head ==NULL)
    {
        cout<<"there is no value"<<endl;
    }
    else
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->Next;
        }
    }
}

void Inset_at_head(Node *&head, int value)
{
    Node *newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node *temp=head;
        head=newnode;
        newnode->Next=temp;
        // or head->Next=temp;
    }
}

int length(Node *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        int c=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->Next;
        }
         return c;
    }

}

void insertAtSpecificPosition(Node *&head,int value,int pos)
{

    if(head==NULL)
    {
        cout<<"linked list is empty"<<endl;
    }
    else
    {
        int len=length(head);
        if(pos<1||pos> len+1)
        {
            cout<<"Sorry!! position is out of range"<<endl;
        }
        else if(pos==1)
        {
           Inset_at_head(head,value);
        }

        else
        {
            Node *temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->Next;
                i++;
            }
            Node *newnode=new Node(value);
            Node * nextnode = temp->Next;
            temp->Next= newnode; // we have to always indicating the next to add new value with it.
            newnode->Next=nextnode;
        }
    }
}

int Search_value_in_uniqueList(Node *&head, int value)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node *temp=head;
        int i=1;
        while(temp->value!=value)
        {
            if(temp->Next==NULL)
            {
                return -1;
            }
            temp=temp->Next;
            i++;
        }
        return i;
    }
}
void Search_value_in_Duplicate_ValuedList(Node *&head, int value)
{
    if(head==NULL)
    {
        cout<<"Linked List is Null"<<endl;
    }
    else
    {

        int len=length(head);
        int pos[len],k=1;
        int j=1;
        Node *temp=head;

        while(j<=len)
        {
            if(value==temp->value)
            {
                pos[k]=j;
                k++;
            }

            j++;
            temp=temp->Next;
        }
       if(k==1)
       {
           cout<<"Searched value is not found"<<endl;
       }
       else
       {
           cout<<"position of searched value are: "<<endl;
           for(int i=1;i<k;i++)
           {
               cout<<pos[i];
               if(i<k-1)
                cout<<",";
           }
           cout<<endl;
       }
    }
}

Duplicate Search_value_in_Duplicate_ValuedList_Return(Node *&head, int value)
{

        Node *temp=head;
        Duplicate d;
        int len = length(head);
       int k=1;
        int i=1;
        while(i<=len)
        {
            if(temp->value==value)
            {
                d.position[k]=i;
                k++;
            }
            i++;
            temp=temp->Next;
        }
        d.position[0]=k;
    return d;
}

void Insert_after_before_ofA_Specific_Value(Node *&head, int TargetValue,int value)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        Node *temp = head;
        // find the position of value where we want to insert our value
        int pos = Search_value_in_uniqueList(head,TargetValue);
        insertAtSpecificPosition(head,value,pos+1);

    }
}

void Delete_from_head(Node *&head)
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
    }
    else
    {
        Node *temp = head;
        head=temp->Next;
        delete(temp);

    }
}
void Delete_from_tail(Node *&head)
{
    if(head==NULL)
    {
                cout<<"Linked List is Empty"<<endl;
    }
    else
    {
          Node *temp=head;
        if(temp->Next==NULL)
        {
            Delete_from_head(head);
        }
        else
        {

        while (temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *vanish = temp->Next->Next;
        temp->Next=NULL;
        delete(vanish);
        }
    }
}
void Delete_from_specific_Position(Node *&head, int pos)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        int len=length(head);
        if(pos<1|| pos>len+1)
        {
             cout<<"Sorry!! position is out of range"<<endl;
        }
        else if(pos==1)
        {
            Delete_from_head(head);
        }
        else if(pos==len)
        {
            Delete_from_tail(head);
        }
        else
        {
            Node * temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->Next;
                i++;
            }
            Node *vanish = temp->Next;
            temp->Next=temp->Next->Next;
            delete(vanish);
        }
    }
}
void Delete_value_from_AUnique_LinkedList(Node *&head,int value)
{
    int pos= Search_value_in_uniqueList(head,value);
    if(pos==-1)
    {
        cout<<"Value does not found"<<endl;
    }
    else
    Delete_from_specific_Position(head,pos);
}

void Insert_after_before_ofA_Specific_Value_Duplicate_LinkedList(Node *&head, int TargetValue,int value)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {

        Duplicate positions;
        positions= Search_value_in_Duplicate_ValuedList_Return(head, TargetValue);
        int len = positions.position[0];
        int i=1;
        while(i<len)
        {
             insertAtSpecificPosition(head,value,positions.position[i]+1);
             i++;
             positions.position[i]= positions.position[i]+(i-1);// value add korar sathe sateh oi specific value(ex;3) er position change hoye jascche. tai oi specific vlaue er position grab korar jonno amader dekhte hobe
             //amra ei porjonto kotogula value add korchi. taile totogula position bere jabe. like 3 jodi age position 3,4,7 number e thake akn jodi amra every 3 er por 1000 vlaue add korte chai. then first 3 er por 1000 add
             // korle 2nd 3 er position hoye jabe 4 er jaygay 5. akn amra 2 ta vlaue add kore felchi, so 3rd 2 er position 2 bere 7 theke 9 hoye jabe. then amra 9 number position er por 1000 add korte parbo.
             // ei logic er upor depend kore current position er sathe i theke 1 minus kore add kora hoice. cz i er man bere jascche next er man er jonno, suppose 2nd 3 er jonno i er man 2, amader newa lagbe position 4 theke 5 e
             // akn i add kore dile hoye jabe 6. so amader korte hobe i-1. eta every case satisfy kore.
             //example, previously- 1 2 3 3 4 5 3 8
             // now- 1 2 3 1000 3 1000 4 5 3 1000 8;
        }

    }
}

void Delete_value_from_ADuplicate_LinkedList(Node *&head,int value)
{
    Duplicate positions;
    positions = Search_value_in_Duplicate_ValuedList_Return(head,value);
    int len = positions.position[0];
    int i=1;
    while(i<len)
    {
        Delete_from_specific_Position(head,positions.position[i]);
        i++;
        positions.position[i]=positions.position[i]-(i-1); // opposite of Insert_after_before_ofA_Specific_Value_Duplicate_LinkedList
    }
}

Node* Reverse_with_Non_recursive(Node *&head)
{
    Node *prev = NULL;
    Node *Current = head;
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return head;
    }
      Node *nextNode = Current->Next;
    while(1)
    {
        Current->Next=prev;
        prev=Current;
        Current=nextNode;
        if(Current==NULL)
            break;
        nextNode=nextNode->Next;
    }
    return prev;
}

Node* Reverse_Recursive(Node *& head)
{
    if(head==NULL||head->Next ==NULL)
    {
        if(head==NULL)
        {
            cout<<"Linked List is empty"<<endl;
        }
        return head;
    }
    Node *newHead = Reverse_Recursive(head->Next);
    head->Next->Next=head;
    head->Next=NULL;
    return newHead;
}
int main()
{
    Node *head = NULL;
    cout<<"Give your choice"<<endl;
    cout<<"Choice 0: Exist"<<endl;
    cout<<"Choice 1: Insert value at tail"<<endl;
    cout<<"Choice 2: Insert value at head"<<endl;
    cout<<"Choice 3: Insert value at specific position"<<endl;
    cout<<"Choice 4: Search a value from unique linked list"<<endl;
    cout<<"Choice 5: Search a value from duplicate valued linked list"<<endl;
    cout<<"Choice 6: Insert value after of before a specific position"<<endl;
    cout<<"Choice 7: Delete from head"<<endl;
    cout<<"Choice 8: Delete from tail"<<endl;
    cout<<"Choice 9: Delete from a specific Position"<<endl;
    cout<<"Choice 10: Delete value from a Unique linked list"<<endl;
    cout<<"Choice 11:  Insert after before ofA Specific Value Duplicate LinkedList"<<endl;
    cout<<"Choice 12: Delete value form a duplicate valued linked list "<<endl;
    cout<<"Choice 13: Reversal of Linked list with Non recursive way "<<endl;
    int choice;
    cin>>choice;
    while(choice!=0)
    {
        int value;
        int position;
        int len;
        int spv;

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
                 cout<<"Insert Position: "<<endl;
                 cin>>position;
                cout<<"Insert Value: "<<endl;
                cin>>value;
                 insertAtSpecificPosition(head,value,position);
                 break;
                case 4:
                    cout<<"Insert value that you want to search "<<endl;
                    cin>>value;
                    len=Search_value_in_uniqueList(head,value);
                    if(len==-1)
                        cout<<"value is not found"<<endl;
                    else
                    cout<<"The position of searched value is "<<len<<endl;
                break;
                case 5:
                    cout<<"Insert value that you want to search "<<endl;
                    cin>>value;
                  Duplicate dd;
                  dd=Search_value_in_Duplicate_ValuedList_Return(head,value);
                   len = dd.position[0];
                   if(len==1)
                   {
                       cout<<"Value is not found"<<endl;
                   }
                   else
                   {
                       cout<<"The position of searched value are : "<<endl;
                       for(int i=1;i<len;i++)
                       {
                           cout<<dd.position[i];
                           if(i<len-1)
                            cout<<",";
                       }
                       cout<<endl;
                   }
                   break;

                case 6:
                    cout<<"Enter specific value: "<<endl;
                        cin>>spv;
                        cout<<"Insert Value: "<<endl;
                        cin>>value;
                        Insert_after_before_ofA_Specific_Value(head,spv,value);
                         cout<<"Linked List: "<<endl;
                        Display(head);
                        break;
                    case 7:
                    Delete_from_head(head);
                    cout<<"Linked List after deletion: "<<endl;
                    Display(head);
                    break;
                    case 8:
                        Delete_from_tail(head);
                    cout<<"Linked List after deletion from tail : "<<endl;
                    Display(head);
                    break;

                    case 9:
                            cout<<"Insert Position: "<<endl;
                            cin>>position;
                            Delete_from_specific_Position(head,position);
                            cout<<"Linked List after deletion from A specific Position : "<<endl;
                            Display(head);
                    break;

                    case 10:
                        cout<<"Which value do you wanna delete?"<<endl;
                        cin>>value;
                        Delete_value_from_AUnique_LinkedList(head,value);
                        cout<<"Linked List after deletion value from A Unique Linked List : "<<endl;
                        Display(head);
                        break;


                    case 11:
                        cout<<"Enter specific value: "<<endl;
                        cin>>spv;
                        cout<<"Insert Value: "<<endl;
                        cin>>value;
                        Insert_after_before_ofA_Specific_Value_Duplicate_LinkedList(head,spv,value);
                         cout<<"Linked List: "<<endl;
                        Display(head);
                        break;

                    case 12:
                        cout<<"which value do you wanna delete? : "<<endl;
                        cin>>value;
                        Delete_value_from_ADuplicate_LinkedList(head,value);
                        cout<<"Linked List: "<<endl;
                        Display(head);
                    break;

                    case 13:
                        //head= Reverse_with_Non_recursive(head);
                        head=Reverse_Recursive(head);
                        cout<<"Linked List after Reverse: "<<endl;
                        Display(head);
                        break;


                default:
                break;
        }
        cout<<"Next Choice: "<<endl;
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
