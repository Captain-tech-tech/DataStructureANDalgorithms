// list is a sequence container implemented as a doubly-linked list. It is specifically optimized for 
// rapid insertions, removals, and splicing operations at the cost of direct data access


// List characteristics  and time complexity and performance: 
// Doubly-linked structure: Each element is contained within a separate node that stores the actual data 
// alongside two pointers pointing to the previous and next nodes in the sequence

// Non-contiguous memory: Nodes are allocated dynamically and scattered across different locations in memory 
// rather than sitting in a single flat block.

// Dynamic allocation: The container expands and contracts seamlessly on an element-by-element basis, 
// completely avoiding reallocation or copying overhead during growth.

// Linear time access (O(N)): It does not support random access via subscript brackets ([]) or the .at() 
// function. Finding a specific element requires stepping through nodes sequentially from the beginning or end

// High pointer overhead: Every single element requires storing two additional pointers, which consumes more 
// memory per element compared to strict array wrappers like std::vector or std::array.

// Poor cache locality: Because the elements are not adjacent in memory, iterating through the list causes 
// frequent CPU cache misses, making sequential traversal slower than dense contiguous containers.

// Because general-purpose STL algorithms like std::sort require random access iterators, they cannot be 
// used directly on lists. Instead, std::list provides its own specialized, highly efficient member functions

// .sort(): Sorts elements in place while preserving node positions.
// .merge(): Merges two pre-sorted lists into one single list.
// .splice(): Moves elements or entire sub-segments from one list into another in constant time (O(1)) without copying any data.
// .unique(): Traverses the container and removes adjacent duplicate values.




#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
    // vector is implemented as a dynamic array and list is implemented as a doubly linked list
    // due to doubly linked list it contains the pop_front and push_front functions

    list<int>l;

    list<int>l1 = {45,67,34,563,67};

    l.push_back(1);
    l.emplace_back(56);
    l.push_back(2);    // for adding numbers at the end
    l.push_front(45);  // for adding numbers from the front
    l.push_front(76);

    for(int i:l)
    cout<<i<<"  ";
    cout<<endl;

    l.pop_back();
    l.pop_front();

    for(int i:l)
    cout<<i<<"  ";
    cout<<endl;

    // list has all function, works exactly same as in vector --> size, erase, clear, begin, end, rbegin, rend, insert, front, back
    return 0;
}


















