// A queue in C++ is a linear data structure that follows the First-In, First-Out (FIFO) principle, 
// meaning the first element added is the first one removed

//  C++ STL implements queue as a container adapter, which wraps around an underlying sequential container 
//  (like std::deque or std::list) to provide a restricted, specific interface. 

// No Direct Indexing: Unlike vectors, elements in a queue are not accessed by index numbers
// “A queue does not provide iterators, so its elements cannot be directly traversed like a vector or list.” 


// Insertion (push / emplace): Adds a new element to the back (rear) of the queue in O(1) time
// Deletion (pop): Removes the element at the front of the queue in O(1) time
// Access (front / back): Inspects the first or last element in O(1) time without disrupting the structure
// Utility (empty / size): Checks whether the queue is empty or returns the current item count in O(1) time




#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;

    q.push(34);
    q.push(78);
    q.push(56);

    while(!q.empty())
    {
        cout<<q.front()<<"  ";
        q.pop();
    }
    cout<<endl;

    // front, pop, size, empty, swap works the same as in list
    return 0;
}

