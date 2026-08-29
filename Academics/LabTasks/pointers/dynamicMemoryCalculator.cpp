#include<iostream>
using namespace std;

int main()
{
    int s;cout<<"Enter the size of the array : ";cin>>s;
    int *arr1 = new int[s], *arr2 = new int[s];

    cout<<"Enter elements of your first array : ";
    for(int i=0;i<s;i++)
    cin>>*(arr1 + i);

    cout<<"Enter elements of the second array : ";
    for(int i=0;i<s;i++)
    cin>>*(arr2 + i);


    int *sum = new int[s], *diff = new int[s], *product = new int[s];

    for(int i=0;i<s;i++)
    {
        *(sum + i) = *(arr1+i) + *(arr2+i);
        *(diff + i) = *(arr1 + i) - *(arr2 + i);
        *(product + i) = *(arr1 + i) * *(arr2 + i);
    }

    cout<<"Sum : ";
    for(int i=0;i<s;i++)
    cout<<*(sum + i)<<"  ";
    cout<<endl;

    cout<<"Product : ";
    for(int i=0;i<s;i++)
    cout<<*(product + i)<<"  ";
    cout<<endl;

    cout<<"Difference : ";
    for(int i=0;i<s;i++)
    cout<<*(diff + i)<<"  ";
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    delete[] sum;
    delete[] diff;
    delete[] product;
    
}


