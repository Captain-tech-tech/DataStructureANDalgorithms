// A stack is a linear data structure in which insertion and deletion happen from one end only, called the TOP.
// The rule is: LIFO = Last In, First Out

// PUSH means adding an element to the top of the stack.
// Stack:
// ┌───┐
// │ 30│ ← TOP
// ├───┤
// │ 20│
// ├───┤
// │ 10│
// └───┘

// POP means removing the element from the top.
// PEEK/TOP means looking at the top element without removing it.

// Stack overflow occurs when you try to PUSH an element into a stack that has no available space.
// Stack underflow occurs when you try to POP from an empty stack.

// Stacks uses
// 1) Function calls
// When one function calls another:
// main()
//   ↓
// functionA()
//   ↓
// functionB()
// The system needs to remember things such as: where to return, local variables, parameters, execution state. This is handled using a call stack.

// 2) Undo/Redo in a text editor

// 3) Browser history
// You visit:
// Google
//  ↓
// YouTube
//  ↓
// Wikipedia
// Going backward can be modeled using stack-like behavior.
// Real browser history implementations can be more sophisticated, but stacks are a useful conceptual model.

// 4)  Parentheses matching
// Consider: { [ ( ) ] }
// A stack can keep track of opening brackets.

// 5) Expression conversion like infix to postfix and infix to prefix
// Stacks can evaluate: 2 3 +   which means:  2 + 3


//              STACK
//                │
//     ┌──────────┴──────────┐
//     │                     │
// PUSH/POP              Applications
//                           │
//                 ┌─────────┼─────────┐
//                 │         │         │
//              Function   Undo     Expression
//               calls                handling
//                                     │
//                        ┌────────────┼────────────┐
//                        │            │            │
//                      Infix       Prefix       Postfix
//                        │
//                        ↓
//                 Conversion
//                        │
//                        ↓
//                     Stack
//                        │
//                        ↓
//                    Postfix
//                        │
//                        ↓
//                    Evaluation



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
