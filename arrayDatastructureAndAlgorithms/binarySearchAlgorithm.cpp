// binary search works on sorted array


#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&nums, int target)
{
    int st = 0, end = nums.size() - 1;
    while(st <= end)
    {
        int mid = (st + end)/2;
        // int mid = st + (end - st)/2;  // it is more optimized way to find the mid
        if(target > nums[mid])
        st = mid+1;
        else if(target < nums[mid])
        end = mid-1;
        else
        return mid;        
    }
    return -1;
}


int recurrsive_binarySearch(vector<int> & nums, int target, int start, int end)
{
    if(start <= end)
    {
        int mid = start + (end-start)/2;
        if(target > nums[mid])
        return recurrsive_binarySearch(nums,target,mid+1,end);
        else if(target < nums[mid])
        return recurrsive_binarySearch(nums,target,start,mid-1);
        else
        return mid;
    }
    return -1;
}




int main()
{
    vector<int>nums = {-1,0,3,4,5,9,12};
    int target = 12;
    cout<<binarySearch(nums,target)<<endl;

    int tar = 0;
    cout<<recurrsive_binarySearch(nums,tar,0,6)<<endl;
}





