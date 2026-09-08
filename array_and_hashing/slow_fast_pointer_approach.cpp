// The slow-fast pointer approach (also known as Floyd's Tortoise and Hare algorithm)
// is a pointer manipulation technique in C++ used primarily for traversing linear 
// data structures like linked lists or arrays. It involves initializing two pointers
// at the starting node: a slow pointer that advances by one step at a time, and a 
// fast pointer that advances by two steps at a time. Because of this speed 
// differential, if a cycle or loop exists within the structure, the fast pointer 
// will eventually catch up and meet the slow pointer from behind. Conversely, if 
// there is no cycle, the fast pointer will safely reach the end of the structure 
// first. This gap-closing mechanic makes the approach highly efficient, allowing 
// programmers to detect cycles, find the middle element of a linked list, or 
// locate the start of a loop in O(N) time complexity and O(1) auxiliary space.




// In duplicate detection, the array values act as "next" pointers, transforming the array into a linked 
// list where a duplicate number represents a node with multiple incoming edges, creating a cycle. 
// For example, if nums[0] = 1 and nums[2] = 1, both indices 0 and 2 point to index 1, guaranteeing a loop. 
// The slow pointer moves one step at a time (slow = nums[slow]) while the fast pointer moves two steps 
// (fast = nums[nums[fast]]) until they collide inside the cycle. To find the exact duplicate, you reset one
// pointer to the start and move both at a speed of one step per turn; the point where they meet again is 
// the duplicate value because it marks the entrance to the loop.

// The structural math: Mathematical proof shows that the distance from the start of the array to the 
// entrance of the loop is exactly equal to the distance from the collision point to the entrance of the loop (modulo the loop length).



// slow-fast pointer approach is use for detecting a cycle in a linked list, finding the middle node of a linked list.



// find the duplicate number
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int> v = {1,3,4,2,2};
//     int slow = v[0], fast = v[0];

//     do{
//         slow = v[slow], fast = v[v[fast]];
//     }
//     while(slow != fast);

//     slow = v[0];

//     while(slow != fast)
//     {
//         slow = v[slow];
//         fast = v[fast];
//     }
//     cout<<slow<<endl;
//     return 0;
// }





// using unordered set to solve the same problem 
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int>s;
//         for(int val:nums)
//         {
//             if(s.find(val) != s.end())
//                 return val;
//             s.insert(val);
//         }
//         return -1;
//     }
// };

