// In C++, map is an associative container that stores elements as key-value pairs. Each key must be 
// unique, and it acts as the index used to locate, retrieve, or alter its associated value.

// Ordered Elements: Keys are automatically sorted in ascending order by default.

// Self-Balancing Binary Search Tree: Under the hood, std::map is typically implemented using a Red-Black Tree.

// Logarithmic Efficiency: Due to its tree structure, searching, inserting, and deleting elements all 
// take O(log n) time complexity.

// Bi-directional Iterators: You can traverse the map from beginning to end or vice-versa, but it does 
// not support random access indexing like a vector.

// Pair Storage: Internally, elements are stored as std::pair<const Key, Value>. Notice that the key is 
// const—you cannot alter a key after it is inserted; you can only delete and re-insert it.

// internal structure of map and multimap is Red-Black Tree, and unordered_map has internal structure of Hash Table 


// insertion working
// If the key does not exist, the map instantly creates a new node with that key, initializes the value to 
// its default state (e.g., 0 for numbers, empty string for strings), and then performs the assignment.

// value changing
// If the key already exists, it simply overwrites the old value with the new value.

// Insertion Works: If the key does not exist, it inserts the new pair successfully.
// Changing Works: If the key already exists, insert() does nothing and fails silently (it will not overwrite
// the old data). It returns a std::pair where the second element is a boolean indicating if insertion succeeded.


// The find() function searches for a specific key and returns an iterator pointing to that element if it exists.
// It returns an iterator directly referencing the key-value pair, It returns the map's boundary iterator, map.end()
// It runs in \(O(\log n)\) time


// The count() function searches for a specific key and returns the number of times the key appears in the map.
// Because keys are unique in a standard map, this function will only ever return 1 (if the key exists) or
// 0 (if the key does not exist).  
// Efficiency: It runs in O(log n) time.



// Use of each underlying data structure 
// 1. Choose unordered_map by default when you just need fast lookups, insertions, and deletions, and you do not care about the order of your items.
// 2. Choose map when you explicitly need your data to remain sorted, or when you need to perform 
//    range-based queries (e.g., "find all keys greater than 50" using upper_bound).
// 3. Choose multimap when your problem explicitly requires grouping multiple distinct values under an 
//    identical key while maintaining a sorted key structure (e.g., grouping students by their test scores)


// Time complexity 
// Operation           std::map          std::unordered_map                std::multimap
// Search/Find         O(log n)          O(1)Average/O(n) Worst Case       O(log n)
// Insertion           O(log n)          O(1) Average/(O(n)Worst Case     O(log n)    
// Deletion/Erase      O(log n)          O(1)Average/O(n)Worst Case        O(log n)

// unordered_map Worst Case: If multiple distinct keys generate the exact same hash value (a hash collision),
// they are chained together in the same bucket. In an extreme scenario where all keys collide, performance degrades from \(O(1)\) down to a linear \(O(n)\) search.



// #include<iostream>
// #include<map>
// using namespace std;
// int main()
// {
//     map<string,int>m;

//     m["Tablet"] = 347;
//     m["laptop"] = 5635;
//     m["headphones"] = 46834;
//     m["tv"] = 3574;

//     m.erase("tv");

//     for(auto p:m)  // values print in sorted order of keys
//     {
//         cout<<p.first<<"  "<<p.second<<endl;
//     }

//     m.insert({"Car",456858});
//     m.emplace("mobile",68434);

//     cout<<endl<<"Count : "<<m.count("laptop")<<endl;

    
//     if(m.find("camera") != m.end())
//     cout<<"Found\n";
//     else
//     cout<<"Not found\n";


//     return 0;
// }















// Multi map
// A multimap is an ordered associative container that allows multiple elements to share the exact same key.

// Because a single key can map to multiple values, the expression myMap["Apple"] would be ambiguous. 
// Therefore, multimap does not support [] or .at(). You must use .insert().

// Contiguous Duplicates: Duplicate keys are guaranteed to be stored next to one another. You can retrieve 
// all values belonging to a single duplicate key using equal_range(), lower_bound(), or upper_bound().

// Sorted by keys (ascending)



// #include<iostream>
// #include<map>
// using namespace std;
// int main()
// {
//     multimap<string,int>m;

//     m.emplace("tv",3573);
//     m.emplace("Car",45684);
//     m.emplace("Laptop",3457);
//     m.emplace("phone",5468);
//     m.emplace("phone",35683);
//     m.emplace("phone",35683);

//     // m.erase("phone");  // it removes all values of phone
//     m.erase(m.find("phone"));   // to remove one value,  .find return iterator, the actual memory location

//     return 0;
// }









// unordered map

// An unordered_map is an unordered associative container that maps unique keys to values, optimized strictly for raw speed.

// No Order: Elements are not sorted. The traversal order depends entirely on the internal hashing 
// structure and can change when new elements are added.

// Hash Table Implementation: Under the hood, it uses an array of buckets combined with a Hash Function. 
// The key is hashed to an index, providing direct access to its corresponding value bucket

// It generally consumes more memory than an ordered map because it needs to maintain a bucket array and 
// handle collision lists.




// #include<iostream>
// #include<unordered_map>
// using namespace std;
// int main()
// {
//     unordered_map<string, int> m;

//     m.emplace("tv",3573);
//     m.emplace("Car",45684);
//     m.emplace("Laptop",3457);
//     m.emplace("phone",5468);
//     m.emplace("phone",35683);

//     for(auto p:m)
//     {
//         cout<<p.first<<"       "<<p.second<<endl;
//     }
// } 


