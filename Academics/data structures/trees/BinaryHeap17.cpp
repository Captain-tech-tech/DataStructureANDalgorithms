// heap binary trees

// Parent(i)= [i/2]
// LeftChild(i)&=2i
// RightChild(i)&=2i+1


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap
{
private:
    // Index 0 is unused; heap elements start at index 1.
    vector<int> A = {0};

    // Restore max-heap property by moving a node downward.
    // Time: O(log n), where n is the current heap size.
    void SiftDown(int i, int n)
    {
        while (2 * i <= n)
        {
            int left = 2 * i;
            int right = left + 1;
            int largest = left;

            // Select the larger child.
            if (right <= n && A[right] > A[left])
                largest = right;

            // If parent is already larger, heap property holds.
            if (A[i] >= A[largest])
                break;

            swap(A[i], A[largest]);
            i = largest;
        }
    }

public:
    // --------------------------------------------------
    // INSERTION
    // Insert at the end, then move upward.
    // Time: O(log n) worst case.
    // --------------------------------------------------
    void Insert(int value)
    {
        A.push_back(value);
        int i = static_cast<int>(A.size()) - 1;
        // static_cast<int> is used to convert a value from one data type to another explicitly.
        // static_cast<target_type>(value)

        while (i > 1 && A[i] > A[i / 2])
        {
            swap(A[i], A[i / 2]);
            i /= 2;
        }
    }

    // --------------------------------------------------
    // GET MAXIMUM
    // The root contains the largest value.
    // Time: O(1).
    // -------------------------------------------------- const applies to the member function, not to the return value or the parameter.
    bool GetMax(int &result) const // The const keyword at the end of the function declaration means that this function promises not to modify the object's data members.
    {
        if (Size() == 0)
            return false;

        return A[1];
    }

    // --------------------------------------------------
    // DELETE MAXIMUM
    // Replace root with last element and sift downward.
    // Time: O(log n) worst case.
    // --------------------------------------------------
    bool DeleteMax(int &removed)
    {
        int n = Size();

        if (n == 0)
            return false;

        removed = A[1];

        if (n == 1)
        {
            A.pop_back();
            return true;
        }

        A[1] = A.back();
        A.pop_back();

        SiftDown(1, Size());
        return true;
    }

    // --------------------------------------------------
    // HEAPIFY / BUILD MAX HEAP
    // Build a heap from an existing array of values.
    // Time: O(n).
    // --------------------------------------------------
    void BuildHeap(const vector<int> &values)
    {
        A.clear();
        A.push_back(0);  // Unused index 0.

        for (int value : values)
            A.push_back(value);

        int n = Size();

        // Leaves already satisfy the heap property.
        // Start at the last non-leaf and move upward.
        for (int i = n / 2; i >= 1; --i)
            SiftDown(i, n);
    }

    // --------------------------------------------------
    // DISPLAY HEAP ARRAY
    // Time: O(n).
    // --------------------------------------------------
    void Display() const
    {
        if (Size() == 0)
        {
            cout << "(empty heap)\n";
            return;
        }

        for (int i = 1; i <= Size(); ++i)
            cout << A[i] << " ";

        cout << '\n';
    }

    int Size() const
    {
        return static_cast<int>(A.size()) - 1;
    }

    bool Empty() const
    {
        return Size() == 0;
    }

    // --------------------------------------------------
    // HEAP SORT
    // Sorts a COPY of the heap's values in ascending order.
    // Time: O(n log n); extra space: O(n) for the copy.
    // --------------------------------------------------
    vector<int> HeapSort() const
    {
        vector<int> result(A.begin() + 1, A.end());

        int n = static_cast<int>(result.size());

        // Convert the copy to 0-based indexing.
        // For a 0-based array:
        // left child = 2*i + 1
        // right child = 2*i + 2
        auto siftDown = [&result](int i, int end)  // a small helper function that restores the max-heap property
        {
            while (2 * i + 1 < end)
            {
                int left = 2 * i + 1;
                int right = left + 1;
                int largest = left;

                if (right < end && result[right] > result[left])
                {
                    largest = right;
                }

                if (result[i] >= result[largest])
                    break;

                swap(result[i], result[largest]);
                i = largest;
            }
        };

        // Build max heap: O(n).
        for (int i = n / 2 - 1; i >= 0; --i)
            siftDown(i, n);

        // Move maximum to the end repeatedly: O(n log n).
        for (int end = n - 1; end > 0; --end)
        {
            swap(result[0], result[end]);
            siftDown(0, end);
        }

        return result; // Ascending order.
    }
};

