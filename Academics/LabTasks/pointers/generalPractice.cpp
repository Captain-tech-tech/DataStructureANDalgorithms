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





// (4)
// #include<iostream>
// using namespace std;
// int main()
// {
//     const int a = 56;
//     // a = 65;   // can't change const int value

//     int b = 45;

//     // here pointers are not const, it can store other address as well, here int is constant not pointer
//     int const *ptr1 = &a;  // these both are same
//     const int *ptr2 = &a;

//     // *ptr1 = 78;  invalied
//     // *ptr2 = 45;  invalied

//     // when * is used in between * and pointer_name, then the pointer is constant and new address can't be assigned, here both int and pointer are constant
//     int const *const ptr = &a;

//     // ptr = &b;  invalid

//     // here int is not constant and pointer is constant, so u can change int value through pointer but not the address inside pointer
//     int *const p = &b;


//     *p = 6785;
//     cout<<*p<<endl;

//     cout<<*ptr1<<endl;
//     cout<<*ptr2<<endl;

//     return 0;
// }






// (5)
// #include<iostream>
// using namespace std;
// int main()
// {
//     int a = 97563;
    
//     void *ptr;
//     ptr = &a;

//     cout<<ptr<<endl;
//     // cout<<*ptr<<endl;  // gives error, as pointer has no clue about how much space to read
//     cout<<(int *)ptr<<endl;
//     cout<<*(char *)ptr<<endl;  // it will access only one byte space, and print whatever value is present there
//     cout<<*(int *)ptr<<endl;

//     char b = 'Y';
//     ptr = &b;

//     cout<<ptr<<endl;
//     cout<<*(char *)ptr<<endl;
// }



// (6)

// int x = 5;
// int y = 2;

// double result = static_cast<double>(x) / y; // type casting in another way

