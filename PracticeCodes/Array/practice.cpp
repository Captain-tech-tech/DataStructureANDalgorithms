// data type modifiers  :  long, short, long long, signed, unsigned 
// data types are signed by default, if unsigned keyword is not used
// unsigned int s = -34;    it gives flase value 
// sizeof()  function 

// #include<iostream>
// using namespace std;
// int main()
// {
//     unsigned short int a = 45;
//     double b = 347.49;
//     long int c = 3456345;

//     cout<<sizeof(a)<<endl;
//     cout<<sizeof(b)<<endl;
//     cout<<sizeof(c)<<endl;

// }





// write a function for converting decimal to binary and a function for converting binary to decimal
// #include<iostream>
// using namespace std;

// long int decimal_to_binary(int decimal)
// {
//     long int ans = 0;
//     int temp = decimal;
//     int place = 1;

//     while (temp != 0)   
//     {
//         ans = ans + (temp%2)*place;
//         place *= 10;
//         temp /= 2;
//     }    
//     return ans;
// }

// int binary_to_decimal(long int binary)
// {
//     int ans = 0;
//     int base = 1;
//     while(binary > 0)
//     {
//         int last_digit = binary % 10;
//         binary /= 10;

//         ans += last_digit*base;
//         base *=2;
//     }
//     return ans;
// }

// int main()
// {
//     int decimal;cout<<"Enter a decimal number : ";cin>>decimal;

//     long int bin = decimal_to_binary(decimal);

//     long int binary;cout<<"Enter a binary number : ";cin>>binary;

//     int deci = binary_to_decimal(binary);

//     cout<<endl<<endl<<"Decimal : "<<decimal<<", binary : "<<bin<<endl;
//     cout<<"Binary : "<<binary<<", Decimal : "<<deci<<endl;

//     return 0;
// }








// bitwise ^   XOR  or exclusive_or operator  apply ^ on different numbers 
// bitwise >> ,   a << b is equal to answer = a*2^b in memory  like if a = 8 and b = 1
// bitwise << ,   a >> b is equal to answer = a/2^b in memory 

// local and global variables

// block of code 
// {
//     int x = 34;
// }
// x can't be accessed out of this block of code 







// #include<iostream>
// using namespace std;

// // function to check whether a number is power of 2 or not without any loop 
// void check_power(int num)
// {
//     if((num ^ 1)  > num)
//     {
//         cout<<"This number is in power of 2"<<endl;
//     }
//     else
//     cout<<"This number is not in power of 2"<<endl;
// }

// // function to check whether a number is power of 2 or not
// void check_power(int num)
// {
//     int flag = 0;
//     int p = 1;
//     while(num != 2)
//     {
//         p++;
//         if((num%2) != 0)
//         {
//             flag = 1;
//             break;
//         }
//         num /= 2;
//     }

//     if(flag == 0)
//     cout<<"This number is power of 2, and the power is "<<p<<endl;
//     else if(flag ==1)
//     cout<<"This number is not power of 2"<<endl;
// }

// int main()
// {
//     int num;cout<<"Enter a number : ";cin>>num;

//     check_power(num);
// }





// write a program to reverse an integer 
// #include<iostream>
// using namespace std;
// int main()
// {
//     long int num;cout<<"Enter a number : ";cin>>num;

//     long int temp = num;
    
//     long int reverse = 0;
//     while(temp != 0)
//     {
//         int reminder = temp % 10;
//         reverse = reminder + reverse*10;
//         temp /= 10;
//     }

//     cout<<"The reverse of "<<num<<" is "<<reverse<<endl;
// }