int main()
{
    MaxHeap heap;

    // =========================================
    // 1. INSERTION
    // =========================================
    cout << "Inserting values:\n";

    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(30);
    heap.Insert(25);
    heap.Insert(5);
    heap.Insert(40);
    heap.Insert(35);

    cout << "Heap array: ";
    heap.Display();

    // =========================================
    // 2. MAXIMUM ELEMENT
    // =========================================
    int value;

    if (heap.GetMax(value))
        cout << "Maximum element: " << value << '\n';

    // =========================================
    // 3. DELETE MAXIMUM
    // =========================================
    if (heap.DeleteMax(value))
        cout << "Deleted maximum: " << value << '\n';

    cout << "Heap after deletion: ";
    heap.Display();

    // =========================================
    // 4. BUILD HEAP USING HEAPIFY
    // =========================================
    vector<int> values = {10, 20, 30, 25, 5, 40, 35};

    heap.BuildHeap(values);

    cout << "\nHeap built using heapify: ";
    heap.Display();

    // =========================================
    // 5. HEAP SORT
    // =========================================
    vector<int> sorted = heap.HeapSort();

    cout << "Heap sort (ascending): ";
    for (int x : sorted)
        cout << x << " ";

    cout << '\n';

    // The original heap is unchanged by HeapSort().
    cout << "Original heap after heap sort: ";
    heap.Display();

    // =========================================
    // 6. SIZE AND EMPTY CHECK
    // =========================================
    cout << "Number of elements: " << heap.Size() << '\n';
    cout << "Is heap empty? "
         << (heap.Empty() ? "Yes" : "No") << '\n';

    return 0;
}














// first we insert value in the array, and then this function is called for rearranging the values
// insertion time for one element is always O(log2(n))
// void Insert(int A[], int n)  // A[] represents the binary max heap , n represent the index at which the new element is stored

// Heap sort
// (1) createHeap of 'n' elements
// (2) then delete 'n' elements 1-by-1



// deleting an element and storing it at the last place
// int delete(int A[], int n)// deletion of one element takes log(n) time, so deletion of n elements takes nlog(n) time. so TC: O(nlog(n))

// inplace heap creation
// void createHeap()  // for one element log(n) time is taken so for n element n log(n) time is taken, so TC : O(nlog(n))


// in insertion, the direction of adjusting heap is from leaf towards to root
// and in deletion, the direction of adjusting is from root towards leaf
// both takes O(nlog(n)) time



// heapify
// heapify is faster method for creating a heap, here TC is O(n)



// binary heap as a priority queue
// heap helps us to implement priority queue
// heap is the best data structure for implementing priority queue
// both insertion and deletion takes log(n), log(n) time
// if we say smaller element is having higher priority then use min heap for priority queue

// larger the element higher the priority
// inertion takes O(1) time and deletion takes O(n) time




















// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class MinHeap
// {
// private:
//     // Index 0 is unused; actual heap starts at index 1.
//     vector<int> A = {0};

//     // Restore min-heap property by moving a node downward.
//     void SiftDown(int i, int n)
//     {
//         while (2 * i <= n)
//         {
//             int left = 2 * i;
//             int right = 2 * i + 1;
//             int smallest = left;

//             // Find the smaller child.
//             if (right <= n && A[right] < A[left])
//             {
//                 smallest = right;
//             }

//             // If parent is already smaller, heap property is satisfied.
//             if (A[i] <= A[smallest])
//             {
//                 break;
//             }

//             swap(A[i], A[smallest]);
//             i = smallest;
//         }
//     }

// public:
//     // Insert an element into the min-heap.
//     void Insert(int value)
//     {
//         A.push_back(value);

//         int i = static_cast<int>(A.size()) - 1;

