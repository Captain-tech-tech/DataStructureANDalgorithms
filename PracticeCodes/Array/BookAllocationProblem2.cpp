// Problem Statement : Given an array A of N integers representing the number of pages in N different books. 
// You need to allocate these books to M students such that the maximum number of pages allocated to any 
// student is minimized.
// Constraints & Rules :
// Contiguous Order: Books must be allocated in a continuous, 
// sequential order (i.e., a student can only be assigned a contiguous sub-segment of books).
// Full Assignment: Every book must be allocated to a student.
// Minimum Work: Each student must be allocated at least one book.
// Invalid Cases: If a valid assignment is not possible (e.g., if there are more students than books, \(M > N\)), return -1


// Objective : Calculate and return the minimum possible value of the maximum pages allocated to a single student.
// The goal is to choose the configuration that makes this maximum value as small as possible. 





#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxAllowedPages)
        return false;

        if(pages + arr[i]  <= maxAllowedPages)
        pages += arr[i];
        else
        {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}


int allocateBook(vector<int> &arr, int n, int m)   // O(logN * n)
{
    if(m > n)
    return -1;
    
    int sum = 0;
    for(int i=0; i<n;i++)  // O(n)
    sum += arr[i];

    int ans = -1;
    int st = 0, end = sum;

    while(st <= end)       // O(logN * n)
    {
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid))  // in case of valid mid, go left and and in case of invalid, go right
        {   ans = mid;
            end = mid - 1;
        }     
        else
        st = mid + 1;
    }
    return  ans;
}


int main()
{
    vector<int> arr = {15,17,20};
    int n = 4, m = 2;
    cout<<allocateBook(arr,n,m)<<endl;

    return 0;
}











