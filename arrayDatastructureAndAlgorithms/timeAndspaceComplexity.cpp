// Resources for learning Algorithms : Cormen, Master's theorem 


// Time Complexity : it is not the actual time taken but amount of time taken (operations) as a function of input size(n)

// Big O notation : 
// for finding the time complexity from a function 
// step (1) : ignores the constants
// step (2) : consider only the largest term
// e.g : 
// f(n) = 3n^2+5n+7
// step (1) : n^2+n+1
// step (2) : n^2  so time complexity is   O(n*2)


// Different time complexities  :
// worse case scenario = O = upper bound
// average case = teta 
// best case scenario = omega = lower bound




// Space Complexity : Amount of space taken by an algorithm as a function of input size(n)

// Space Complexity means how much extra memory a program needs while running.
// Think of RAM as your workspace on a desk.
// If a program uses only a few variables, it needs very little extra space → O(1).
// If the memory grows as the input grows, the space complexity increases → O(n).
// Space complexity does not focus on how fast the program runs; it focuses on how much memory it uses.
// e.g : 

/*#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}*/

// We only use a few variables: n, sum, and i.
// Whether n = 5 or n = 1,000,000, the number of variables stays the same.
// Memory usage does not grow with the input size.
// Space Complexity = O(1) (Constant Space)

// if one array is given and we are ask to make another array and store the squares of the numbers in the second array then 
// time complexity is  O(n*1)




// Common time complexity :

// O(1)      e.g : sum of numbers from 1 to n 
// int n;
// cin>>n;
// int ans=n*(n*1)/2;


// Linear time complexity : O(n) ---> big of n

// e.g : finding factorial
// int fact=1;int n;cin>>n;
// for(int i=1;i<=n;i++)
// fact*=i;

// similarly Kadane's algorithm and fibonacci dynamic programming comes under O(n) time complexity

// bubble sort, insertion sort and selection sort have time complexity O(n*2)

// binary search algorithm uses O(log(n)) time complexity
// if in a any algorithm, the value becomes half after every iteration, then the time complexity is O(log(n))

// O(nlog(n)) time complexity is used in optimize search algorithms like merge sort, quick sort, greedy algorithms

// O(2*n) ---> exponential time complexity ---> time complexity is used in recursions in brute force approach

// in recurssion n queens brute force approach uses  O(n!) factorial time complexity, also use in knight tour, or in case of
// string finding all possible permutations 


// finding prime number and its complexity
// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cout << "Enter N: ";
//     cin >> N;
//     for (int num = 2; num <= N; num++) {
//         bool isPrime = true;
//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
//         if (isPrime)
//             cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }
// time complexity  is   i*i=n  so i= under root n 
// so the time complexity is under root n 





// Selection Sort 
// #include <iostream>
// using namespace std;
// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         // Find the smallest element in the unsorted part
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         // Swap the found minimum element with the first element
//         swap(arr[i], arr[minIndex]);
//     }
// }
// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     selectionSort(arr, n);
//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
//time complexity  O(n*2)








// | Maximum N in Constraints | Maximum Safe Complexity | Typical Techniques            |
// | ------------------------ | ----------------------- | ----------------------------- |
// | N ≤ 10                   | O(N!), O(2ᴺ)            | Brute Force, Backtracking     |
// | N ≤ 20                   | O(2ᴺ)                   | Bitmasking, Recursion         |
// | N ≤ 100                  | O(N³)                   | Triple Loops                  |
// | N ≤ 1,000                | O(N²)                   | Nested Loops                  |
// | N ≤ 100,000              | O(N log N)              | Sorting, Binary Search        |
// | N ≤ 1,000,000            | O(N)                    | Arrays, Hash Maps, Prefix Sum |
// | N > 1,000,000            | O(log N) or O(1)        | Binary Search, Math           |











// do 215 number leetcode question





// leetcode  question number # 50

// if a decimal number has n digits  then its binary form has maximum  logn+1 (log is base 2)  digits
// e.g : 8=1000     as log8=3 so   8 binary form has four digits

// so computing n*x has a time complexity O(logn) when x is taken in binary form 
// #include<iostream>
// using namespace std;
// int main()
// {
//     double x;cout<<"Enter your number : ";cin>>x;
//     int n;cout<<"Enter the power you wanna find : ";cin>>n;

//     if(n==0 || x==1)
//     cout<<"Your answer is : "<<1<<endl;
//     if(x==0)
//     cout<<"Your answer is : "<<0<<endl;

//     if(x==-1 && n%2==0)
//     cout<<"Your answer is : "<<1<<endl;
//     else if(x==-1 && n%2!=0)
//     cout<<"Your answer is : "<<-1<<endl;


//     long binaryf=n;double ans=1;

//     if(binaryf<0)  // this condition is check for a negative power
//     {
//         x=1/x;
//         binaryf=-binaryf;
//     }
//     while(binaryf>0)
//     {
//         if(binaryf%2==1)
//         {
//             ans*=x;
//         }
//         x*=x;
//         binaryf/=2;
//     }
//     cout<<"You answer is : "<<ans<<endl;

//     return 0;
// }





// stock best buy and sell day   121 number code
// #include <iostream>
// using namespace std;
// int main()
// {
//     int s;cout << "Enter the number of days of data: ";cin >> s;
//     if (s < 2)
//     {
//         cout << "Need at least 2 days of prices.\n";
//         return 0;
//     }

//     double arr[s];

