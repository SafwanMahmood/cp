#include <iostream>
#include <string>
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

string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int check(int k)
{
  string a = IntToString(k);
  for (int i = 0; i < a.length(); ++i)
    {
      if (a[i]!='7' && a[i]!='4' )
	    {
	    	return 1;
	    }  
	
    }
	
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int flag =0;
	int flag1 =0;
	int h;
	flag = check(n); 
    if (flag==1)
	{
		for (int i = 2; i * i <= n; ++i)
        {
          if (n % i == 0 && (check(i)==0 || check(n /i)==0))
         {
            flag1 = 1;
         }
       }

        if (flag1==1)
        {
        	cout<<"YES"<<endl;
        }
		else
		{	
		  cout<<"NO"<<endl;
		}  
	}
	else
	{
		cout<<"YES"<<endl;
	}	
	return 0;
}