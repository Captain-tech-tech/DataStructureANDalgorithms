#include <iostream>
using namespace std;
class ArrayQueue
{
private:
int *arr;
int front, rear; // Indexes for front and rear of the queue in the
circular array
int size;
int capacity;
bool isEmpty() { return (size == 0); }
bool isFull() { return (size == capacity); }
public:
ArrayQueue();
ArrayQueue(int value);
~ArrayQueue();
void enqueue(int value);
int dequeue();
int peek();
int getSize();
void display();
};
int main()
{
ArrayQueue queue;
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
ArrayQueue::ArrayQueue()
{
capacity = 10;
arr = new int[capacity];
front = 0;
rear = -1;
size = 0;
}
// Parameterized Constructor
ArrayQueue::ArrayQueue(int value)
{
capacity = 10;
arr = new int[capacity];
front = rear = 0;
*(arr + rear) = value; // Store the initial element at index 0
size = 1;
}
// Destructor
ArrayQueue::~ArrayQueue()
{
delete[] arr; // Release the dynamically allocated array
}
// Add an element to the rear of the queue
void ArrayQueue::enqueue(int value)
{
if (isFull())
{
cout << "Queue is full." << endl;
return;
}
rear++;
// If rear reaches the end of the array, wrap it around to the
beginning
if (rear == capacity)
{
rear = 0;
}
*(arr + rear) = value;
size++;
}
// Remove and return the element at the front of the queue
int ArrayQueue::dequeue()
{
if (isEmpty())
{
cout << "Queue is empty." << endl;
return -1;
}
int dequeuedData = *(arr + front);
front++;
// If front reaches the end of the array, wrap it around to the
beginning
if (front == capacity)
{
front = 0;
}
size--;
return dequeuedData;
}
// Return the element at the front without removing it
int ArrayQueue::peek()
{
if (isEmpty())
{
cout << "Queue is empty." << endl;
return -1;
}
return*(arr + front);
}
// Return the current number of elements
int ArrayQueue::getSize()
{
return size;
}
// Display the queue from front to rear
void ArrayQueue::display()
{
cout << "[ ";
int index = front;
for (int i = 0; i < size; i++)
{cout << *(arr + index);
if (i < size - 1)
{
cout << " | ";
}
index++;
// Wrap around when reaching the end of the array
if (index == capacity)
{
index = 0;
}
}
cout << " ]" << endl;
}

