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



// most optimal approach  is  'Sieve of Eratosthenes'
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


