// A stack is a linear data structure in which insertion and deletion happen from one end only, called the TOP.
// The rule is: LIFO = Last In, First Out

// (2) LinkedList based implementation of stack


#include<iostream>
#include<iomanip>
using namespace std;

class LinkedStack
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val,Node *oldtop):data(val), next(oldtop){}
    };

    Node *top;
    int size;

    bool isEmpty() { return (top==nullptr);}

public:
    LinkedStack()
    {
        top = nullptr;
        size = 0;
    }

    LinkedStack(int val)
    {
        top = new Node(val,nullptr);
        size = 1;
    }

    void push(int val)
    {
        Node *newNode = new Node(val, top);
        top = newNode;
        size++;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        Node *popNode = top;
        int topVal = popNode->data;

        top = top->next;
        delete popNode;
        size--;

        return topVal;
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return top->data;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        Node *curr = top;
        while(curr)
        {
            cout<<"["<<setw(3)<<curr->data<<"]"<<endl;
            curr = curr->next;
        }
    }

    ~LinkedStack()
    {
        while(top)
        {
            Node *curr = top;
            top = top->next;
            delete curr;
        }
    }
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
