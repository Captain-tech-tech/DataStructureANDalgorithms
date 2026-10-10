

#include<iostream>
#include<vector>
using namespace std;

// O(n^2)
void bubbleSort(vector<int>&arr) // if arr is already sorted, so in one pass it perform n-1 comparisons and so then TC:O(n)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int flag = 0;//flag is used if no swap occurs during any pass, then it means the remaining array is sorted, so break the loop
        for(int j=1;j<n-1-i;j++)
        {
            if(arr[j]>arr[i])
            {
                swap(arr[j],arr[i]);
                flag = 1; 
            }
        }
        if(flag == 0)
            break;// this condition can be true in any pass, and if the array is already sorted, the loop will direectly break
    }
}













