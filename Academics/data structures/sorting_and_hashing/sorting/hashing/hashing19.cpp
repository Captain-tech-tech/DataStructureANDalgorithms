


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








// linear probing
// #include <iostream>

// // Define the maximum size of the hash table
// const int SIZE = 10;

// /**
//  * Purpose: Hash Function
//  * Computes the initial index for a given key using the modulus operator.
//  * This is a simple division hash method.
//  */
// int hashFunction(int key) {
//     return key % SIZE;
// }

// /**
//  * Purpose: Linear Probing (Collision Resolution)
//  * If a collision occurs (the index is already filled), this function scans 
//  * the hash table sequentially (index + 1, index + 2, ...) to find the next available empty spot (0).
//  */
// int probe(int H[], int key) {
//     int index = hashFunction(key);
//     int i = 0;
    
//     // Linearly scan the table until an empty space (value 0) is found
//     while (H[(index + i) % SIZE] != 0) {
//         i++;
//     }
    
//     return (index + i) % SIZE;
// }

// /**
//  * Purpose: Insert Key
//  * Inserts a unique key into the hash table. If the direct index is occupied,
//  * it invokes the probe function to find the correct open address.
//  */
// void Insert(int H[], int key) {
//     int index = hashFunction(key);
    
//     // Check if a collision occurred (slot is not empty)
//     if (H[index] != 0) {
//         index = probe(H, key);
//     }
    
//     // Place the key into the open index
//     H[index] = key;
// }

// /**
//  * Purpose: Search Key
//  * Searches for a key in the hash table by computing its initial index 
//  * and using linear probing to trace it if it was shifted due to a collision.
//  */
// int Search(int H[], int key) {
//     int index = hashFunction(key);
//     int i = 0;
    
//     // Linearly scan until the key is found 
//     // Note: In production code, you should also handle bounds to prevent an infinite loop if the key doesn't exist
//     while (H[(index + i) % SIZE] != key) {
//         i++;
//     }
    
//     return (index + i) % SIZE;
// }

// int main() {
//     // Initialize Hash Table (HT) with all zeros representing empty spaces
//     int HT[SIZE] = {0};

//     // Inserting values from the images
//     Insert(HT, 12); // Hashes to index 2
//     Insert(HT, 25); // Hashes to index 5
//     Insert(HT, 35); // Hashes to index 5 -> Collides, probes to index 6
//     Insert(HT, 26); // Hashes to index 6 -> Collides, probes to index 7

//     // Displaying the contents of the Hash Table
//     std::cout << "Hash Table contents:" << std::endl;
//     for (int i = 0; i < SIZE; i++) {
//         std::cout << "Index " << i << " -> " << HT[i] << std::endl;
//     }

//     // Testing the Search function
//     int searchKey = 35;
//     std::cout << "\nSearching for key " << searchKey << "..." << std::endl;
//     std::cout << "Found at index: " << Search(HT, searchKey) << std::endl;

//     return 0;
// }











// quadratic probing
// #include <iostream>

// // Define the maximum size of the hash table
// const int SIZE = 10;

// /**
//  * Purpose: Hash Function
//  * Computes the initial index for a given key using the modulus operator.
//  */
// int hashFunction(int key) {
//     return key % SIZE;
// }

// /**
//  * Purpose: Quadratic Probing (Collision Resolution)
//  * Scans the hash table using a quadratic offset (i * i) to find the next 
//  * available empty slot (0). Slots checked: index, index+1, index+4, index+9...
//  */
// int probe(int H[], int key) {
//     int index = hashFunction(key);
//     int i = 0;
    
//     // Quadratically scan the table until an empty space (value 0) is found
//     while (H[(index + i * i) % SIZE] != 0) {
//         i++;
//     }
    
//     return (index + i * i) % SIZE;
// }

// /**
//  * Purpose: Insert Key
//  * Inserts a unique key into the hash table. If the direct index is occupied,
//  * it invokes the quadratic probe function to find the open address.
//  */
// void Insert(int H[], int key) {
//     int index = hashFunction(key);
    
//     // Check if a collision occurred (slot is not empty)
//     if (H[index] != 0) {
//         index = probe(H, key);
//     }
    
//     // Place the key into the calculated open index
//     H[index] = key;
// }

// /**
//  * Purpose: Search Key
//  * Searches for a key in the hash table by computing its initial index 
//  * and using quadratic probing (index + i * i) to track its location.
//  */
// int Search(int H[], int key) {
//     int index = hashFunction(key);
//     int i = 0;
    
