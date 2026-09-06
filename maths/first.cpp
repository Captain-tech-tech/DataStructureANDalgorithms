// 1

// i*i = n     =>  i = (n)^1/2

// #include<iostream>
// using namespace std;

// string isPrime(int n)
// {
//     for(int i = 2; i*i < n;i++)
//     {
//         if(n%i == 0)
//         return "Non Prime";
//     }
//     return "Prime";
// }

// int main()
// {
//     int n = 42;
//     cout<<isPrime(n)<<endl;
//     return 0;
// }



// ***********************  most optimal approach  is  'Sieve of Eratosthenes' *******************
// leetcode question number 204 count primes is based on this approach

// 'Sieve of Eratosthenes' algorithm : 
// You start by assuming every number is prime, pick the first prime (like 2), and 
// cross out all of its multiples (4, 6, 8...) since they can't be prime. You simply 
// repeat this for the next uncrossed numbers, and whatever is left standing at the 
// end is your list of prime


// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n = 50;
//     vector<bool> isPrime(n+1,true);
//     isPrime[0] = false, isPrime[1] = false;   // 0 and 1 are not prime numbers

//     int count = 0;
//     for(int i=2;i*i<n;i++)
//     {
//         if(isPrime[i])
//         {   
//             count++;
//             for(int j = i*2;j<n;j+=i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     cout<<count<<endl;
//     for(int i=0;i<n;i++)
//     {
//         if(isPrime[i]==true)
//         cout<<i<<"  ";
//     }
//     cout<<endl;
//     return 0;
// }




// 2

// finding number of digits in a number has time complexity O(log(n))--> here log base is 10
// if division is performed by 2 or 3 etc then time complexity is O(log(n)) -- here log base is 2 or 3

// #include<iostream>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int n = 895723;
//     cout<<(int)(log10(n) + 1)<<endl;   // it gives number of digits,   usually we find it through while
//     return 0;
// }





// 3  amstrong number 
// #include <iostream>
// #include <cmath>

// using namespace std;

// bool isArmstrong(int num) {
//     int originalNum = num;
//     int temp = num;
//     int digits = 0;
//     int sum = 0;

//     while (temp > 0) {
//         temp /= 10;
//         digits++;
//     }

//     temp = num; 
//     while (temp > 0) {
//         int remainder = temp % 10;
//         sum += round(pow(remainder, digits)); 
//         // pow(5, 3) outputs 124.999999998,   round(124.999999998) converts it to exactly 125
//         temp /= 10;
//     }
//     return (sum == originalNum);
// }

// int main() {
//     int num;
//     cout << "Enter an integer: ";
//     cin >> num;

//     if (isArmstrong(num)) {
//         cout <<num<< " is an Armstrong number." << endl;
//     } else {
//         cout <<num<< " is NOT an Armstrong number." << endl;
//     }
//     return 0;
// }





// 4 GCD/HCF


// #include<iostream>
// using namespace std;
// int main()
// {
//     int a = 20, b = 28;
//     int gcd;
//     for(int i = 1;i<min(a,b);i++)
//     {
//         if(a%i == 0 && b%i == 0)
//         {
//             gcd = i;
//         }
//     }
//     cout<<"Your GCD of "<<a<<" and "<<b<<" : "<<gcd<<endl;
//     return 0;
// }




// ******************* Euclid algorithm *******************
// gcd and lcm

// a*b = gcd(a,b) * lcm(a,b)

// #include<iostream>
// using namespace std;

// int gcd(int a,int b)
// {
//     while(a > 0 && b > 0)
//     {
//         if(a>b)
//             a = a%b;
//         else
//             b = b % a;
//     }
//     if(a == 0) return b;
//         return a;
// }

// int lcm(int a,int b)
// {
//     int gcdd = gcd(a,b);
//     return (a*b)/gcdd;
// }

// int main()
// {
//     cout<<gcd(20,28)<<endl;
//     cout<<gcd(0,24)<<endl;
//     cout<<lcm(20,28)<<endl;
//     cout<<lcm(0,24)<<endl;
//     return 0;
// }

// do GCD through recurssion in free time





// 5
// modulo arithmetics

// (x+y)%m = (x%m) + (y%m)

// (x-y)%m = (x%m) - (y%m)

// (x*y)%m = (x%m) * (y%m)

// ((((x%y)%y)%y)%y) and so one is same as (x%y)





