// A set in C++ is an associative container that stores unique elements following 
// a specific order. Once an element is added to a set, its value cannot be 
// modified directly (it is const); it can only be deleted or newly inserted.

// Sorted Order: By default, elements are automatically arranged in ascending order.
// Underlying Structure: Implemented as a self-balancing binary search tree (typically a Red-Black Tree).
// Efficiency: Search, insertion, and removal all take logarithmic time O(log n).



// set: Unique elements, sorted O(log n)
// unordered_set: Unique elements, unsorted hash table O(1) average
// multiset: Duplicate elements allowed, sorted O(log n)



#include<iostream>
#include<set>
#include<unordered_set> 
using namespace std;

int main()
{
    set<int>s;
    s.insert(45);
    s.insert(68);
    s.insert(23);
    s.insert(89);
    s.insert(89);
    s.insert(89);

    cout<<"Size  : "<<s.size()<<endl; // set ignores duplicates values that's why it size is 4 and not 6

    for(auto val:s)
    cout<<val<<"   ";
    cout<<endl;

    cout<<"lower bound : "<<*(s.lower_bound(18)); // lower_bound returns an iterator which we can deference
    // it searchs for that values, if it is found, it returns that value and if not found, then value just greater than that value is return
    // it not such value exists and also no higher value than that exists, then it 
    // return s.end() value which means 0 value, because it is not a valid index
    cout<<endl;

    cout<<"upper bound : "<<*(s.upper_bound(67))<<endl;



    // multi-set 
    multiset<int>ms;
    ms.insert(457);
    ms.insert(345);
    ms.insert(8734);
    ms.insert(6272);
    ms.insert(67);
    ms.insert(67);
    ms.insert(457);

    cout<<"multi set : ";
    for(auto val:ms)
    cout<<val<<"  ";
    cout<<endl;

    // unordered_set
    unordered_set<int>us;
    us.insert(78);
    us.insert(56);
    us.insert(35);
    us.insert(234);

    cout<<"Unordered set : ";
    for(auto val:us)
    cout<<val<<"   ";
    cout<<endl;


    return 0;
}