//     // Quadratically scan until the key is found
//     while (H[(index + i * i) % SIZE] != key) {
//         i++;
//     }
    
//     return (index + i * i) % SIZE;
// }

// int main() {
//     // Initialize Hash Table (HT) with all zeros representing empty spaces
//     int HT[SIZE] = {0};

//     // Inserting values to observe quadratic probing behavior
//     Insert(HT, 12); // Hashes to index 2
//     Insert(HT, 25); // Hashes to index 5
//     Insert(HT, 35); // Hashes to index 5 -> Collides. Checks (5 + 1^2)%10 = 6. Index 6 is free.
//     Insert(HT, 26); // Hashes to index 6 -> Collides. Checks (6 + 1^2)%10 = 7. Index 7 is free.

//     // Displaying the contents of the Hash Table
//     std::cout << "Quadratic Probing Hash Table contents:" << std::endl;
//     for (int i = 0; i < SIZE; i++) {
//         std::cout << "Index " << i << " -> " << HT[i] << std::endl;
//     }

//     // Testing the Search function
//     int searchKey = 35;
//     std::cout << "\nSearching for key " << searchKey << "..." << std::endl;
//     std::cout << "Found at index: " << Search(HT, searchKey) << std::endl;

//     return 0;
// }








// double hashing
#include <iostream>

// M is the size of the hash table
const int M = 11; 

// R is a prime number smaller than M (used for the second hash function)
const int R = 7;  

/**
 * Purpose: First Hash Function (h1)
 * Computes the base/initial index for a given key.
 */
int h1(int key) {
    return key % M;
}

/**
 * Purpose: Second Hash Function (h2)
 * Computes the step size for probing when a collision happens.
 * It must never return 0, otherwise the probe would get stuck in an infinite loop.
 */
int h2(int key) {
    // Formula 1: h2(k) = 1 + (k % R)
    return 1 + (key % R);

    // Formula 2: h2(k) = R - (key % R)
    // To use Formula 2, uncomment the line below and comment out the line above:
    // return R - (key % R);
}

/**
 * Purpose: Double Hashing Probing 
 * Calculates the next available index step-by-step using the step size from h2(key).
 */
int probe(int H[], int key) {
    int index = h1(key);
    int stepSize = h2(key);
    int i = 0;
    
    // Move forward by multiplying 'i' with the step size until an empty spot (0) is found
    while (H[(index + i * stepSize) % M] != 0) {
        i++;
    }
    
    return (index + i * stepSize) % M;
}

/**
 * Purpose: Insert Key
 * Inserts a key into its primary index. If occupied, it resolves the 
 * collision by calculating a dynamic offset via double hashing.
 */
void Insert(int H[], int key) {
    int index = h1(key);
    
    // Check if a collision occurred (slot is not empty)
    if (H[index] != 0) {
        index = probe(H, key);
    }
    
    // Place the key into the open index
    H[index] = key;
}

/**
 * Purpose: Search Key
 * Finds the index of a key by calculating its base hash and tracking its location
 * step-by-step using the same step size multiplier from h2.
 */
int Search(int H[], int key) {
    int index = h1(key);
    int stepSize = h2(key);
    int i = 0;
    
    // Step forward dynamically until the key is matched
    while (H[(index + i * stepSize) % M] != key) {
        i++;
    }
    
    return (index + i * stepSize) % M;
}

int main() {
    // Initialize Hash Table (H) with all zeros representing empty spaces
    int HT[M] = {0};

    // Inserting values to demonstrate double hashing
    Insert(HT, 5);   // h1(5) = 5%11 = 5
    Insert(HT, 16);  // h1(16) = 16%11 = 5 -> Collision! 
                     // h2(16) = 1 + (16%7) = 1 + 2 = 3 step size.
                     // Next check: (5 + 1*3) % 11 = 8. Index 8 is free.
                     
    Insert(HT, 27);  // h1(27) = 27%11 = 5 -> Collision!
                     // h2(27) = 1 + (27%7) = 1 + 6 = 7 step size.
                     // Next check: (5 + 1*7) % 11 = 12 % 11 = 1. Index 1 is free.

    // Displaying the contents of the Hash Table
    std::cout << "Double Hashing Table contents (M=11, R=7):" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cout << "Index " << i << " -> " << HT[i] << std::endl;
    }

    // Testing the Search function
    int searchKey = 16;
    std::cout << "\nSearching for key " << searchKey << "..." << std::endl;
    std::cout << "Found at index: " << Search(HT, searchKey) << std::endl;

    return 0;
}


