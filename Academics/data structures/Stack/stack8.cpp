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

// vector<int> prevSmallerElement(vector<int>arr)
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







