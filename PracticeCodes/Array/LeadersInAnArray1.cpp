// Question : Given an array A of positive integers. Your task is to find the leaders 
// in the array. An element of array is leader if it is greater than or equal to all 
// the elements to its right side. The rightmost element is always a leader.

#include<iostream>
int main()
{
    int s;std::cout<<"Enter the size of the array : ";std::cin>>s;

    int arr[s];std::cout<<"Enter "<<s<<" elements in the array : ";
    for(int i=0;i<s;i++)
    std::cin>>arr[i];

    long int sum = 0;
    for(int i=0;i<s;i++)
    sum += arr[i];

    for(int i=0;i<s;i++)
    {
        sum -= arr[i];

        if(*(arr+i) >= sum)
        std::cout<<arr[i]<<"  ";
    }
    std::cout<<std::endl;

    return 0;
}

