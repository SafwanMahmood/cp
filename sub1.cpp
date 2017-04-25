
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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	queue<char> st;
	int count =0;
	for (int i = 0; i < s.length(); ++i)
	{
		st.push(s[i]);
	}
	while(!st.empty() && s.length() > 3)
	{
		char a = st.front();
		// cout<<a<<endl;
		st.pop();
		char b = st.front();
		st.pop(); 
		if (((st.front() == 'r' && a == 'b')&& (b =='b')) || (st.front() == 'b' && a == 'r' && b== 'r')||(st.front() == 'b' && a == 'r' && b== 'r') )
		{
			  count++;
		}
		if(((st.front() == 'b' && a == 'b')&& (b =='b')) || (st.front() == 'r' && a == 'r' && b== 'r') )
		{
			 count++;
	    }
	}
	
	if (s.length() == 3)
	{
	   char a = st.front();
		// cout<<a<<endl;
		 st.pop();
		char b = st.front();
		 st.pop(); 
		if (((st.front() == 'r' && a == 'b')&& (b =='b')) || (st.front() == 'b' && a == 'r' && b== a) )
		{
			count++;
		}
		if(((st.front() == 'r' && a == 'b')&& (b =='b')) || (st.front() == 'r' && a == 'r' && b== 'r') )
		{
			 count++;
	    }	
	}
	cout<<count<<endl;

	return 0;
}
