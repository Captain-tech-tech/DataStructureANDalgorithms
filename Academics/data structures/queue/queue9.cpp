#include <iostream>
using namespace std;

class LinkedQueue
{
private:
    // Each node stores one queue element and a link to the next node
    struct Node
    {
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node *front;  // Points to the front node which is maintained at the
                  // head of the list
    Node *rear;   // Points to the rear node which is maintained at the
                  // tail of the list
    int size;

    bool isEmpty()
    {
        return (front == nullptr);
    }

public:
    LinkedQueue();
    LinkedQueue(int value);
    ~LinkedQueue();

    void enqueue(int value);
    int dequeue();
    int peek();
    int getSize();
    void display();
};

int main()
{
    LinkedQueue queue;

    queue.enqueue(100);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(123);

    queue.display();

    cout << "Size: " << queue.getSize() << endl;
    cout << "******************************\n";

    int removed1 = queue.dequeue();
    int removed2 = queue.dequeue();

    queue.display();

    cout << "Size: " << queue.getSize() << endl;
}

// Default Constructor
LinkedQueue::LinkedQueue()
{
    front = rear = nullptr;
    size = 0;
}

// Parameterized Constructor
LinkedQueue::LinkedQueue(int value)
{
    // Create the first node and make it the front of the queue
    front = rear = new Node(value);
    size = 1;
}

// Destructor
LinkedQueue::~LinkedQueue()
{
    // Delete each node one by one
    while (front)
    {
        Node *curr = front;     // Save the current node
        front = front->next;    // Move to the next node before deleting

        delete curr;
    }
}

// Add an element to the rear of the queue
void LinkedQueue::enqueue(int value)
{
    // Create a new node to be added at the rear
    Node *newNode = new Node(value);

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        // Make the new node the new rear of the queue
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

// Remove and return the front element of the queue
int LinkedQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }

    // Save the front node and its data before removing it
    Node *dequeuedNode = front;
    int dequeuedData = dequeuedNode->data;

    front = front->next;  // Move front to the next node

    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete dequeuedNode;  // Delete the old front node

    size--;

    return dequeuedData;
}

// Return the front element without removing it
int LinkedQueue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }

    return front->data;
}

// Return the current number of elements
int LinkedQueue::getSize()
{
    return size;
}

// Display the queue from front to rear
void LinkedQueue::display()
{
    Node *curr = front;

    cout << "[ ";

    while (curr)
    {
        cout << curr->data;

        if (curr->next)
        {
            cout << " | ";
        }

        curr = curr->next;
    }

    cout << " ]" << endl;
}

