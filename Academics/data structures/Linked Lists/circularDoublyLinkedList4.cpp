// ADT : Abstract data type
// Definition: A logical blueprint for data.
// Focus: It tells you what data is stored and what operations are allowed (like insert or delete).
// Hiding details: It hides how the data is actually organized or coded in the computer's memory.
// Benefit: You can change the underlying code later (such as switching from an array to a linked list) 
// without breaking the rest of your program


// List ADT : 
// A List ADT is a specific type of ADT that represents a finite, ordered sequence of data items where 
// each item has a specific position

// Conceptual View: A collection of items arranged in a linear, sequential order (A_1, A_2, A_3, ... , A_n).
// Meaning of "Ordered": Each element has a distinct position or index (like first, second, or third). 
// It does not mean the values are sorted numerically or alphabetically.
// Dynamic Size: It can usually grow or shrink as items are added or removed.



#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *previous;

    Node(int val):data(val), next(nullptr), previous(nullptr){}
};


class LinkedList
{
    int length;
    Node *head;

    public:

    LinkedList()
    {
        length = 0;
        head = nullptr;
    }

    // Insert value at a particular position
    void insert(int val, int pos)
    {
        if(pos < 1 || pos > length + 1)
        {
            cout<<"Invalid position, can't insert"<<endl;
            return;
        }

        Node *newNode = new Node(val);
        // Empty list
        if(head == NULL)
        {
            head = newNode;

            newNode->next = head;
            newNode->previous = head;

            length++;
            return;
        }

        // Insert at position 1
        if(pos == 1)
        {
            Node *tail = head->previous;
            newNode->next = head;
            newNode->previous = tail;

            head->previous = newNode;
            tail->next = newNode;

            head = newNode;

            length++;
            return;
        }

        // Find node at position pos - 1
        Node *curr = head;

        for(int i=1;i<pos-1;i++)
            curr = curr->next;

        // Insert after curr
        newNode->next = curr->next;
        newNode->previous = curr;

        curr->next->previous = newNode;
        curr->next = newNode;

        length++;
    }

    // Add element at the end
    void add_end(int val)
    {
        Node *newNode = new Node(val);

        // Empty list
        if(head == NULL)
        {
            head = newNode;

            newNode->next = head;
            newNode->previous = head;

            length++;
            return;
        }

        Node *tail = head->previous;

        newNode->next = head;
        newNode->previous = tail;

        tail->next = newNode;
        head->previous = newNode;
        length++;
    }

    // Remove element from a particular position
    void remove(int pos)
    {
        if(head == NULL)
        {
            cout<<"List is empty, can't remove"<<endl;
            return;
        }

        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position, can't remove"<<endl;
            return;
        }

        // Only one node
        if(length == 1)
        {
            delete head;

            head = NULL;
            length = 0;
            return;
        }

        // Remove first node
        if(pos == 1)
        {
            Node *curr = head;
            Node *tail = head->previous;

            head = head->next;

            tail->next = head;
            head->previous = tail;

            delete curr;

            length--;
            return;
        }

        // Find node at position pos
        Node *curr = head;
        for(int i=1;i<pos;i++)
            curr = curr->next;

        // Connect previous and next nodes
        curr->previous->next = curr->next;
        curr->next->previous = curr->previous;

        delete curr;
        length--;
    }

    // Search for a value
    bool search(int val)
    {
        if(head == NULL)
            return false;

        Node *curr = head;
        do
        {
            if(curr->data == val)
                return true;

            curr = curr->next;

        }while(curr != head);

        return false;
    }

    // Search position of a value
    // Returns -1 if value doesn't exist
    int search_position(int val)
    {
        if(head == NULL)
            return -1;

        Node *curr = head;
        int pos = 1;
        do
        {
            if(curr->data == val)
                return pos;

            curr = curr->next;
            pos++;

        }while(curr != head);
        return -1;
    }

    // Get value at a particular position
    int get(int pos)
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return -1;
        }

        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position"<<endl;
            return -1;
        }

        Node *curr = head;
        for(int i=1;i<pos;i++)
            curr = curr->next;

        return curr->data;
    }

    // Set/change value at a particular position
    void set(int val, int pos)
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position"<<endl;
            return;
        }

        Node *curr = head;
        for(int i=1;i<pos;i++)
            curr = curr->next;
        curr->data = val;
    }

    // Display from head to tail
    void display()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        Node *curr = head;
        do
        {
            cout<<curr->data<<" <-> ";
            curr = curr->next;

        }while(curr != head);
        cout<<"HEAD"<<endl;
    }

    // Display from tail to head
    void display_reverse()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        Node *tail = head->previous;
        Node *curr = tail;
        do
        {
            cout<<curr->data<<" <-> ";
            curr = curr->previous;

        }while(curr != tail);
        cout<<"TAIL"<<endl;
    }

    // Return length
    int get_length()
    {
        return length;
    }

    // Return first element
    int get_first()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    // Return last element
    int get_last()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return -1;
        }
        return head->previous->data;
    }

    // Destructor
    ~LinkedList()
    {
        if(head == NULL)
            return;

        Node *curr = head->next;
        while(curr != head)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = NULL;
        length = 0;
    }
};


int main()
{
    LinkedList l1;
    // Add elements
    l1.add_end(10);
    l1.add_end(20);
    l1.add_end(30);
    l1.add_end(40);

    cout<<"Original list: ";
    l1.display();

    // Insert at beginning
    l1.insert(5,1);

    cout<<"After inserting 5 at position 1: ";
    l1.display();

    // Insert in middle
    l1.insert(25,4);

    cout<<"After inserting 25 at position 4: ";
    l1.display();

    // Insert at end
    l1.insert(50,l1.get_length()+1);

    cout<<"After inserting 50 at end: ";
    l1.display();

    // Remove first
    l1.remove(1);

    cout<<"After removing position 1: ";
    l1.display();

    // Remove middle
    l1.remove(3);

    cout<<"After removing position 3: ";
    l1.display();

    // Search
    cout<<"Search 30: ";

    if(l1.search(30))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    // Search position
    cout<<"Position of 30: "<<l1.search_position(30)<<endl;

    // Get
    cout<<"Value at position 2: "<<l1.get(2)<<endl;

    // Set
    l1.set(100,2);

    cout<<"After setting position 2 to 100: ";
    l1.display();

    // Reverse
    cout<<"Reverse: ";
    l1.display_reverse();

    // First and last
    cout<<"First element: "<<l1.get_first()<<endl;

    cout<<"Last element: "<<l1.get_last()<<endl;

    // Length
    cout<<"Length: "<<l1.get_length()<<endl;

    return 0;
}