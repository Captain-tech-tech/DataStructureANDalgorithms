// Link list is a data structure ni which elements are explicitly ordered, that is 
// each item contains within itself the address of next item;

// Need a head to point to the first node of the list. Otherwise we don't know  where
// the start of the list is.



#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// [2,6,8,7,1]

class LinkedList
{
    private:
    Node *head;   // points to the start of the list
    int length;   // number of elements 

    public:
    LinkedList()
    {
        head = NULL;
        length = 0;
    }

    void insert(int val, int pos)
    {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Invalid position, can't insert value"<<endl;
            return;
        }

        // insert at the beginning
        if(pos == 1)
        {
            Node *n = new Node(val);
            n->next = head;
            head = n;
            length++;
            return;
        }

        // create new node
        Node *n = new Node(val);

        Node *curr = head;  // find node before the desire position

        for(int i=1;i<pos-1;i++)
            curr = curr->next;
        
        // inserting node
        n->next = curr->next;
        curr->next = n;

        length++;
    }

    void remove(int pos)   // ********** remove by value can also be performed
    {
        if(head == NULL)
        {
            cout<<"List is empty, remove operation can't be performed"<<endl;
            return;
        }
        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position, can't remove"<<endl;
            return;
        }

        Node * curr = head;
        if(pos==1)
        {
            head = head->next;  // or head = curr->next;
            delete curr;
        }
        else 
        {
            Node *previous = NULL;
            for(int i = 1;i < pos;i++)
            {
                previous = curr;
                curr = curr->next;
            }
            previous->next = curr->next;
            delete curr;
        }
        length--;
    }

    bool search(int val)  // checking whether the element is present in the link list or not
    {
        Node *curr = head;
        while(curr->next != NULL)
        {
            if(curr->data == val)
             return true;
            
            curr = curr->next;
        }
        return false;
    }

    int search_pos(int val)    // return position of the element
    {
        Node *curr = head;
        int pos = 0;
        while(curr->next != NULL)
        {
            pos++;
            if(curr->data == val)
                return pos;
            
            curr = curr->next;
        }
        return -1;
    }   // ********** make a search function, in which all position of an element are returned in a link list 

    ~LinkedList()
    {
        Node *curr = NULL;
        while(head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
};

int main()
{
    LinkedList l1;
    l1.insert(10,1);
    l1.insert(357,2);
    l1.insert(457,1);
    l1.insert(567,8);

    cout<<l1.search(10)<<endl;
    cout<<l1.search_pos(457)<<endl;
}




