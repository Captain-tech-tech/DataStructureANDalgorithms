// (1) Array based implementation of stack data structure

#include <iostream>
#include <iomanip>
using namespace std;
class ArrayStack
{
private:
int *arr;
int size;
int capacity;
bool isEmpty() { return (size == 0); }
bool isFull() { return (size == capacity); }
public:
ArrayStack();

ArrayStack(int value);
~ArrayStack();
void push(int value);
int pop();
int peek();
int getSize();
void display();
};
int main()
{
ArrayStack stack;
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
cout << "Size: " << stack.getSize()<<endl;
}
// Default Constructor
ArrayStack::ArrayStack()
{
capacity = 10;
arr = new int[capacity];
size = 0;
}
// Parameterized Constructor
ArrayStack::ArrayStack(int value)
{
capacity = 10;
arr = new int[capacity];
*arr = value; // Store the initial element at index 0
size = 1;
}
// Destructor
ArrayStack::~ArrayStack()
{
delete[] arr; // Release the dynamically allocated array
}
// Add an element to the top of the stack
void ArrayStack::push(int value)
{
if (isFull())
{
cout << "Stack Overflow: Stack is full." << endl;
return;
}
*(arr + size) = value;
size++;
}
// Remove and return the top element of the stack
int ArrayStack::pop()
{
if (isEmpty())
{
cout << "Stack Underflow: Stack is empty." << endl;
return -1;
}
// The top element is at index: size - 1
int poppedData = *(arr + size - 1);
// Remove the top element by decreasing the size
size--;
return poppedData;
}
// Return the top element without removing it
int ArrayStack::peek()
{
if (isEmpty())
{
cout << "Stack is empty." << endl;
return -1;
}
return *(arr + size - 1);
}
// Return the current number of elements
int ArrayStack::getSize()
{
return size;
}
// Display the stack from top to bottom
void ArrayStack::display()
{
// Start from the top and move toward the bottom
for (int i = size - 1; i >= 0; i--)
{
cout << "[" << setw(3) << *(arr + i) << "]" << endl;
}
}

