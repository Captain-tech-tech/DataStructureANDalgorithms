









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


















