#include<iostream>
using namespace std;

int remove_duplicates(int *arr, int s)
{
    for(int i=0;i<s;i++)
    {
        for(int j=i+1;j<s;j++)
        {
            if(*(arr+i) == *(arr+j))
            {
                for(int k=j;k<s-1;k++)
                {
                    *(arr+k) = *(arr+k+1);
                }
                j--;
                s--;
            }
        }
    }

    return s;
}

int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;
    int arr[s];
    cout<<"Enter "<<s<<" elements in the array : ";
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }

    int n = remove_duplicates(arr,s);
    cout<<"Your array without duplicates : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<"  ";
    }
    cout<<endl;
}
