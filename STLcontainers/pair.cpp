// A sequence container is a C++ Standard Template Library (STL) data structure that stores elements of 
// the same data type in a sequential, linear layout.

// vectors, lists and deques are sequence containers
// They are called sequence containers because they arrange elements in a strict, 
// linear order. Position depends solely on when and where you insert the item, not on its value.


// Pair : It is a utility class template defined in the <utility> header/library.
// It holds exactly two values. These two values can have different data types or same data types.
// The two values are directly accessed using the hardcoded, public member variables .first and .second.
// Unlike a list or a vector, a pair is not a dynamic sequence; it is a fixed, two-element structure.


// Lexicographical comparison: Pairs natively support comparison operators (==, !=, <, >, <=, >=).
// Two-step sorting logic: When comparing two pairs, the compiler first evaluates the .first elements. 
// If they are equal, it falls back to comparing the .second elements. This makes pairs highly useful 
// as keys in sorted associative containers. 

// Every element inside a std::map is stored internally as a std::pair<const Key, Value>

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    pair<int, int>p = {56,45};

    cout<<p.first<<"   "<<p.second<<endl;

    pair<string, int> p1 = {"Muhammad Atif",2574};

    cout<<p1.first<<"   "
    <<p1.second<<endl;

    pair<int, pair<int,char>> p2 = {346,{684,'A'}};    // nested pairs
    cout<<p2.first<<"   "<<p2.second.first<<"   "<<p2.second.second<<endl;

    vector<pair<int,int>>vec = {{364,346},{78,34}};     // vector of pairs

    vector<pair<int, pair<char,string>>> vec1 = {{13451,{'A',"Hello brothers"}},{8724,{'A',"Hello sisters"}}};

    for(auto i:vec1)
    {
    cout<<i.first<<"       ";
    cout<<i.second.first<<"      ";
    cout<<i.second.second<<"      "<<endl;
    }

    vec1.push_back({536,{'B',"Why are you!"}});
    
    vec1.emplace_back(47686,'C',"It's okay to be scared, but we have to do it anyway");  
    //emplace_back automatically makes the pair without using {}
    //emplace_back creates in-place objects at the time of insertion
    //while push_back assumes that pair is present and it performs only insertion or add it to the end of vector
    //the efficiency of emplace_back is faster than push_back
}










// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// int main() {
//     // a map that automatically sorts its keys (the pairs)
//     map<pair<int, int>, string> gameGrid;

//     // Inserting data in random order
//     gameGrid[{2, 3}] = "Alice";
//     gameGrid[{1, 5}] = "Bob";
//     gameGrid[{2, 1}] = "Charlie";

//     // when you loop through a map, it prints in perfectly sorted order
//     for (const auto& [coords, name] : gameGrid) 
//     {
//         cout<<"("<<coords.first<<", "<<coords.second<<")->"<<name<<"\n";
//     }
// }

