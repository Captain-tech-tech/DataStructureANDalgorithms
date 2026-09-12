
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node *previous;

    Node(int val) : info(val), next(NULL), previous(NULL) {}
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

    void insert(int val, int pos)
    {
        if(pos < 1 || pos > length + 1)
        {
            cout << "Invalid position, can't insert" << endl;
            return;
        }

        Node *newNode = new Node(val);

        // Insert at beginning
        if(pos == 1)
        {
            newNode->next = head;
            newNode->previous = NULL;

            if(head != NULL)
                head->previous = newNode;
            head = newNode;
            length++;
            return;
        }

        // Find node at position pos - 1
        Node *curr = head;

        for(int i = 1; i < pos - 1; i++)
            curr = curr->next;

        // Connect new node
        newNode->next = curr->next;
        newNode->previous = curr;

        // If inserting before an existing node
        if(curr->next != NULL)
            curr->next->previous = newNode;

        curr->next = newNode;

        length++;
    }

    // Add element at the end
    void add_end(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            length++;
            return;
        }

        Node *curr = head;

        while(curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
        newNode->previous = curr;

        length++;
    }

    // Remove element from a particular position
    void remove(int pos)
    {
        if(head == NULL)
        {
            cout << "List is empty, can't remove" << endl;
            return;
        }

        if(pos < 1 || pos > length)
        {
            cout << "Invalid position, can't remove" << endl;
            return;
        }

        // Remove first node
        if(pos == 1)
        {
            Node *curr = head;
            head = head->next;
            if(head != NULL)
                head->previous = NULL;

            delete curr;

            length--;
            return;
        }

        // Find node to remove
        Node *curr = head;

        for(int i = 1; i < pos; i++)
            curr = curr->next;

        // Connect previous node to next node
        curr->previous->next = curr->next;

        // If curr is not the last node
        if(curr->next != NULL)
            curr->next->previous = curr->previous;

        delete curr;

        length--;
    }


    // Search whether a value exists
    bool search(int val)
    {
        Node *curr = head;

        while(curr != NULL)
        {
            if(curr->info == val)
                return true;
            curr = curr->next;
        }
        return false;
    }


    // Return position of a value, returns -1 if value doesn't exist
    int search_position(int val)
    {
        Node *curr = head;
        int pos = 1;

        while(curr != NULL)
        {
            if(curr->info == val)
                return pos;
            curr = curr->next;
            pos++;
        }
        return -1;
    }


    // Get value at a particular position
    int get(int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return -1;
        }
        Node *curr = head;
        for(int i = 1; i < pos; i++)
            curr = curr->next;
        return curr->info;
    }


    // Set/change value at a particular position
    void set(int val, int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *curr = head;

        for(int i = 1; i < pos; i++)
            curr = curr->next;

        curr->info = val;
    }


    // Display list from head to tail
    void display()
    {
        Node *curr = head;
        cout << "NULL <-> ";
        while(curr != NULL)
        {
            cout << curr->info << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }


    // Display list from tail to head
    void display_reverse()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *curr = head;

        // Go to last node
        while(curr->next != NULL)
            curr = curr->next;

        cout << "NULL <-> ";

        // Move backwards
        while(curr != NULL)
        {
            cout << curr->info << " <-> ";
            curr = curr->previous;
        }
        cout << "NULL" << endl;
    }


    // Return length
    int get_length()
    {
        return length;
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

    l1.insert(5, 1);
    l1.insert(25, 4);

    l1.display();

    l1.remove(3);

    l1.display();

    cout << "Search 30: ";

    if(l1.search(30))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Position of 30: "<< l1.search_position(30) << endl;

    cout << "Value at position 2: "<< l1.get(2) << endl;

    l1.set(100, 2);

    cout << "After set: ";
    l1.display();

    cout << "Length: "<< l1.get_length() << endl;

    cout << "Reverse: ";
    l1.display_reverse();

    return 0;
}

