#include<iostream>
using namespace std;

int remove_duplicates(int s, int * arr) { 
    for(int i=0;i<s;i++) 
    { 
        for(int j=i+1;j<s;j++) 
        { 
            if(*(arr+i) == *(arr+j)) 
            { 
                for(int k = j; k < s - 1; k++) 
                {
                    *(arr+k) = *(arr+k+1);
                }
                s--;
                j--;
            } 
        } 
    } 
    return s; 
}

int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;

    int arr[s];
    cout<<"Enter "<<s<<" elements in your array : ";

    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"Your array with duplicates : ";
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Your array without duplicates : ";

    int n = remove_duplicates(s,arr);

    for(int i = 0;i<n;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    return 0;
}



