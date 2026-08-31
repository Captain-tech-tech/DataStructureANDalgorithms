// Characteristics of Vectors

// Dynamic Size: Unlike standard arrays with fixed lengths, vectors adjust their storage automatically when 
// you add or remove elements.

// Contiguous Memory: Elements are stored in adjacent memory locations. You can use regular pointers or 
// indices to access them.

// Fast Element Access: Accessing any element by its index takes constant time, written as O(1).

// Efficient Insertion at the End: Adding an item to the end using push_back() takes O(1) average time.

// Automatic Memory Management: The container allocates extra capacity ahead of time to handle future 
// growth without reallocating every single time.





#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec;

    vector<int>vec1 = {45,67,34,57,34,57,39};
    vector<int>vec2(3,8);  // 3 is the size and 8 is stored at every index
    vector<int>vec3(vec2); // initializing vec3 values with vec2 values

    // push_back, pop_back, at, front, back, emplace      all of these run in O(1) time complexity
    // erase, insert        run in O(n) time complexity in worst case 
    // clear and erase function change the size of the vector but capacity of the vector remains the same
    
    vec.push_back(1);  // inserting an element at the end
    vec.push_back(2);
    vec.push_back(3);

    cout<<"SIZE : "<<vec.size()<<endl<<"CAPACITY : "<<vec.capacity()<<endl;

    for(auto i:vec)
    cout<<i<<" ";
    cout<<endl;

    vec.pop_back(); // for deleting the value at the end of vector

    cout<<"The value at index 0 : "<<vec[0]<<" or"<<vec.at(0)<<endl;
    cout<<"First element : "<<vec.front()<<", end element : "<<vec.back()<<endl;

    vec2.erase(vec2.begin());  // .begin() gives the first index values
    vec2.erase(vec2.begin() + 2); // for deleting value at index 2
    // vec3.erase(vec3.begin() + 1,vec3.begin()+4); //  it is use to remove a range of numbers, 
    // start index value is included and end is not included 


    vec.insert(vec.begin()+1,100);  // 1 is index and 100 is value we wanna store at that index // 
    // for inserting a value at specific index

    vec.clear();  // it is used to remove all the elements from the array, size become 0 and capacity
    //  remains the same

    cout<<vec.capacity()<<endl<<vec.size()<<endl;
    cout<<vec.empty()<<endl; // to check our vector is empty or not



    

    // vectors iterators 
    cout<<*(vec3.begin())<<endl<<*(vec3.end()-1)<<endl;  // vec3.end() gives index which is 1 greater than 
    // where the last value is present
    
    // creating iterator
    vector<int>::iterator it;
    for(it = vec3.begin(); it != vec3.end(); it++)
        cout<<*(it)<<"  ";
    cout<<endl;

    // creating reverse iterator
    vector<int>::reverse_iterator itr;   // auto keyword can also be instead of this line and auto is directly written in for loop
    for(itr = vec3.rbegin(); itr != vec3.rend(); itr++)  // rend gives -1 index not 0   and  rbegin gives index of last value
        cout<<*(itr)<<"  ";
    cout<<endl;
    
    return 0;
}
















