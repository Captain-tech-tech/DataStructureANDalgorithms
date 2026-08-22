#include<iostream>
using namespace std;
int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;
    int arr[s];
    cout<<"Enter "<<s<<" element in the array : ";
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }

    int smallest = arr[0];
    int second_smallest = arr[0];

    for(int i=0;i<6;i++)
    {
        if(smallest > *(arr+i))
        {
            second_smallest = smallest;
            smallest = *(arr+i);
        }
        else if(*(arr+i) < second_smallest && *(arr+i) != smallest)
        {
            second_smallest = *(arr+i);
        }
    }

    if(smallest == second_smallest)
    {
        cout<<"There is no second smallest!"<<endl;
        cout<<"All the values are equal to "<<smallest<<endl;
        return 0;
    }

    cout<<"The smallest number is : "<<smallest<<endl;
    cout<<"The second smallest number is : "<<second_smallest<<endl;
    return 0;
}
