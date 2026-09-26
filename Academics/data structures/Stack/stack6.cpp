
// (2) LinkedList based implementation of stack

#include <iostream>
#include <iomanip>
using namespace std;
class LinkedStack
{
private:
// Each node stores one stack element and a link to the next node
struct Node
{
int data;
Node *next;
Node(int value, Node *oldtop) : data(value), next(oldtop) {}
};
Node *top; // Points to the top node which is maintained at the head of the list
int size;
bool isEmpty() { return (top == nullptr); }
public:
LinkedStack();
LinkedStack(int value);
~LinkedStack();
void push(int value);
int pop();
int peek();
int getSize();
void display();
};
int main()
{
LinkedStack stack;
stack.push(100);
stack.push(20);
stack.push(30);
stack.push(123);
stack.display();
cout << "Size: " << stack.getSize() << endl;
cout << "******************************\n";
int removed1 = stack.pop();
int removed2 = stack.pop();
stack.display();
cout << "Size: " << stack.getSize() << endl;
}
// Default Constructor
LinkedStack::LinkedStack()
{
top = nullptr;
size = 0;
}
// Parameterized Constructor
LinkedStack::LinkedStack(int value)
{
// Create the first node and make it the top of the stack
top = new Node(value, nullptr);
size = 1;
}
// Destructor
LinkedStack::~LinkedStack()
{
// Delete each node one by one
while (top)
{
Node *curr = top; // Save the current node
top = top->next; // Move to the next node before deleting
delete curr;
}
}
// Add an element to the top of the stack
void LinkedStack::push(int value)
{
// Create a new node whose next points to the current top
Node *newNode = new Node(value, top);
// Make the new node the new top of the stack
top = newNode;
size++;
}
// Remove and return the top element of the stack
int LinkedStack::pop()
{
if (isEmpty())
{
cout << "Stack Underflow: Stack is empty." << endl;
return -1;
}
// Save the top node and its data before removing it
Node *poppedNode = top;
int poppedData = poppedNode->data;
top = top->next; // Move top to the next node
delete poppedNode; // Delete the old top node
size--;
return poppedData;
}
// Return the top element without removing it
int LinkedStack::peek()
{
if (isEmpty())
{
cout << "Stack is empty." << endl;
return -1;
}
return top->data;
}
// Return the current number of elements
int LinkedStack::getSize()
{
return size;
}
// Display the stack from top to bottom
void LinkedStack::display()
{
// Traverse the linked list starting from the top node
Node *curr = top;
while (curr)
{
cout << "[" << setw(3) << curr->data << "]" << endl;
curr = curr->next;
}
}