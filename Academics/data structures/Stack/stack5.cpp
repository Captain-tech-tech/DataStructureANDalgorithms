// (1) Array based implementation of stack data structure



#include<iostream>
#include<iomanip>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int capacity;

    bool isEmpty(){ return size == 0;}
    bool isFull(){ return size == capacity;}

public:
    Stack()
    {
        capacity = 10;
        arr = new int[capacity];
        size = 0;
    }
    
    Stack(int val)
    {
        size = 0;
        capacity = 10;
        arr = new int[capacity];
        *(arr+size) = val;
        size++;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        *(arr+size) = val;
        size++;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int top = *(arr+size-1);
        size--;
        return top;
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return *(arr+size-1);
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        for(int i=size-1;i>=0;i--)
        {
            cout<<"["<<setw(3)<<*(arr+i)<<"]"<<endl;
        }
    }
};







