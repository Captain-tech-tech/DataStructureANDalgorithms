// List is a set of elements in a linear order.
// For example, data values a1, a2, a3, a4 can be arranged in a list: (a3, a1, a2, a4)   

// The order is important in a list, so (a1,a2,a3,a4) and (a3,a1,a2,a4) are different lists 
// items are same but order is different, that's why these are different lists


#include<iostream>
using namespace std;

class ArrayList
{
    private:
        int *arr;
        int length; // number of elements
        int size;  // maximum capacity 
        int *curr;
    public:
    ArrayList(int s)
    {
        size = s;
        arr = new int[size];
        length = 0;
        curr = NULL;
    }

    void start()
    {
        curr = arr;  //  current store the starting address of array
    }

    void tail()
    {
        curr = arr + length -1;  // current points to the last element of array
    }

    void next()
    {
        curr++;
    }

    void back()
    {
        curr--;
    }


    void insert(int val,int pos)
    {
        if(length == size)
        {
            cout<<"List is full, can't insert value"<<endl;
            return;
        }
        if(pos < 1 || pos > (length + 1))
        {
            cout<<"Invlaid position, can't insert"<<endl;
            return;
        }

        tail();   // tail function is called, to point current to the address of last element
        for(int i = length;i >= pos;i--)
        {
            *(curr+1) = *curr;
            back;
        }
        *(curr+1) = val;
        length++;
    }   


    void remove(int pos)
    {
        if(length == 0)
        {
            cout<<"List is empty, nothing to remove"<<endl;
            return;
        }
        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position, can't remove"<<endl;
            return;
        }
        start();
        // while(*curr != arr[pos-1])
        //     next();
        // for(int i = pos;i<length-1;i++)
        // {
        //     *(curr) = *(curr+1); 
        //     next(); 
        // }

        // or 

        for(int i=1;i<length;i++)
        {
            if(i>=pos)
                *curr = *(curr+1);
            next();
        }
        length--;
    }

    void printList()
    {
        for(int i=0;i<length;i++)
        {
            cout<<*curr<<"  ";
            next();
        }
        cout<<endl;
    }

    int get(int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position, can't access"<<endl;
            return -1;
        }

        start();
        for(int i=1;i<pos;i++)
            next();
        
        return *curr;
    }

    int search(int val)
    {
        if(length == 0)
        {
            cout<<"List is empty"<<endl;
            return -1;
        }

        start();
        for(int i=1;i <= length;i++)
        {
            if(*curr == val)
                return 1;
            next();
        }
        return -1;
    }
};





