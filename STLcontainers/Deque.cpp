// Deque : double ended queue 
// Dequeue : it means poping an element from a queue

#include<iostream>
#include<deque>
using namespace std;
int main()
{
    // deque is internally implemented as a dynamic array, so random access is possible in deque 
    // while in lists random access is not possible

    deque<int>d = {67,34,56,89,23};

    for(int i:d)
    cout<<i<<"  ";
    cout<<endl;

    // all functions work in deque
    return 0;
}















