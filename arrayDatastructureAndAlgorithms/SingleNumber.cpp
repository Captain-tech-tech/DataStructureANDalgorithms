// if a vector   1,3,4,-3,-1,5,-4  is given and we are told to find the number with occur once, we will 
// simply add all the numbers

// same logic is used in the below question, but here no negative number is present so for cancaling
// two same numbers, the XOR logic can be used, in this way the unique number will remain

// so we will take XOR of all the values of the vector to find the unique number

// n^n=0
// n^0=n


// Leetcode Question
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one
// You must implement a solution with a linear runtime complexity and use only constant extra space

// linear runtime means one loop can be use, and only constant extra space means one constant variable can be made 

// Example 1:
// Input: nums = [2,2,1]
// Output: 1
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int singleNumber(vector<int>&nums)
    {
        int ans=0;
        for(int i:nums)
        {   
            ans=ans^i;
        }
        return ans;
    }
};

int main()
{
    int s;cout<<"Enter the size of your vector : ";cin>>s;
    vector<int>num(s,0);
    cout<<"Enter "<<s<<" elements in your vector : ";
    for(int i=0;i<s;i++)
    {
        cin>>num[i];
    }
    Solution s1;
    int single=s1.singleNumber(num);
    cout<<"The number "<<single<<" is the only number which occured once in the vector"<<endl;
    return 0;
}






