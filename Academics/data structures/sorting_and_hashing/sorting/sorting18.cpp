

#include<iostream>
#include<vector>
using namespace std;


//  Bubble Sort vs Insertion Sort
// | Cases    | Bubble Sort | Insertion Sort |
// | Min Comp | O(n)       | O(n) |        if already in ascending order
// | Max Comp | O(n^2)     | O(n^2) |      if already in descending order
// | Min Swap | O(1)       | O(1) |        ascending
// | Max Swap | O(n^2)     | O(n^2) |      descending
// | Adaptive | ✓ Yes      | ✓ Yes |
// | Stable   | ✓ Yes      | ✓ Yes |
// | Linked List | No      | Yes |
// | K Passes    | Yes     | No |

// O(n^2)
void bubbleSort(vector<int>&arr) // if arr is already sorted, so in one pass it perform n-1 comparisons and so then TC:O(n)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int flag = 0;//flag is used if no swap occurs during any pass, then it means the remaining array is sorted, so break the loop
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = 1; 
            }
        }
        if(flag == 0)
            break;// this condition can be true in any pass, and if the array is already sorted, the loop will direectly break
    }
}


// O(n^2)
void insertionSort(vector<int>&arr)
{
    int n = arr.size();
    for(int i=1;i<n;i++) // start from index 1, as we initially consider array size to be 1 which is sorted, and then insert elements one by one
    {
        int j = i-1;
        int x = arr[i];
        while(j>-1 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


void selectionSort(vector<int>&arr)
{
    int n = arr.size();
    int j,k;
    for(int i=0;i<n;i++)
    {
        for(j=k=i;j<n;j++)
            if(arr[j]<arr[k])
                k = j;
        swap(arr[i],arr[k]);
    }
}




int main()
{
    vector<int>arr = {8,5,7,3,2};

    // bubbleSort(arr);
    // insertionSort(arr);
    selectionSort(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<"  ";
    
    return 0;
}










