


// chaining
#include <iostream>
using namespace std;
#define SIZE 10

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert an element into the hash table
void Insert(Node *HT[], int key)
{
    int index = hashFunction(key);

    Node *newNode = new Node;
    newNode->data = key;

    // Insert at the beginning of the linked list
    newNode->next = HT[index];
    HT[index] = newNode;
}

// Search for an element
Node *Search(Node *HT[], int key)
{
    int index = hashFunction(key);
    Node *temp = HT[index];

    while (temp != nullptr)
    {
        if (temp->data == key)
            return temp;

        temp = temp->next;
    }

    return nullptr;
}

// Display the hash table
void Display(Node *HT[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> ";

        Node *temp = HT[i];

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

// Main function
int main()
{
    Node *HT[SIZE];

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
    {
        HT[i] = nullptr;
    }

    // Insert elements
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    // Display hash table
    cout << "Hash Table:" << endl;
    Display(HT);

    // Search for 21
    Node *temp = Search(HT, 21);

    if (temp != nullptr)
        cout << "\nElement found: " << temp->data << endl;
    else
        cout << "\nElement 21 not found!" << endl;

    // Search for 22
    temp = Search(HT, 22);

    if (temp != nullptr)
        cout << "Element found: " << temp->data << endl;
    else
        cout << "Element 22 not found!" << endl;

    // Free allocated memory
    for (int i = 0; i < SIZE; i++)
    {
        Node *current = HT[i];

        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    return 0;
}


