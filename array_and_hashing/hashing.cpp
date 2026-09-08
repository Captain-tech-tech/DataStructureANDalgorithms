// In C++, hashing is a technique used to map data of any size (like strings or custom objects) to a 
// fixed-size integer value (a "hash code") using a mathematical function called a hash function



// two sum 
// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


// brute force approach     // O(n^2)
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int> v = {351,538,346,345,457,456};
//     int target = 696, ans = 0;

//     for(int i=0;i<v.size();i++)
//     {
//         for(int j=i+1;j<v.size();j++)
//         {
//             if(target == (v[i]+v[j]))
//                 ans = 1;
//         }
//     }
//     cout<<ans<<endl;
// }



// a better approach : is to sort the array and then use two pointer approach   so the overall time complexity is O(nlogn)




// Optimized approach
// solving the problem through hashing


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={7,2,11,15};
    int target = 9;

    unordered_map<int,int>m;
    
    vector <int>ans;

    for(int i=0;i<v.size();i++)
    {
        int first = v[i];
        int sec = target - first;

        if(m.find(sec) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
        }
        m[first] = i;
    }
    cout<<ans[0]<<"  "<<ans[1]<<endl;
}



