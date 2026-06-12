// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.


// time complexity  O(n*2)   brute force approach
// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
//     public:
//     int majorityElement(vector<int>& v)
//     {
//         int n=v.size();
//         for(int i:v)
//         {
//             int freq=0;
//             for(int j:v)
//             {
//                 if(i==j)
//                 freq++;
//             }
//             if(freq>n/2)
//             return i;
//         }
//         return -1;
//     }
// };

// int main()
// {
//     int n;cout<<"Enter the size of your array : ";cin>>n;

//     vector<int>v(n);
//     cout<<"Enter "<<n<<" elements in your vector : ";
//     for(int i=0;i<n;i++)
//     cin>>v[i];

//     Solution s1;
//     int a=s1.majorityElement(v);
//     if(n==-1)
//     cout<<"There is no element having higher majority than n/2"<<endl;
//     else
//     cout<<"Element with the highest majority : "<<a<<endl;
//     return 0;
// }





// A more optimize approach towards the same problem  
// ---> time complexity for sorting O(nlog(n)) and for finding highest frequent number O(n*1)
// and overall time complexity is O(nlog(n))
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int> v = {0,0,1,1,2,2,2,2,2};
//     int s = v.size();

//     for(int i=0; i<s-1; i++)
//     {
//         for(int j=0; j<s-i-1; j++)
//         {
//             if(v[j] > v[j+1])
//             {
//                 swap(v[j], v[j+1]);
//             }
//         }
//     }
//     int freq = 1,num = -1;
//     for(int i=1; i<s; i++)
//     {
//         if(v[i] == v[i-1])
//         {
//             freq++;

//             if(freq > s/2)
//             {
//                 num = v[i];
//                 break;
//             }
//         }
//         else
//         {
//             freq = 1;
//         }
//     }
//     if(num != -1)
//         cout<<"Majority element: "<<num<<endl;
//     else
//         cout<<"No majority element exists"<<endl;

//     return 0;
// }




// Moores_voting algorithm   ----> time complexity O(n*1)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={1,2,2,1,1};
    int freq=0,ans=0;
    for(int i=0;i<v.size();i++)
    {
        if(freq==0)
        ans=v[i];
        if(ans==v[i])
        freq++;
        else
        freq--;
    }
    cout<<"The most frequent number is : "<<ans<<endl;
    return 0;
}
// logic of moore's voting algorithm
// “Agar ek element majority hai, toh wo apne aap ko baaki elements ke against cancel karne ke baad bhi bach jayega.”
// Hum ek candidate aur count lete hain — same element mile toh count badhao, different mile toh count ghatao.
// Jab count 0 ho jata hai, naya candidate select kar lete hain.
// Isliye majority element end tak survive kar jata hai, kyunki uski frequency > n/2 hoti hai



























