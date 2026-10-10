

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


//  Bubble Sort vs Insertion Sort
// | Cases    | Bubble Sort | Insertion Sort |
// | Min Comp | O(n)       | O(n) |        if already in ascending order
// | Max Comp | O(n^2)     | O(n^2) |      if already in descending order
// | Min Swap | O(1)       | O(1) |        ascending
// | Max Swap | O(n^2)     | O(n^2) |      descending
// | Adaptive | ✓ Yes      | ✓ Yes |
// | Stable   | ✓ Yes      | ✓ Yes |
// | Linked List | No      | Yes |
// | K Passes    | Yes     | No |

// O(n^2)
void bubbleSort(vector<int>&arr) // if arr is already sorted, so in one pass it perform n-1 comparisons and so then TC:O(n)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int flag = 0;//flag is used if no swap occurs during any pass, then it means the remaining array is sorted, so break the loop
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = 1; 
            }
        }
        if(flag == 0)
            break;// this condition can be true in any pass, and if the array is already sorted, the loop will direectly break
    }
}


// O(n^2)
void insertionSort(vector<int>&arr)
{
    int n = arr.size();
    for(int i=1;i<n;i++) // start from index 1, as we initially consider array size to be 1 which is sorted, and then insert elements one by one
    {
        int j = i-1;
        int x = arr[i];
        while(j>-1 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


void selectionSort(vector<int>&arr)
{
    int n = arr.size();
    int j,k;
    for(int i=0;i<n;i++)
    {
        for(j=k=i;j<n;j++)
            if(arr[j]<arr[k])
                k = j;
        swap(arr[i],arr[k]);
    }
}

int partition(vector<int>& A, int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do { i++; } while (A[i] <= pivot);
        do { j--; } while (A[j] > pivot);

        if (i < j)
            swap(A[i], A[j]);

    } while (i < j);

    swap(A[l], A[j]);
    return j;
}

// recursive function to actually sort the array
void quickSort(vector<int>& A, int l, int h)
{
    if (l < h)
    {
        int j = partition(A, l, h);
        quickSort(A, l, j);     // sorts the left side
        quickSort(A, j + 1, h); // sorts the right side
    }
}


// O(m+n)   
// merge here applies on two arrays and returns a sorted new array
vector<int> merge(const vector<int>& A, const vector<int>& B)
{
    int m = A.size();
    int n = B.size();
    
    // allocate space for the merged vector C
    vector<int> C(m + n); 
    int i = 0, j = 0, k = 0;
    // compare elements from both vectors and copy the smaller one
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for (;i<m;i++)
        C[k++] = A[i];
    for (;j<n;j++)
        C[k++] = B[j];
    return C;
}

// if there are two lists inside one array and we want to sort the array  like  [2,5,8,12,3,6,7,10]
void merging(vector<int>& A, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    
    // create temporary vector B of size h + 1 to accommodate indices up to h
    vector<int> B(h + 1);

    // compare and merge elements into B
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    // copy remaining elements from the left sorted half
    for (; i <= mid; i++)
        B[k++] = A[i];

    // copy remaining elements from the right sorted half
    for (; j <= h; j++)
        B[k++] = A[j];

    // copy the merged elements back into the original vector A
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

// Iterative mergeSort function
void IMergeSort(vector<int>& A)
{
    int n = A.size();
    int p, i, l, mid, h;

    // outer loop sizes passes by powers of 2 (2, 4, 8...)
    for (p = 2; p <= n; p = p * 2)
    {
        // inner loop merges pairs of sub-arrays of size p
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;    
            merging(A, l, mid, h);
        }
    }
    // if the array size is not a perfect power of 2, merge the remaining elements left over at the end
    if (p / 2 < n)   // like if an array contains 5,7 or 9 elements
    {
        merging(A, 0, (p / 2) - 1, n - 1);
    }
}

// recursive way of merge sort
void RMergeSort(vector<int>& A, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        RMergeSort(A, l, mid);      // recursively sort the left half
        RMergeSort(A, mid + 1, h);  // recursively sort the right half
        
        merging(A, l, mid, h);       // merge the two sorted halves together
    }
}



// count sort algorithm
void countSort(vector<int>& A)
{
    if (A.empty()) return;

    auto maxVal = max_element(A.begin(), A.end());   // max_element function is present in <algorithm>
    int max = *maxVal;
    int i, j;

    // create the count array 'C' initialized with 0s, which size is max + 1 to accommodate indices from 0 up to max
    vector<int> C(max + 1, 0);

    // Count the frequency of each element in A
    for (i = 0; i < A.size(); i++)
    {
        C[A[i]]++;
    }

    // Copy sorted elements back from C into original vector A
    i = 0; // Index pointer for count vector C
    j = 0; // Index pointer for original vector A
    
    while (i < max + 1)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
        {
            i++;
        }
    }
}



// radix sort algorithm 
void RadixSort(vector<int>& A)
{
    if (A.empty()) return;

    auto maxVal = max_element(A.begin(),A.end());
    int max = *maxVal;
    int n = A.size();

    // 2D Vector representing 10 Bins (indices 0 to 9)
    vector<vector<int>> bins(10);

    // loop through each place value: 1s, 10s, 100s...,  exp represents the denominator
    for (int exp=1; max/exp>0; exp*=10)
    {
        // distribute elements into the bins based on the current digit
        for (int i = 0; i < n; i++)
        {
            int binIndex = (A[i] / exp) % 10;
            bins[binIndex].push_back(A[i]);
        }

        // collect elements back from the bins into original vector A
        int idx = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int num : bins[i])
            {
                A[idx++] = num;
            }
            bins[i].clear(); // Clear the bin for the next pass
        }
    }
}


// bin/bucket sort algorithm
void binSort(vector<int>& A)
{
    if (A.empty()) return;

    auto maxVal = max_element(A.begin(), A.end());
    int max = *maxVal;

    // create a 2D vector of bins initialized up to index 'max'
    vector<vector<int>> Bins(max + 1);

    // insert elements into their respective bins
    for (int i = 0; i < A.size(); i++)
    {
        Bins[A[i]].push_back(A[i]);
    }

    // collect elements back into the original vector A
    int i = 0; // Index pointer for bins
    int j = 0; // Index pointer for array A

    while (i < max + 1)
    {
        // if a bin contains elements, dump them sequentially into A
        for (int element : Bins[i])
        {
            A[j++] = element;
        }
        i++;
    }
}


int main()
{
    // vector<int>arr = {8,5,7,3,2};

    // bubbleSort(arr);
    // insertionSort(arr);
    // selectionSort(arr);
    // vector<int>arr1 = {8,5,7,3,2,INT_MAX};
    // quickSort(arr1,0,arr1.size()-1);

    // for(int i=0;i<arr.size()-1;i++)
    //     cout<<arr[i]<<"  ";

    vector<int> arr = {8, 3, 7, 4, 9, 2, 6, 5};
    // RMergeSort(arr,0,arr.size()-1);
    

    // countSort(arr);

    // RadixSort(arr);

    binSort(arr);

    for (int num : arr)
        cout << num << " ";    
    
    return 0;
}










