// span : maximum no of previous consecutive days from today where price <= today's price 
// previous high : immediate greater value for any day     span = i-previous_high_index


// online stock span
// #include<iostream>
// #include<vector>
// #include<stack>

// using namespace std;
// int main()
// {
//     vector<int>prices = {100,80,60,70,60,75,85};

//     vector<int>ans(prices.size(),0);
//     stack<int>s;  // here additionally stack is used for calculating the answer, so SC: O(n)

//     for(int i=0;i<prices.size();i++)  // TC: O(n)
//     {
//         while(s.size()>0 && prices[i]>=prices[s.top()])
//             s.pop();
        
//         if(s.empty())
//             ans[i] = i+1;
//         else
//             ans[i] = i - s.top();

//         s.push(i);        
//     }

//     for(auto val:ans)
//     {
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }



// next greater element
// immediatly larger and to the right of the current element
// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>arr = {6,8,0,1,3};

//     stack<int>s;
//     vector<int>ans(arr.size(),0);
//     for(int i=arr.size()-1;i>=0;i--)
//     {
//         while(!s.empty() && s.top()<arr[i])
//             s.pop();
        
//         if(s.empty())
//         {
//             ans[i] = -1;
//         }
//         else
//         {
//             ans[i] = s.top();
//         }
//         s.push(arr[i]);
//     }

//     for(auto val:ans)
//         cout<<val<<" ";
//     cout<<endl;
//     return 0;
// }






// previous smaller element
// immediately smaller and is on the left
// #include<iostream>
// #include<vector>
// #include<stack>

// using namespace std;

// vector<int> prevSmallerElement(vector<int>arr)  // TC: O(n). SC: O(n)
// {
//     vector<int>ans(arr.size(),0);
//     stack<int>s;
//     for(int i=0;i<arr.size();i++)
//     {
//         while(s.size()>0 && s.top()>=arr[i])
//         {
//             s.pop();
//         }
        
//         if(s.empty())
//         {
//             ans[i]=-1;
//         }
//         else
//         {
//             ans[i] = s.top();
//         }
//         s.push(arr[i]);
//     }
//     return ans;
// }

// int main()
// {
//     vector<int>arr = {3,1,0,8,6};

//     vector<int>ans = prevSmallerElement(arr);

//     for(auto val:ans)
//     {
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     return 0;
// }





// The celebrity problem
// Given a 2D array (n x n), such that arr[i][j] = 1 means ith person knows jth person, the task is to find the celebrity.
// • A celebrity is a person who is known to all but does not know anyone.
// • Return the index of the celebrity. If there is no celebrity, return -1.
// Example Matrix
// arr = [, [0,0,0], [0,1,0] ]

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getcelebrity(vector<vector<int>>nums)
{
    int n = nums.size();
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }

    while(s.size()>1)
    {
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(nums[i][j]==0)
            s.push(i);
        else
            s.push(j);
    }

    int celebrity = s.top();

    for(int i=0;i<n;i++)
    {
        if((i!=celebrity) && (nums[i][celebrity]==0 || nums[celebrity][i]==1))
        {
            return -1;
        }
    }

    return celebrity;
}

int main()
{
    vector<vector<int>>arr = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int ans = getcelebrity(arr);
    cout<<"The celebrity : "<<ans<<endl;

    return 0;
}





