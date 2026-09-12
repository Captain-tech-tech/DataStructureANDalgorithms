#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val):data(val), next(NULL){}
    
};

class LinkedList
{
    private:
    Node *head;
    int length;

    public:
    LinkedList()
    {
        head = NULL;
        length = 0;
    }

    // Insert a value at a particular position
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
            head->next = head;
            length++;
            return;
        }

        Node *curr = head;
        // Insert at beginning
        if(pos == 1)
        {
            newNode->next = head;
            while(curr->next != head)
                curr = curr->next;

            curr->next = newNode;
            head = newNode;
        }
        else
        {
            // Move to node at position pos - 1
            for(int i=1;i<pos-1;i++)
                curr = curr->next;

            newNode->next = curr->next;
            curr->next = newNode;
        }
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
            head->next = head;
            length++;
            return;
        }

        Node *curr = head;

        while(curr->next != head)
            curr = curr->next;

        curr->next = newNode;
        newNode->next = head;

        length++;
    }


    // Remove element from a particular position
    void remove(int pos)
    {
        if(head == NULL)
        {
            cout<<"Empty list, can't remove"<<endl;
            return;
        }

        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position, can't remove"<<endl;
            return;
        }

        Node *curr = head;

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
            Node *temp = head;
            // Find last node
            while(curr->next != head)
                curr = curr->next;

            head = head->next;
            curr->next = head;

            delete temp;
        }
        else
        {
            Node *prev = NULL;
            // Find node at position pos
            for(int i=1;i<pos;i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
        length--;
    }

    // Search whether a value exists
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

    // Search the position of a value, returns -1 if value doesn't exist
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
            cout<<"Empty list"<<endl;
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
            cout<<"Empty list"<<endl;
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

    // Display the circular linked list
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
            cout<<curr->data<<" -> ";
            curr = curr->next;

        }while(curr != head);

        cout<<"HEAD"<<endl;
    }

    // Display length of list
    int get_length()
    {
        return length;
    }

    // Josephus problem
    int Josephus(int n, int m)
    {
        if(n <= 0 || m <= 0)
        {
            cout<<"Invalid values"<<endl;
            return -1;
        }

        // Create circular list
        for(int i=1;i<=n;i++)
            add_end(i);

        Node *curr = head;
        Node *prev = head;

        // Find node before head
        while(prev->next != head)
            prev = prev->next;

        /*
            curr = current node
            prev = node before curr

            We move m-1 times because curr
            itself is counted as 1.
        */

        while(length > 1)
        {
            for(int i=1;i<m;i++)
            {
                prev = curr;
                curr = curr->next;
            }

            // Remove curr
            prev->next = curr->next;

            // If removing head
            if(curr == head)
                head = curr->next;

            delete curr;
            length--;
            // Move to next person
            curr = prev->next;
        }
        return curr->data;
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

    l1.add_end(10);
    l1.add_end(20);
    l1.add_end(30);
    l1.add_end(40);

    l1.display();

    l1.insert(5,1);
    l1.display();

    l1.insert(25,4);
    l1.display();

    l1.remove(3);
    l1.display();


    cout<<"Search 30: ";

    if(l1.search(30))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    cout<<"Position of 30: "<<l1.search_position(30)<<endl;

    cout<<"Value at position 2: "<<l1.get(2)<<endl;

    l1.set(100,2);

    cout<<"After set: ";
    l1.display();


    cout<<"Length: "<<l1.get_length()<<endl;

    LinkedList l2;

    cout<<"Josephus winner: "<<l2.Josephus(5,2)<<endl;

    return 0;
}


