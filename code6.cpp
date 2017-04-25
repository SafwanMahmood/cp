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
int cost(int w, int k)
{
	int sum = 0;
	for (int i = 1; i <= w; ++i)
	{
		sum += i*k;
	}
	
	return sum;	
}
int main(int argc, char const *argv[])
{ 
	int k,n,w;
	cin>>k;
	cin>>n;
	cin>>w;
	int b = cost(w,k)-n;
	if (b>0)
	{
		cout<<b<<endl;
	}
	else{
		cout<<0<<endl;
	}
	
	 
	return 0;
}