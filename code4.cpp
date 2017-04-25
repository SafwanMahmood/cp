#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <sstream>
#include <stdlib.h>
using namespace std;
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int arr[10000];
int c = 0;
int r =-1;
int rec(int arr[],int c,int n)
{
for (int i = 0; i < 3; ++i)
    {
    	if(n>=arr[i])
    	{
    		rec(arr,c+1,n-arr[i]);
    	}
    	  }
    	  if (n==0)
    	{
    		r = max(c,r);
    	}	
  
}    
int main()
{
    int n;
    cin>>n;
    
    for (int i = 0; i < 3; ++i)
    {
    	cin>>arr[i];
    }
    int m = rec(arr,0,n);
    cout<<m;
    return 0;
}