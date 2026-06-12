// subarray is the continous part of a given array 
// if the size of an array is n, then the number of subarrays is equal to n*(n+1)/2

// like :
//  int arr[] = {10, 20, 30, 40, 50};
// // then the subarrays would be :
// {10}
// {20}
// {30}
// {40}
// {50}
// {10, 20}
// {20, 30}
// {30, 40}
// {40, 50}
// {10, 20, 30}
// {20, 30, 40}
// {30, 40, 50}
// {10, 20, 30, 40}
// {20, 30, 40, 50}
// {10, 20, 30, 40, 50}

// as n=5, so the number of subarrays is 15




// code for printing all subarrays of an arrray
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;cout<<"Enter the size of the array : ";cin>>n;
//     int arr[n];
//     cout<<"Enter "<<n<<" elements in your array : ";
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     cout<<endl;      // 1 , 2 , 3 , 4 , 5 
//     for(int start=0;start<n;start++)
//     {
//         for(int end=start;end<n;end++)
//         {
//             cout<<"{";
//             for(int i=start;i<=end;i++)
//             {
//                 cout<<arr[i];
//                 if(i!=end)
//                 cout<<",";
//             }
//             cout<<"}";
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }





//  Maximum Subarray Sum  (complexity :  O(n*3))
// finding the subarray with maximum sum of its values 
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;cout<<"Enter the size of your array : ";cin>>n;
//     cout<<"Enter "<<n<<" elements in your array : ";

//     int array[n];
//     for(int i=0;i<n;i++)
//     cin>>array[i];

//     int highest_sum=array[0];
//     int sum;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             sum=0;
//             for(int k=i;k<=j;k++)
//             {
//                 sum+=array[k];
//             }
//             if(highest_sum<sum)
//             highest_sum=sum;
//         }
//     }

//     cout<<"The highest sum : "<<highest_sum<<endl;
//     return 0;
// }


//  Maximum Subarray Sum  (complexity :  O(n*2))
// brute force approach means simple approach towards solving a problem
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;cout<<"Enter the size of your array : ";cin>>n;
//     cout<<"Enter "<<n<<" elements in your array : ";

//     int array[n];
//     for(int i=0;i<n;i++)
//     cin>>array[i];

//     int highest_sum=array[0];
//     int current_sum;

//     for(int i=0;i<n;i++)
//     {
//         current_sum=0;
//         for(int j=i;j<n;j++)
//         {
//             current_sum+=array[j];
//             highest_sum=max(highest_sum,current_sum);
//         }
//     }

//     cout<<"The maximum sum : "<<highest_sum<<endl;

//     return 0;
// }



// maximum subarray sum through Kadane's algorithm   (complexity :  O(n*1))
// most optimise approach
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;cout<<"Enter the size of your array : ";cin>>n;
    
//     cout<<"Enter "<<n<<" elements in your array : ";
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];

//     int current_sum=0,max_sum=arr[0];

//     for(int i=0;i<n;i++)
//     {
//         current_sum+=arr[i];
//         max_sum=max(max_sum,current_sum);
//         if(current_sum<0)
//         current_sum=0;
//     }
//     cout<<"The maximum sum : "<<max_sum<<endl;
//     return 0;
// }
// Kadane's algorithm is like a kind of dynamic programming algorithm

// logic of kadane's algorithm
// "Agar current sum negative ho jaye, toh usse carry karne ka koi fayda nahi hai, kyunki 
// woh aage ke sum ko aur chhota karega. Isliye current sum ko 0 se restart kar dete
// hain. Har step par maximum sum ko update karte rehte hain. End mein jo sabse bada
// sum mila, wahi maximum subarray sum hota hai."





    








































