// vectors are like arrays, vectors are different from array in a way that vectors have dynamic size, 
// not fixed size



// STL = standard template library  ---> this library contains STL containers(vector,queue,stack,set)
// they are called containers because they store some type of data 



// vector syntax

// (1) way of initialization
// vector<data_type_name>name_of_vec_variable

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>a;  // 0
//     vector<int>nums={34,54,23};

//     // cout<<a[0];//it will give segmentation fault error,  it occurs when accessing something that is not in range
//     cout<<nums[2]<<endl;

//     return 0;
// }


// (2) way of initialization
// vector<int>vec(3,0)  // where 3 is the size of the vector and 0 is stored at every index

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>vec(4,0);
//     vector<float>num(5,3);  // here the size is 5 and a every index 3 is stored
//     cout<<vec[3]<<endl<<num[4]<<endl;

//     // for each loop is used in vectors
//     for(int i:vec)   // here i does store the index number but store the value at the index
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;

//     vector<char>name={'A','t','i','f'};
//     for(char value:name)
//     cout<<value<<" ";
//     cout<<endl;
//     return 0;
// }




// VECTORS FUNCTIONS

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>vec={45,56,34,46,23,64};

//     // finding size
//     cout<<"Initial size of the vector : "<<vec.size()<<endl;

//     // push_back function
//     vec.push_back(34);// the size is increased and 34 is stored at end index
//     vec.push_back(56);//the order is maintained while adding values through push back method
//     cout<<"Size after push_back : "<<vec.size()<<endl; 

//     // pop_back function
//     vec.pop_back(); // it removes the end value from the vector and reduce the size of vector by 1
//     cout<<"Size after pop_back : "<<vec.size()<<endl;

//     // front() method
//     cout<<"First value : "<<vec.front()<<endl;  // is used for printing the starting value of the vector

//     // back() method
//     cout<<"Last value : "<<vec.back()<<endl; // for printing end value

//     // at() method
//     cout<<vec.at(3)<<endl; // for accessing a value at specific index

//     return 0;
// }



// VECTOR STATIC AND DYNAMIC ALLOCATION

// (1) static allocation occurs during compile time and dynamic allocation occurs during run 
// time
// (2) static memory is reversed in stack memory and dynamically memory is reserved from heap 


// Finding the size and capacity of the vector after push_back
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec;

    // size means the number of elements in the vector and capacity means how many elements the vector can store
    vec.push_back(0);  // it doubles capacity to 1 and the size is increased 1 which was initially 0
    vec.push_back(1);  // it doubles the capacity to 2 and the size increase to 2
    vec.push_back(2);  // it doubles the capacity of vector to 4 and size increase to 3

    // (1) after every push_back if capacity is not enough to store the new element 
    // new memory is reversed of double size the previous memory
    // (new vector is made) and the previous elements of vector
    // are stored there and then the new element is stored there and then the old memory is deleted
    // (2) if capacity is high then element is stored there without allocating new memory

    cout<<"The size of the vector : "<<vec.size()<<endl;
    cout<<"The capacity of the vector : "<<vec.capacity()<<endl;

    cout<<endl;
    vec.push_back(3);
    cout<<"The size of the vector : "<<vec.size()<<endl;
    cout<<"The capacity of the vector : "<<vec.capacity()<<endl;

    cout<<endl;
    vec.push_back(4);
    cout<<"The size of the vector : "<<vec.size()<<endl;
    cout<<"The capacity of the vector : "<<vec.capacity()<<endl;

    return 0;
}




































