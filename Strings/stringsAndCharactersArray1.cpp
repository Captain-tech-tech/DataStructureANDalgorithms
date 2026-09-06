// character array = cstring

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char char_arr[] = {'a','b','v','f','\0'}; // by adding '\0' it becomes a valid string // array names are constant pointer
    int arr[] = {456,68,345,57,34};
    cout<<arr<<endl;   // here we get first index address
    cout<<char_arr<<endl;  // all characters converted into a single string
    cout<<strlen(char_arr)<<endl;    // when string len is calculated, then the '\0' null character is ignore

    char c[] = "Hello";   // such string assignment is called string literals
    cout<<strlen(c)<<endl;


    // cin.getline(name_of_char_string, size, delimiter?)  // here delimiter is optional
    // if we enter a character for delimiter, then further input will stop after such character like $ or .
    // everything after that delimiter will be ignored

    char c1[100];
    cin.getline(c1,100,'.');    // if cin is used then characters after space are ignored

    cout<<c1<<endl;

    // string is basically a class and we make objects of it and that's why it has a lot function/methods

    string str = "Why are you here";   // it is dynamic in nature, as it resize at run time
    cout<<str<<endl;
    str = "brothers and sisters";   // such change of values with string is not possible
    cout<<str<<endl;   

    string s1 = "how ", s2 = "are ", s3 = "you";
    string s4 = s1+s2+s3;   // concatenation
    cout<<s4<<endl;

    string s5 = "atif", s6 = "atif";
    cout<<(s5==s6)<<endl;  // 1 b/c both strings are equal
    cout<<(s1<s2)<<endl; // it compare first values of the strings
    cout<<s1.length()<<endl;

    
    // getline(cin, str_name, delimiter?)
    string s7;
    getline(cin>>ws,s7);

    cout<<s7<<endl;

    reverse(s7.begin(), s7.end());     // .begin() and .end() returns iterators
    cout<<s7<<endl;

    // to_string(int_value)   it converts the integer value into string and if you want then one by one 
    // it can be stored in char array

    // vector_char_array.resize(5);     if previous size was 12, now it will resize to 5 --> 5 and 12 can be any values
    
}







