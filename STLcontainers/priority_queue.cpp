// we can visualize priority queue as a stack
// highest priority element is one which has highest value, or smallest value

// Instead, every element has a priority, and the element with the highest priority 
// is always served first



// Ordered Retrieval: You can only look at or remove the "top" element (the one with the highest priority).
// Container Adapter: Like std::queue, it wraps around an underlying container (by default, std::vector) 
// and provides a restricted set of methods.
// Logarithmic Efficiency: Insertion and deletion take O(log n) time, while accessing the top 
// element takes O(1) time.


// In C++, std::priority_queue is implemented under the hood using a Binary Heap. A binary heap is a balanced,
// complete binary tree (meaning every level is completely filled, except possibly the last level, which is 
// filled from left to right).




// Max-Heap (The Default in C++)
// By default, std::priority_queue<int> instantiates a max-heap.
// The Rule: The value of each parent node must be greater than or equal to the values of its children.
// Result: The largest element in the entire tree is guaranteed to sit at the root (the very top).
// Use Case: Perfect when "highest value" translates to "highest priority" (e.g., handling emergency tasks 
// with priority numbers from 1 to 10, where 10 is critical).



// 2. Min-HeapYou can configure the queue to be a min-heap by passing extra template arguments: 
// std::priority_queue<int, std::vector<int>, std::greater<int>>.
// The Rule: The value of each parent node must be less than or equal to the values of its children.
// Result: The smallest element in the entire tree is guaranteed to sit at the root.
// Use Case: Perfect when "smallest value" translates to "highest priority" (e.g., a CPU task manager 
// executing the job with the shortest remaining execution time).



// push()Up-Heapify (Bubble Up): 
// The new element is appended to the bottom-right of the tree (end of the vector). It then compares itself 
// with its parent. If it violates the heap property, it swaps with the parent. This process repeats upward 
// until it finds its valid home.   0(logn)


// pop()Down-Heapify (Bubble Down): 
// The root node (top priority) is deleted. To keep the tree complete, the very last element at the 
// bottom-right of the tree is moved up to replace the root. This node then compares itself with its 
// children and swaps downward with its largest child (max-heap) or smallest child (min-heap) until order 
// is restored.   0(logn)


// top()Direct Access: Simply looks at the root of the tree (index 0 of the underlying array).    0(1)




#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int>pq;

    pq.push(567);
    pq.push(234);
    pq.push(897);
    pq.push(321);
    pq.push(576);

    while(!pq.empty())
    {
        cout<<pq.top()<<"   ";
        pq.pop();
    }
    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> q;  // if first priority element is the smallest one

    q.push(567);
    q.push(234);
    q.push(897);
    q.push(321);
    q.push(576);

    while(!q.empty())
    {
        cout<<q.top()<<"   ";
        q.pop();
    }

    cout<<endl;

}




