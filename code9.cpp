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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;
typedef bitset<11> bit;
typedef queue<LL> QLL;
typedef string str;

#define FOR(i, x, y) for (LL i = (x); i < (y); ++i)
#define FORV(i, x)                                                             \
  for (std::vector<LL>::iterator i = (x.begin()); i != (x.end()); ++i)
 #define FORVS(i, x)                                                             \
  for (std::vector<string>::iterator i = (x.begin()); i != (x.end()); ++i)
#define sd(x) scanf("%lld", &x)
#define sd2(x,y) scanf("%lld %lld", &x,&y)
#define sd3(x,y,z) scanf("%lld %lld %lld", &x,&y,&z)
#define sdi(x) scanf("%d", &x)
#define sdi2(x,y) scanf("%d %d", &x,&y)
#define sdi3(x,y,z) scanf("%d %d %d", &x,&y,&z)
#define ps(x) printf("%s\n",x)
#define p(e) printf("\n");
#define pb(e) push_back(e)
#define mp make_pair
#define All(x) x.begin(), x.end()
#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define MAX 1e18
#define PI 3.14159265
 #define int long long
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
string all[2000000];
int co=0;
int lucky(int n)
{
	int count=0;
	int count1=0;
	
    while (n != 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            return 0;
        }
        if (n % 10 == 4 )
        {
            count++;
        }
        if ( n % 10 == 7)
        {
            count--;
        }
        n /= 10;
        
    }
    if (count == 0)
    {
    	return 1;
    }
    return 0;
    
}
 
// ones & zeroes --> counts of 1's and 0's in current string 'str'
// len ---> desired length of every permutation
void generate(int ones, string str, int len)
{
    // If length of current string becomes same as desired length
    if (len == str.length())
    {
    	if(lucky(convert(str))==1 )  
        {   
           all[co] = str;
           co++;
           
        }
          return;
           
    }
    else{
    str[ones] ='4'; 
    generate(ones+1, str , len);
    str[ones] = '7'; 
    generate(ones+1, str, len);
   }
}
 
// Driver program to test above function
std::vector<string> generate1(int n,int i,std::vector<string> v,string s){
	if(i==n){
		 v.push_back(s);
		 return v;
	}
	else{
		s[i] = '4';
		std::vector<string> v_c(generate1(n,i+1,v,s));
		s[i] = '7';
		std::vector<string> v_c2(generate1(n,i+1,v_c,s));
		return v_c2;
	}
}

signed main()
{
	int n;
	cin>>n;
	int k;
	if (n>1000000000)
	{
		return 0;
	}
	if (lucky(n)==1)
	{
		cout<<n<<endl;
		return 0;
	}
	string a = IntToString(n);
	 int  l = a.length();
	// cout<<l<<endl;
	// string s(l,'4');
	// string s1(l+1,'4');
	// string s2(l+2,'4');
	// std::vector<string> v;
	// std::vector<string> v1;
	// std::vector<string> v2;
	// v = generate1(l,0,v,s);
	// v1 = generate1(l+1,0,v1,s1);
	// v2 = generate1(l+2,0,v2,s2);
	// sort(All(v));
	// //cout<<v.size()<<endl;
    string str(l,'4');
    // string str1(l,'4');
    int o = l+2;

    if (l%2==0)
    {
    	    generate(0, str,l);
    	   
         	generate(0, str,o);
        
    }
    else 
    {
    	generate(0, str,l+1);
    }
    
     int lol[co];
    for (int i = 0; i < co; ++i)
    {
    	lol[i] = convert(all[i]);
    }
    sort(lol, lol + co);
    // for (int i = 0; i < co; ++i)
    // {
    // 	cout<<lol[i]<<endl;
    // }
    for (int i = 0; i < co; ++i)
    {
    	if (lol[i] >= n )
    	{
    	  cout<<lol[i]<<endl;
    	  break;
    	}
    	
    }
    // if (l%2==0)
    // {
    // 	   sort(All(v));
    // 	   bool x = 0;
    // 	   FORVS(it,v){
    // 	   		//cout<<(*it)<<endl;
		  //   	if((convert((*it)))>=n){
		  //   		if(lucky(convert((*it))) == 1)
		  //   		{
		  //   			cout<<*it<<endl;
		  //   			x = 1;
		  //   			break;
		  //   		}
		  //   	}
		  //   }
    //     	if(!x){
    //     		sort(All(v2));
	   //      		FORVS(it,v2){
	   //      			//cout<<(*it)<<endl;
				//     	if((convert((*it)))>=n){
				//     		if(lucky(convert((*it))) == 1)
				//     		{
				//     			cout<<*it<<endl;
				//     			x = 1;
				//     			break;
				//     		}
				//     	}
				//     }
    //     	}
    // }
    // else 
    // {
    // 	sort(All(v1));
    // 	FORVS(it,v1){
		  //   	if((convert((*it)))>=n){
		  //   		//cout<<(*it)<<endl;
		  //   		if(lucky(convert((*it))) == 1)
		  //   		{
		  //   			cout<<*it<<endl;
		  //   			//x = 1;
		  //   			break;
		  //   		}
		  //   	}
		  //   }
    // }
     return 0;
}

