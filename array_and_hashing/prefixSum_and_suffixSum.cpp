// A prefix sum is a technique where you create a new array where each element at index i stores the 
// cumulative total of all numbers from the beginning of the original array up to i. In contrast, a suffix 
// sum stores the cumulative total from the end of the array back to index i. In C++, you can easily generate 
// a prefix sum using std::partial_sum from the <numeric> library, while a suffix sum is built by applying 
// the same logic in reverse (from rbegin() to rend()). These techniques are widely used in algorithm design 
// to achieve constant-time O(1) range queries, such as finding the sum of any subarray without looping 
// through it repeatedly. They are essential for optimizing performance in problems involving static array 
// range sums, equilibrium point detection, and 2D matrix region calculations, transforming slow O(N) 
// operations into highly efficient checks



