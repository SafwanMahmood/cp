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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int min1;
	int max1;
	int max =0;
	int min = 102;
	int ans;
    for (int i = 0; i < n; ++i)
    {
    	if (a[i]>max)
    	{
    		max = a[i];
    		max1 =i;
    	}
    	if (a[i]<=min)
    	{
    		min = a[i];
    		min1 =i;
    	}
    }
    
    if (max1 > min1)
    {
      ans = (max1) + (n-1 - min1) - 1;	
    }
    else
    {
    	ans = (max1) + (n-1 - min1);
    }   
    cout<<ans<<endl;

	return 0;
}