//     cout << "Enter stock prices: ";
//     for (int i = 0; i < s; i++)
//         cin >> arr[i];

//     double bestbuy = arr[0];
//     int buyDay = 0;

//     double maxProfit = 0;
//     int bestBuyDay = 0;
//     int bestSellDay = 0;

//     for (int i = 1; i < s; i++)
//     {
//         if (arr[i] - bestbuy > maxProfit)
//         {
//             maxProfit = arr[i] - bestbuy;
//             bestBuyDay = buyDay;
//             bestSellDay = i;
//         }

//         if (arr[i] < bestbuy)
//         {
//             bestbuy = arr[i];
//             buyDay = i;
//         }
//     }

//     if (maxProfit > 0)
//     {
//         cout << "Best day to buy: " << bestBuyDay << endl; // it is the best day, not the best price 
//         cout << "Best day to sell: " << bestSellDay << endl;
//         cout << "Maximum profit: " << maxProfit << endl;
//     }
//     else
//         cout << "No profit possible. Maximum profit: 0" << endl;

//     return 0;
// }                                                                                                                                                                                                                                                                                                                                      







// solve   50 , 121 , 11 , 




// Container with most water 

// O(n*2)
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>height={1,8,6,2,5,4,8,3,7};
//     int maxwater=0;
//     for(int i=0;i<height.size();i++)
//     {
//         for(int j=i+1;j<height.size();j++)
//         {
//             if(height[i]<height[j])
//             {
//                 int ran=height[i]*(j-i);
//                 maxwater=max(ran,maxwater);
//             }
//             else if(height[j]<height[i])
//             {
//                 int ran=height[j]*(j-i);
//                 maxwater=max(ran,maxwater);
//             }
//         }
//     }
//     cout<<"The maximum amount of water the container can store : "<<maxwater<<endl;
//     return 0;
// }



// optimising the above question with two pointer approach 
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>h={1,8,6,2,5,4,8,3,7};
//     int maxwater=0;
//     int s=0,e=h.size()-1;
//     for(int i=0;i<h.size()/2;i++)
//     {
//         if(h[s]<h[e])
//         {
//             int r=h[s]*(e-s);
//             maxwater=max(maxwater,r);
//             s++;
//         }
//         else if(h[e]<h[s])
//         {
//             int r=h[e]*(e-s);
//             maxwater=max(maxwater,r);
//             e--;
//         }
//     }
//     cout<<"The maximum amount of water the container can store : "<<maxwater<<endl;
//     return 0;
// }










// product of array except self 

// O(n*2)
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>nums={1,2,3,4};
//     vector<int>ans(nums.size(),0);
//     int product=1;
//     for(int i=0;i<nums.size();i++)
//     {
//         product=1;
//         for(int j=0;j<nums.size();j++)
//         {
//             if(j!=i)
//             product*=nums[j];
//         }
//         ans[i]=product;
//     }
//     cout<<"Your given array : ";
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }









// * is the deference operator 
// #include<iostream>
// using namespace std;
// int main()
// {
//     int a=34;
//     cout<<a<<endl<<&a<<endl;
//     int* b=&a;
//     cout<<*b<<endl<<b<<endl;
//     cout<<&b<<endl;

//     int**ptr=&b;
//     cout<<**ptr<<endl<<*ptr<<endl<<ptr<<endl;


//     int arr[]={34,45,34,45};
//     cout<<"Array base address : "<<arr<<endl;
//     int c=34;
//     // arr=&c;  // arrays are constant pointers, you can't change the address stored inside
//     return 0;
// }






// }}}}}}}}}}}}}}}}}}}}}}}}}


// binary search algorithm  works on sorted array  and  its time complexity is O(log(n))
// a monotonic function is a function which is non-increasing or non-decrreasing 
// the mid value in an array   =  (start+end)/2 
// best approach for finding mid value    mid=start + (end-start)/2 


// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
//     public:
//     int findTarget(vector<int>& nums,int tar)
//     {
//         int start=0,end=nums.size()-1;
//         while(start<=end)
//         {
//             int mid=(start+end)/2;
//             if(nums[mid]>tar)
//             {
//                 end=mid-1;
//             }
//             else if(nums[mid]<tar)
//             {
//                 start=mid+1;
//             }
//             else if(nums[mid]==tar)
//             return mid;
//         }
//         return -1;
//     }
// };
// int main()
// {
//     vector<int>nums={-1,0,3,4,5,9,12};
//     int target;cout<<"Enter your target : ";cin>>target;

//     Solution s1;
//     cout<<"Your target is found at index : "<<s1.findTarget(nums,target)<<endl;
//     return 0;
// }



// #include<iostream>
// #include<vector>
// using namespace std;

// int mBinarySearch(vector<int>&arr,int tar,int sta,int end)
// {
//     if(sta<=end)
//     {
//     int mid=sta + (end-sta)/2;

//     if(tar>arr[mid])
//     {
//         return mBinarySearch(arr,tar,mid+1,end);
//     }
//     else if(tar<arr[mid])
//     {
//         return mBinarySearch(arr,tar,sta,mid-1);
//     }
//     else 
//     return mid;
//     }
//     return -1;
// }
// int main()
// {
//     vector<int>arr={-1,0,3,4,5,9,12};
//     int target=5;

//     cout<<"The target is at index : "<<mBinarySearch(arr,target,0,6)<<endl;
    
//     return 0;
// }



// }}}}}}}}}}}}}}}}}}}}}}

 



// solve problem    852,  


























































