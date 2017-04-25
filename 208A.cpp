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


int main() {
	string s;
	cin>>s;
	int flag=0;
	int count=0;
	// string s1="";
	// for (int i = 0; i < s.length(); ++i)
	// {
	// 	if (s[i]!='1' || s[i]!='4')
	// 	{
	// 		flag=1;
	// 		break;
	// 	}
	// 	if (s[i]=='1' && s[i+1]!='4')
	// 	{
	// 	   s1 += '1' ;	
	// 	}
	// 	else if (s[i]=='1' && s[i+1]=='4'  && s[i+2]!='4')
	// 	{
	// 	   s1 += "14" ;	
	// 	}
	// 	else if (s[i]=='1' && s[i+1]=='4'  && s[i+2]=='4')
	// 	{
	// 	   s1 += "144" ;	
	// 	}
	// }
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]=='4')
		{
			count++;
		}
		if (s[i]!='4')
		{
			count=0;
		}
		if (count>=3)
		{
			break;
		}
		
		/* code */
	}
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]!='1' || s[i]!='4')
		{
			flag=1;
			break;
		}

		/* code */
	}
	// cout<<count<<endl;
	while(s.find("144")!=-1)
	{
	 s = s.replace( s.find("144"), 3, "");
	}
	while(s.find("14")!=-1)
	{
	 s = s.replace( s.find("14"), 2, "");
	}
	while(s.find("1")!=-1)
	{
	 s = s.replace( s.find("1"), 1, "");
	}
	// cout<<s<<endl;
	if (s!="" || flag==1 && count >=3 )
	{
	   cout<<"NO"<<endl;	
	}
	else
	{

		cout<<"YES"<<endl;
	}
	
	// cout<<s<<endl;
	// while(s.find("  ")!=-1)
	// {
	//  s = s.replace( s.find("  "), 2, " ");
	// }
	// // cout<<s<<endl;
 //    if (s[0]==' ')
 //    {
 //       s = s.replace( 0, 1, "");	
 //    }
 //    cout<<s<<endl;
    return 0;
    
}