//         // Sift up until the min-heap property is restored.
//         while (i > 1 && A[i] < A[i / 2])
//         {
//             swap(A[i], A[i / 2]);
//             i = i / 2;
//         }
//     }

//     // Get the minimum element without removing it.
//     bool GetMin(int &result) const
//     {
//         if (Empty())
//         {
//             return false;
//         }

//         result = A[1];
//         return true;
//     }

//     // Remove and return the minimum element.
//     bool DeleteMin(int &removed)
//     {
//         if (Empty())
//         {
//             return false;
//         }

//         removed = A[1];

//         // If only one element exists, remove it.
//         if (Size() == 1)
//         {
//             A.pop_back();
//             return true;
//         }

//         // Move the last element to the root.
//         A[1] = A.back();
//         A.pop_back();

//         // Restore min-heap property.
//         SiftDown(1, Size());

//         return true;
//     }

//     // Build a min-heap from an existing vector.
//     void BuildHeap(const vector<int> &values)
//     {
//         A.clear();
//         A.push_back(0);

//         for (int value : values)
//         {
//             A.push_back(value);
//         }

//         int n = Size();

//         // Start from the last internal node and sift down.
//         for (int i = n / 2; i >= 1; --i)
//         {
//             SiftDown(i, n);
//         }
//     }

//     // Display heap elements in array order.
//     void Display() const
//     {
//         if (Empty())
//         {
//             cout << "Heap is empty.\n";
//             return;
//         }

//         cout << "Min-Heap: ";

//         for (int i = 1; i <= Size(); ++i)
//         {
//             cout << A[i] << " ";
//         }

//         cout << '\n';
//     }

//     // Return the number of elements.
//     int Size() const
//     {
//         return static_cast<int>(A.size()) - 1;
//     }

//     // Check whether the heap is empty.
//     bool Empty() const
//     {
//         return Size() == 0;
//     }

//     // HeapSort: return elements in ascending order.
//     // The original heap remains unchanged.
//     vector<int> HeapSort() const
//     {
//         vector<int> result = A;

//         int n = static_cast<int>(result.size()) - 1;

//         // Local helper lambda to restore min-heap property.
//         auto siftDown = [&result](int i, int end)
//         {
//             while (2 * i <= end)
//             {
//                 int left = 2 * i;
//                 int right = 2 * i + 1;
//                 int smallest = left;

//                 if (right <= end &&
//                     result[right] < result[left])
//                 {
//                     smallest = right;
//                 }

//                 if (result[i] <= result[smallest])
//                 {
//                     break;
//                 }

//                 swap(result[i], result[smallest]);
//                 i = smallest;
//             }
//         };

//         // Move each minimum to the end of the active heap.
//         for (int end = n; end > 1; --end)
//         {
//             swap(result[1], result[end]);
//             siftDown(1, end - 1);
//         }

//         // A min-heap produces descending order with this
//         // swap-to-the-end approach, so reverse the result.
//         reverse(result.begin() + 1, result.end());

//         // Remove the unused index 0 before returning.
//         result.erase(result.begin());

//         return result;
//     }
// };

// int main()
// {
//     MinHeap heap;

//     heap.Insert(40);
//     heap.Insert(20);
//     heap.Insert(50);
//     heap.Insert(10);
//     heap.Insert(30);

//     heap.Display();

//     int result;

//     if (heap.GetMin(result))
//     {
//         cout << "Minimum element: " << result << '\n';
//     }

//     int removed;

//     if (heap.DeleteMin(removed))
//     {
//         cout << "Deleted minimum: " << removed << '\n';
//     }

//     heap.Display();

//     vector<int> values = {45, 12, 30, 8, 25, 60};

//     heap.BuildHeap(values);

//     cout << "\nAfter BuildHeap:\n";
//     heap.Display();

//     vector<int> sorted = heap.HeapSort();

//     cout << "Sorted elements: ";

//     for (int value : sorted)
//     {
//         cout << value << " ";
//     }

//     cout << '\n';

//     cout << "Heap size: " << heap.Size() << '\n';
//     cout << "Is heap empty? "
//          << (heap.Empty() ? "Yes" : "No") << '\n';

//     return 0;
// }













