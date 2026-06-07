// Pair sum       here the time complexity is O(n*2)
// #include<iostream>
// using namespace std;
// int main()
// {
//     int s;cout<<"Enter the size of your array : ";cin>>s;
//     cout<<"Enter "<<s<<" elements in your array : ";

//     int arr[s];
//     for(int i=0;i<s;i++)
//     cin>>arr[i];

//     int n;cout<<"Enter the pair expected sum you wanna find : ";cin>>n;
//     int flag=0;

//     int sum=0;
//     for(int i=0;i<s;i++)
//     {
//         for(int j=i+1;j<s;j++)
//         {
//             sum=arr[i]+arr[j];
//             if(sum==n)
//             {
//                 cout<<"you required sum is the sum of numbers at indexes : "<<i<<", "<<j<<endl;
//                 flag=1;
//                 break;
//             }
//         }
//     }
//     if(flag==0)
//     {
//         cout<<"No such is being found!"<<endl;
//     }
//     return 0;
// }



// return pair in sorted array with target sum ----> input are in sorted order 
// this code is using 2 pointer approach --->time complexity O(n*1)
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n;cout<<"Enter the size of your array : ";cin>>n;
//     vector<int>v(n);

//     cout<<"Enter "<<n<<" numbers for your vector : ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }

//     int target;cout<<"Enter the target sum, you wanna find : ";cin>>target;

//     int i1,i2,s=0,e=n-1;
//     while(s<e)
//     {
//         int h=v[s]+v[e];
//         if(h==target)
//         {
//             i1=s,i2=e;
//             break;
//         }
//         else if(h>target)
//         {
//             e--;
//         }
//         else if(h<target)
//         {
//             s++;
//         }
//     }

//     cout<<"Your required sum is the sum of numbers at indexes "<<i1<<", "<<i2<<endl;
//     return 0;
// }
























