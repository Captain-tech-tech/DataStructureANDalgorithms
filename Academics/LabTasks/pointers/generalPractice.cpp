// (1)
// #include<iostream>
// using namespace std;
// int main()
// {
//     int *ptr = new(nothrow) int;

//     if(!ptr)
//     {
//         cout<<"Memory allocation failed!"<<endl;
//     }

//     return 0;
// }
// we can't dereference a pointer whose value is Null



// (2)
// memory leak  : avoid this memory leak by first freeing the memory and then assigning the new address to the pointer

// int *p = new int;
// p = new int;

// or

// while(1)
// int *p = new int;

// or 

// int f()    // here memory is reserved and address is not returned in the main, so now this memory is un accessible
// {
//     int *p;
//     p = new int;
//     return 0;
// }




// (3)
// if one address comes before another address in memory, the first address is considered less than the second address















