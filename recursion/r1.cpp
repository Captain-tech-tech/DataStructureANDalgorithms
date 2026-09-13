// Recursion is when a function calls itself to solve a smaller version of the same problem.
// Base case — tells the function when to stop.
// Recursive case — calls the same function with a smaller/simpler input.

// if base case is not added, the recursion never stops, eventually the program crashes because the call 
// stack becomes full which is called Stack Overflow

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
    return 0; 
}











