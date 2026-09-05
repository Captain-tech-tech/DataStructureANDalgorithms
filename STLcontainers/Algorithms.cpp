// Comparator  : comparator tells our function logic, comparator are boolean function which return 
// true or false value based upon some comparison 



// Sort
// sort(arr, arr+n)                        ascending order sorting, passing start and end
// sort(arr, arr+n, greater<int>())        for descending order sorting



// sorting algorithms
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// // Custom comparators for sorting data in pairs by second values
// bool cus_com(pair<int,int> p1, pair<int,int>p2)
// {
//     if(p1.second < p2.second) return true;
//     else return false;

//     // if second value is same in both pairs, so then sorting is on the basis of first value
//     if(p1.first < p2.first) return true;
//     else return false;
// }

// int main()
// {
//     int arr[5] = {4,6,3,1,7};  
//     sort(arr, arr+5);   // or  sort(arr.begin(), arr.end());   it works with vector

//     for(auto val:arr)
//     cout<<val<<"   ";
//     cout<<endl;

//     sort(arr,arr,greater<int>());        // greatrt<int>()  is a comparator

//     for(auto val:arr)
//     cout<<val<<"   ";
//     cout<<endl;

//     vector<pair<int,int>> vec = {{56,45},{78,23},{12,57},{23,57}};
    
//     // here sorting works on the basis of first value of pair by-default
//     sort(vec.begin(),vec.end());
//     for(auto p:vec)
//     cout<<p.first<<"   "<<p.second<<endl;

//     // use of custom comparator to sort values on basis of second value of pair
//     sort(vec.begin(),vec.end(),cus_com);
    
//     for(auto val:vec)
//     cout<<val.first<<"   "<<val.second<<endl;

//     return 0;
// }





// reverse algorithm
// reverse(arr.begin(),arr.end())
// reverse(arr.begin() + 2, arr.begin() + 7)         to reverse values of a specific range



// next permutation
// next_permutation(vec.begin(),vec.end())



// swap,min,max
// min(45,56),   max(356,134),  swap(a,b)



// *(min_element(vec.begin(),vec.end()))      // finding minimum element in an array
// *(max_element(vec.begin(),vec.end()))      // finding maximum element in an array

// binary_search(vec.begin(),vec.end(),target)    // it returns a boolean value telling that the target exists or not




// count set bits  
// __buildin_popcount()     // counting number of 1's in a binary form of a number
// __buildin_popcountl()    // it is use if the value is long int
// __buildin_popcountll()   // it is use if the value is long long int

// cout<< __buildin_popcount(n)<<endl;

