// stack is the non-swquential container 

// it is called last in first output container (LIFO)
// The last element you add to the stack is always the very first one that must be removed.
// You cannot access the elements underneath without removing the top element first.

// Think of a physical stack of dinner plates on a table:You place Plate A on the table.
// Plate B on top of Plate A and  Plate C on top of Plate B. Now if you need middle plate, you
// have to remove plate C from the top and then take the second plate 


// It wraps around existing sequential containers like deque or vector instead of being a standalone data structure
// You can only access, insert, or remove the element located at the very top.
// It does not support iterators, preventing you from looping through or modifying middle elements
// Operations like insertion (push) and removal (pop) run in O(1) constant time
// It uses deque by default, but you can explicitly specify vector or list







#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    s.push(78);
    s.push(56);
    s.push(43);
    s.emplace(34);

    cout<<s.top()<<endl;  // top is use to know which element is present at the top of stack

    s.pop();  // it removes the element present at the top

    cout<<s.empty()<<endl; // it is used to check whether the stack is empty or not

    // printing all elements one by one and then deleting the element one by one 
    while(!s.empty())
    {
        cout<<s.top()<<"   ";
        s.pop();
    }
    cout<<endl;

    return 0;
}

