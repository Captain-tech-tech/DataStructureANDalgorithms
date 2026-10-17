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




