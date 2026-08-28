// Painter's partition problem :
// You are given an integer array representing the lengths of several wooden boards placed side by side, 
// and an integer representing the total number of available painters. Your task is to find the minimum 
// possible time required to paint all the boards, under the constraint that each painter can only paint 
// contiguous sections of boards and all painters work simultaneously at the same constant speed 
// (taking one unit of time to paint one unit of board length). Write an efficient algorithm to determine 
// this optimal maximum workload assigned to a single painter, ensuring the total time taken by the most
// heavily burdened painter is minimized.

// like :  arr[40,30,10,20],  M = 2







#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;

    for(int i=0;i<n;i++)
    {
        if(time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else 
        {
            painters ++;
            time = arr[i];
        }
   }

   return painters <= m;
}



int minTimeToPaint(vector<int> &arr, int n, int m)
{
    int sum = 0, maxVal = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    while(st <= end)
    {
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else 
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m =2;

    cout<<minTimeToPaint(arr,n,m)<<endl;
}




















