// Recursion is when a function calls itself to solve a smaller version of the same problem.
// Base case — tells the function when to stop.
// Recursive case — calls the same function with a smaller/simpler input.

// if base case is not added, the recursion never stops, eventually the program crashes because the call 
// stack becomes full which is called Stack Overflow

// Recursion is the programming technique. Recurrence is the mathematical way of describing the cost of that recursion.

// Every backtracking algorithm usually uses recursion, but not every recursive algorithm is backtracking.
// factorial finding through recursion is not normally backtracking algorithm
// Backtracking means:
// Make a choice → explore it → undo the choice → try another choice.
// Backtracking example
// Imagine you're in a maze. you go 
// Start --> Path A --> Path B --> Dead end
// you go backward : Dead end --> Path B
// Then choose another path:Path C
// That's the basic idea of backtracking.
// in programming
// Choose --> Explore --> Undo --> Choose another option
// The undo step is extremely important.



// Call Stack : Whenever a function is called, the computer creates a small memory area called a stack 
// frame containing information needed for that function call.
// like when we call sum(5), the stack roughly becomes
// ┌─────────────┐
// │ sum(1)      │
// ├─────────────┤
// │ sum(2)      │
// ├─────────────┤
// │ sum(3)      │
// ├─────────────┤
// │ sum(4)      │
// ├─────────────┤
// │ sum(5)      │
// └─────────────┘
// then sum(0) is called 
// ┌─────────────┐
// │ sum(0)      │ <-- top
// ├─────────────┤
// │ sum(1)      │
// ├─────────────┤
// │ sum(2)      │
// ├─────────────┤
// │ sum(3)      │
// ├─────────────┤
// │ sum(4)      │
// ├─────────────┤
// │ sum(5)      │
// └─────────────┘
// sum(0) returns 0.
// Its stack frame is removed.
// Then sum(1) continues.
// Then sum(1) returns.
// Then sum(2) continues.
// And so on.
// This is LIFO



#include<iostream>
#include<vector>
using namespace std;

void printNums(int val)
{
    if(val == 0)  // base case
        return;

    // cout<<val<<"  ";

    printNums(val-1);

    cout<<val<<"  ";
}

void print(const vector<int>& current) {
    for (int num : current) {
        cout << num << " ";
    }
    cout << endl;
}


// BackTracking example
void solve(int index, vector<int>& arr, vector<int>& current) {

    if (index == arr.size()) {
        // current is one complete subset
        print(current);
        return;
    }

    // Take arr[index]
    current.push_back(arr[index]);
    solve(index + 1, arr, current);

    // Undo
    current.pop_back();   // this pop_back() is the backtracking

    // Don't take arr[index]
    solve(index + 1, arr, current);
}

int fact(int num)
{
    if(num == 0)   // base is the smallest value of the parameter that we know
        return 1;

    return num * fact(num-1);
}

int sum(int val)  // sum of n numbers using recursion
{
    if(val == 0)
        return 0;
    return val + sum(val-1);
}

// reverse print an array
void reverseArray(int arr[], int size)
{
    if(size == -1)
        return;
    cout<<arr[size]<<"  ";
    reverseArray(arr,size-1);
}

// reverse a vector array
void reverse_vector(vector<int>&v, int s, int e)
{
    if(s >= e)
        return;
    swap(v[s],v[e]);
    reverse_vector(v, s+1, e-1);
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

//                     fibonacci(4)
//                    /            \
//                   /              \
//           fibonacci(3)        fibonacci(2)
//            /       \            /       \
//           /         \          /         \
//    fibonacci(2)  fibonacci(1) fibonacci(1) fibonacci(0)
//       /     \
//      /       \
// fib(1)      fib(0)
// the stack follows depth-first execution, each recursive call gets its own separate stack frame
// n-1 and n-2 are used because every Fibonacci number is the sum of the two previous Fibonacci numbers

bool isSorted(int arr[], int size)
{
    if(size <= 0)
        return true;
    
    if(arr[size] < arr[size-1])
        return false;
    
    return isSorted(arr, size-1);
}


// printing subsets
void printSubsets(vector<int> & arr, vector<int> & ans, int i)   // O(2^n * n)
{
    if(i == arr.size())
    {
        for(int val:ans)
            cout<<val<<"  ";
        cout<<endl;
        return;
    }

    // include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    ans.pop_back();  // back_tracking

    // exclude
    printSubsets(arr, ans, i+1);

}
//                           []
//                        /      \
//                     +1         -1
//                     /           \
//                   [1]            []
//                 /     \        /     \
//               +2      -2      +2       -2
//               /         \      /         \
//           [1,2]         [1]    [2]        []
//           /   \        / \    /   \         / \
//         +3    -3      +3 -3   +3   -3      +3 -3
//         /       \      /   \   \     \     /    \
//    [1,2,3]     [1,2] [1,3] [1]  [2,3] [2] [3]   []




class Solution {
public:
    void getPermutation(vector<int> &nums, int idx, vector<vector<int>>& ans) // TC : O(n! * n), SC: O(n!)
    {
        if(idx == nums.size())
        {
            ans.push_back({nums});
            return;
        }
        for(int i=idx; i<nums.size(); i++)
        {
            swap(nums[idx], nums[i]);

            getPermutation(nums, idx+1, ans);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutation(nums, 0, ans);
        return ans;
    }
};
//          [1,2,3]
//        idx = 0
//      /    |     \
//     /     |      \
//    1      2       3
//   / \    / \     / \
//  2   3  1   3   1   2
//  |   |  |   |   |   |
// 123 132 213 231 312 321
// Start at position 0.

// For every number:
//     Put that number at position 0.
    
//     Now recursively generate
//     all permutations of the remaining positions.
    
//     Undo the change.

// Move to the next possible number.



int main()
{
    // printNums(10);

    // cout<<fact(5)<<endl;

    // cout<<sum(10)<<endl;

    // int arr[] = {345,67,34,57,23,57,34,567};
    // reverseArray(arr,7);
    // cout<<endl;

    // vector<int> v = {45,97,45,75,45,36,43,40};
    // reverse_vector(v,0,7);
    // for(auto i:v)
    //     cout<<i<<"  ";
    // cout<<endl;

    // cout<<fibonacci(5)<<endl;

    // int arr[] = {1,2,4,5,8,9,12,76,89};
    // cout<<isSorted(arr,8)<<endl;

    vector<int> v = {1,2,3};
    vector<int> ans;
    printSubsets(v, ans, 0);
    return 0; 
}











