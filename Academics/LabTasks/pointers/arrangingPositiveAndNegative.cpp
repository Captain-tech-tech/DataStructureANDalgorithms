#include<iostream>
using namespace std;

void rearrangeArray(int *arr,int s)
{
    int n = 0;
    for(int i=0;i<s;i++)
    {
        if(*(arr+i) < 0)
        {
            int temp = *(arr+n);
            *(arr+n) = *(arr+i);
            *(arr+i) = temp;
            n++;
        }
    }
}

int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;
    int arr[s];
    cout<<"Enter "<<s<<" element in the array : ";
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }

    cout<<"YOur array without arranging : ";
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    rearrangeArray(arr, s);

    cout<<"YOur array after arranging : ";
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}
