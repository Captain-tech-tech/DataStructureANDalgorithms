#include<iostream>
using namespace std;
int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;

    int *ptr = new int[s];

    cout<<"Enter "<<s<<" elements in your array : ";
    for(int i=0;i<s;i++)
    cin>>*(ptr+i);

    cout<<endl<<"All the elements of your array : ";
    for(int i=0;i<s;i++)
    cout<<*(ptr + i)<<"  ";
    cout<<endl;

    int flag, count = 0;

    int *leaders = new int[1];
    for(int i=0;i<s;i++)
    {
        flag = 0;
        for(int j=i+1;j<s;j++)
        {
            if(*(ptr+i) < *(ptr+j))
            flag = 1;
        }
        if(flag == 0)
        {
            count++;
            if(count == 1)
            {
                *(leaders + 0) = *(ptr+i);
            }
            else if(count > 1)
            {
                int *temp = new int[count];
                for(int i = 0;i<count-1;i++)
                *(temp + i) = *(leaders + i);
                *(temp + count -1) = *(ptr + i);
                
                delete[] leaders;
                leaders = temp;
                temp = nullptr;
            }
        }
    }

    cout<<"All the leaders elements of the array : ";
    for(int i=0;i<count;i++)
    cout<<*(leaders + i)<<"  ";
    cout<<endl;

    delete[] leaders;
    delete[] ptr;
}


