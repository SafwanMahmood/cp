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
	int m[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>m[i];
	}
	int flag=0;
	int count=0;
	int flag1=0;
	int count1=0;
	for (int i = 0; i < n; ++i)
	{
	       if (m[i]%2==0)
	       	{      		
	       		count++;
	       	}
	       if(m[i]%2==1)
	       {
	       	   count1++;
	       	   
	       }
	       
	}
	for (int i = 0; i < n; ++i)
	{
		if (count1>count)
		{
			if (m[i]%2==0)
			{
				cout<<i+1<<endl;
				break;
			}
		}
		else
		{
			if (m[i]%2==1)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}
	

	return 0;
}