
/*
***************************************************************************************************************
 
                          Author : SAFWAN 
 
**************************************************************************************************************
*/
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <utility>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <bitset>
#include <iomanip>
#include <limits.h>
#include <pthread.h>
#include <utility>

#define MAX 1e18
#define PI 3.14159265
#define FORV(i, x)                                                             \
  for (std::vector<int>::iterator i = (x.begin()); i != (x.end()); ++i)
#define FORS(i, x)                                                             \
  for (std::set<int>::iterator i = (x.begin()); i != (x.end()); ++i)
#define FOR(i,start,end) for(size_t i=start;i<end;i++)
#define rFOR(i,end,start) for(size_t i=end,i>=start;i--)
#define ll long long int
#define ld long double
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mp make_pair
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ii pair<int,int>
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}

int convert(string k)
{
    int a;
    istringstream ss(k);
    ss >> a;
    return a;
}

int powerwithmodulus(int base, int exponent,int modulus){
    int result = 1; base%=modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1) result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void printArray(int arr[] , int n){ FOR(i,0,n) cout << arr[i] << " " ; cout << endl;}

// bool isPrime(long long number){
//     if (number != 2){
//         if (number < 2 || number % 2 == 0) {
//             return false;
//         }
//         for(int i=3; (i*i)<=number; i+=2){
//             if(number % i == 0 ){
//                 return false;
//             }
//         }
//     }
//     return true;
// }


int power(int a, unsigned int n, int p)
{
    int res = 1;      // Initialize result
    a = a % p;  // Update 'a' if 'a' >= p
 
    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res*a) % p;
 
        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
    return res;
}
 
// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned int n, int k)
{
   // Corner cases
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;
 
   // Try k times
   while (k>0)
   {
       // Pick a random number in [2..n-2]        
       // Above corner cases make sure that n > 4
       int a = 2 + rand()%(n-4);  
 
       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;
 
       k--;
    }
 
    return true;
}
bool sieve[1000000000];
int SieveOfAtkin(int l,int limit)
{
    int count=0;
    // 2 and 3 are known to be prime
    if (limit > 2)  cout << 2 << " ";
    if (limit > 3)  cout << 3 << " ";
 
    // Initialise the sieve array with false values
    
    for (int i=0; i<limit; i++)
        sieve[i] = false;
 
    /* Mark siev[n] is true if one of the following is true:
     a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
        odd number of distinct pairs (x, y) that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
     b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
     c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            // Main part of Sieve of Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
 
            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;
 
            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
 
    // Mark all multiples of squares as non-prime
    for (int r = 5; r*r < limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                sieve[i] = false;
         }
    }
 
    // Print primes using sieve[]

      for (int i = l; i <= limit; i++)
      {
        if(sieve[i] == true)
        {
             bool pp = false;
            string a;
            a = IntToString(i);
            for (int k = 0; k < a.length(); ++k)
            {
                if (!sieve[a[k]])
                {
                    pp = true;
                    break;
                }
            }
            
            // cout<<i<<endl;
            if (!pp)
            {
                count++;
            }
        }
        /* code */
    }
    return count; 
}
int SieveOfEratosthenes(int l,int n)
{
    bool prime[n+1];
    int count=0;
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int i = l; i <= n; i++)
    {
        if(prime[i] == true)
        {
             bool pp = false;
             int k = i;
            while(k>0)
            {
                
            }    
            
            // cout<<i<<endl;
            if (!pp)
            {
                count++;
            }
        }
        /* code */
    }
    return count;
}
int main() {
    int f,l;
    cin>>f>>l;
    int count=SieveOfEratosthenes(f,l);
    
    cout<<count<<endl;
    return 0;
}
