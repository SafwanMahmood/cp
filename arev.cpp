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

int pal(string a,int i,int j )
{
	// int i =0;
	// int j = a.length()-1;
	while(i<j)
	{
		if (a[i] != a[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	return 1;	
}
int n;
// vector<string> all(string a,int st,int end)
// {
// 	std::vector<string> v;
// 	for (int i = st; i < a.length(); ++i)
// 	{
// 		if(pal(a,st,i+1))
// 		{
//                 v.push_back(a.substr(st,st-i+1));
//                 all(a,i+1,n); 
// 		}	
// 	}
// }
int len;
int countTriplets(int arr[], int n, int sum)
{
    // Sort input array
    sort(arr, arr+n);
 
    // Initialize result
    int ans = 0;
 
    // Every iteration of loop counts triplet with
    // first element as arr[i].
    for (int i = 0; i < n - 2; i++)
    {
        // Initialize other two elements as corner elements
        // of subarray arr[j+1..k]
        int j = i + 1, k = n - 1;
 
        // Use Meet in the Middle concept
        while (j < k)
        {
            // If sum of current triplet is more or equal,
            // move right corner to look for smaller values
            if (arr[i] + arr[j] + arr[k] > sum)
                k--;
 
            // Else move left corner
            else
            {
                // This is important. For current i and j, there
                // can be total k-j third elements.
                // ans += (k - j);
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                	ans++;
                	cout<<arr[i]<< arr[j]<< arr[k]<<endl;
                }
                j++;
            }
        }
    }
    return ans;
}
int checker(int a[],int sum)
{
	bool la[1000] = {0};
	int t = 0;
	int count=0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i+1; j < len; ++j)
		{
		 t = sum - a[i] - a[j] ;
		if (t >= 0 && la[t] == 1)
		{
			cout << a[i] << t << a[j]<< endl;
			count++;
		}
		la[a[i]] = 1;
	  }
	}
	return count;
}
int zig(int a[])
{
	bool flag =true;
	for (int i = 0; i < len-1; ++i)
	{
		if (flag)
		{
			if (a[i] > a[i+1])
			{
				swap(a[i],a[i+1]);
			}
			else{
				if (a[i]<a[i+1])
				{
					swap(a[i],a[i+1]);
				}
			}
			flag != flag;
		}
	}
}
int smaller(int a[])
{
	int res =1;
        for (int i = 0; i < len; ++i)
        {
        	if (a[i]<= res)
        	{
        		res = res +a[i];
        	}
        }
        return res;
}
int sortedpro(int a[])
{
	sort(a,a+len);
	std::vector<int> x,y;

	for (int i = 0; i < len; ++i)
	{
		if (i < len/2)
		{
			 x.push_back(a[i]);
		}
		else
		{
			 y.push_back(a[i]);
		}
	}
	sort(y.begin(),y.end(),greater<int>());
	int i=0,sum=0;
	for (int j = 0; j < x.size(); j++)
	{
		a[i] = y[j];
		i++;
		a[i] = x[j];
		i++;
		sum += x[j]*y[j];
	}
	return sum;
}
int main() 
{
	string a;
	cin>>a;
	string b = a;
	n = a.length();
	int i =0,j=n-1;
	int temp;	
	while(i<j)
	{ 
		if(!isalpha(a[i]))
		{
			i++;
		}
		else if(!isalpha(a[j]))
		{
			j--;
		}
		else
		{	
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	for (int i = 0; i < n; ++i)
		{
			cout<<a[i];
		}
	cout<<pal(a,0,n-1)<<endl;
    cin>>len;
    int c[len];
    for (int i = 0; i < len; ++i)
      {
      	cin>>c[i];
      }
    // sort(c,c+len);
    // for (int i = 0; i < len; ++i)
    //     {
    //     	cout<<c[i]<<" ";
    //     }    
	// cout<<checker(c,12);
	// cout<<countTriplets(c,len,12);
	// cout<<zig(c)<<endl;
	// for (int i = 0; i < len; ++i)
	// {
	// 	cout<<c[i]<<" ";
	// }
	// cout<<smaller(c)<<endl;
    cout<<sortedpro(c)<<endl;
	for (int i = 0; i < len; ++i)
	{
		cout<<c[i]<<" ";
	}
	
	// std::vector<string> v = all(a,0,n);		
    return 0;
}