


// // chaining
// #include <iostream>
// using namespace std;
// #define SIZE 10

// // Node structure
// struct Node
// {
//     int data;
//     Node *next;
// };

// // Hash function
// int hashFunction(int key)
// {
//     return key % SIZE;
// }

// // Insert an element into the hash table
// void Insert(Node *HT[], int key)
// {
//     int index = hashFunction(key);

//     Node *newNode = new Node;
//     newNode->data = key;

//     // Insert at the beginning of the linked list
//     newNode->next = HT[index];
//     HT[index] = newNode;
// }

// // Search for an element
// Node *Search(Node *HT[], int key)
// {
//     int index = hashFunction(key);
//     Node *temp = HT[index];

//     while (temp != nullptr)
//     {
//         if (temp->data == key)
//             return temp;

//         temp = temp->next;
//     }

//     return nullptr;
// }

// // Display the hash table
// void Display(Node *HT[])
// {
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << i << " -> ";

//         Node *temp = HT[i];

//         while (temp != nullptr)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }

//         cout << "NULL" << endl;
//     }
// }

// // Main function
// int main()
// {
//     Node *HT[SIZE];

//     // Initialize hash table
//     for (int i = 0; i < SIZE; i++)
//     {
//         HT[i] = nullptr;
//     }

//     // Insert elements
//     Insert(HT, 12);
//     Insert(HT, 22);
//     Insert(HT, 42);

//     // Display hash table
//     cout << "Hash Table:" << endl;
//     Display(HT);

//     // Search for 21
//     Node *temp = Search(HT, 21);

//     if (temp != nullptr)
//         cout << "\nElement found: " << temp->data << endl;
//     else
//         cout << "\nElement 21 not found!" << endl;

//     // Search for 22
//     temp = Search(HT, 22);

//     if (temp != nullptr)
//         cout << "Element found: " << temp->data << endl;
//     else
//         cout << "Element 22 not found!" << endl;

//     // Free allocated memory
//     for (int i = 0; i < SIZE; i++)
//     {
//         Node *current = HT[i];

//         while (current != nullptr)
//         {
//             Node *nextNode = current->next;
//             delete current;
//             current = nextNode;
//         }
//     }

//     return 0;
// }









// #include <iostream>
// #include <vector>
// using namespace std;

// class HashTable
// {
// private:
//     enum State { EMPTY, OCCUPIED, DELETED };

//     vector<int> H;
//     vector<State> state;
//     int SIZE;

//     // Hash function
//     int hashFunction(int key) const
//     {
//         int index = key % SIZE;
//         return (index + SIZE) % SIZE;
//     }

//     // Linear probing function
//     int probe(int index, int i) const
//     {
//         return (index + i) % SIZE;
//     }

// public:
//     // Constructor
//     explicit HashTable(int size)
//         : SIZE(size > 0 ? size : 10),
//           H(SIZE),
//           state(SIZE, EMPTY)
//     {
//     }

//     // Insert a key
//     bool Insert(int key)
//     {
//         int index = hashFunction(key);
//         int firstDeleted = -1;

//         for (int i = 0; i < SIZE; i++)
//         {
//             int pos = probe(index, i);

//             if (state[pos] == OCCUPIED)
//             {
//                 if (H[pos] == key)
//                 {
//                     cout << key << " already exists.\n";
//                     return false;
//                 }
//             }
//             else if (state[pos] == DELETED)
//             {
//                 if (firstDeleted == -1)
//                     firstDeleted = pos;
//             }
//             else // EMPTY
//             {
//                 int target =
//                     (firstDeleted != -1) ? firstDeleted : pos;

//                 H[target] = key;
//                 state[target] = OCCUPIED;

//                 cout << key << " inserted at index "
//                      << target << ".\n";
//                 return true;
//             }
//         }

//         // Reuse a deleted slot if the table has no EMPTY slots
//         if (firstDeleted != -1)
//         {
//             H[firstDeleted] = key;
//             state[firstDeleted] = OCCUPIED;

//             cout << key << " inserted at index "
//                  << firstDeleted << ".\n";
//             return true;
//         }

//         cout << "Hash table is full. Cannot insert "
//              << key << ".\n";
//         return false;
//     }

//     // Search for a key
//     int Search(int key) const
//     {
//         int index = hashFunction(key);

//         for (int i = 0; i < SIZE; i++)
//         {
//             int pos = probe(index, i);

//             // An EMPTY slot means the key cannot occur later
//             if (state[pos] == EMPTY)
//                 return -1;

//             if (state[pos] == OCCUPIED && H[pos] == key)
//                 return pos;
//         }

//         return -1;
//     }

//     // Remove a key
//     bool Remove(int key)
//     {
//         int pos = Search(key);

//         if (pos == -1)
//         {
//             cout << key << " not found.\n";
//             return false;
//         }

//         // Mark as DELETED, not EMPTY
//         state[pos] = DELETED;

//         cout << key << " removed from index "
//              << pos << ".\n";
//         return true;
//     }

//     // Display the hash table
//     void Display() const
//     {
//         cout << "\nHash Table:\n";

//         for (int i = 0; i < SIZE; i++)
//         {
//             cout << "[" << i << "] -> ";

//             if (state[i] == EMPTY)
//                 cout << "EMPTY";
//             else if (state[i] == DELETED)
//                 cout << "DELETED";
//             else
//                 cout << H[i];

//             cout << '\n';
//         }
//     }
// };

// int main()
// {
//     HashTable HT(10);

//     // Insert values
//     HT.Insert(12);
//     HT.Insert(22);
//     HT.Insert(42);
//     HT.Insert(32);

//     HT.Display();

//     // Search for a key
//     int key = 22;
//     int pos = HT.Search(key);

//     if (pos != -1)
//         cout << "\n" << key
//              << " found at index " << pos << ".\n";
//     else
//         cout << "\n" << key << " not found.\n";

//     // Search for a missing key
//     key = 21;
//     pos = HT.Search(key);

//     if (pos != -1)
//         cout << key << " found at index " << pos << ".\n";
//     else
//         cout << key << " not found.\n";

//     // Delete and display
//     HT.Remove(22);
//     HT.Display();

//     return 0;
// }