// The Aggressive Cows problem is a classic binary search algorithm puzzle where you must place C cows into N 
// stalls along a straight line such that the minimum distance between any two cows is as large as possible. 
// You are given the specific coordinate positions of the stalls, which you first sort in ascending order to 
// map out the physical layout. Because directly calculating the optimal spacing is difficult, the problem 
// uses binary search on the answer to test different possible minimum distances. For each distance tested, 
// a greedy approach places the first cow in the first stall and subsequent cows in the next available stalls 
// that meet or exceed that minimum gap. If all cows fit successfully, you try a larger distance; if they do 
// not, you reduce the distance, repeating this process until you find the absolute maximum possible minimum 
// distance.





#include<iostream>
#include<vector>
#include<algorithm>  // this library contains the sort function
using namespace std;

bool isPossible(vector<int> & nums, int n, int c, int minAllowedDistance)
{
    int cows = 1, laststallpos = nums[0];

    for(int i=0;i<n;i++)
    {
        if(nums[i]-laststallpos >= minAllowedDistance)
        {
            cows++;
            laststallpos = nums[i];
        }
        else
        if(cows == c)
        return true;
    }
    return false;
}


int minDistance(vector<int> & nums, int n, int m)
{
    sort(nums.begin(), nums.end());
    int st = 1, end = nums[n-1]-nums[0];
    int ans = -1;

    while(st <= end)
    {
        int mid = st + (end-st)/2;

        if(isPossible(nums,n,m,mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else 
        end = mid - 1;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,8,4,9};
    int n = 5, cows = 3;

    cout<<minDistance(nums, n, cows)<<endl;

}







