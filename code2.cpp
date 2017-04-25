/*
***************************************************************************************************************
 
                          Author : SAFWAN 
 
**************************************************************************************************************
*/
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
int convert(string k)
{
	int a;
	istringstream ss(k);
    ss >> a;
    return a;
}

int main() {
    string s;
    string s1;
    cin>>s>>s1;
    string hrs,min,min1,hrs1;
    for (int i = 0; i < 2; ++i)
    {
          hrs +=  s[i];	
    }
    for (int i = 3; i < 5; ++i)
    {
          min +=  s[i];	
    }
    for (int i = 0; i < 2; ++i)
    {
          hrs1 +=  s1[i];	
    }
    for (int i = 3; i < 5; ++i)
    {
          min1 +=  s1[i];	
    }
    
    int k = convert(hrs);
    int k1 = convert(hrs1);
    int m = convert(min);
    int m1 = convert(min1);
    
    k = k+24;
    if (k-k1>=24)
     {
       	  k = k -24 - k1;
     }
     else
     {
         k =k-k1; 
     }
     if (m-m1>=0)
     {
     	m = m - m1;
     }
     else{
     	if (k>0)
     	{
     		k = k -1;
     	}
     	else{
     		k = k + 24 -1;
     	}	
     	m = m + 60 - m1;
     	
     }
     string l,o;
     if (k<10)
     {
     	l = "0" + IntToString(k) ; 
     }
     else{
     	l = IntToString(k);
     }
     if (m<10)
     {
     	o = "0" + IntToString(m) ; 
     }
     else{
     	o = IntToString(m);
     }
     //cout<<IntToString(k)<<':'<<IntToString(m)<<endl;	
     cout<<l<<':'<<o<<endl; 
       
        
     

    return 0;
}