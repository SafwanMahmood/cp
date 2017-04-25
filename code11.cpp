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
	int a,b;
	cin>>a>>b;
    string s,s1,z;
    int sum = a+b;
    s= IntToString(a);
    s1= IntToString(b);
    z = IntToString(sum);
    string ss="";
    string ss1 ="";
    string z1 ="";
    for (int i = 0; i < s.length(); ++i)
      {
      	 if (s[i]!='0')
      	 {
      	 	ss += s[i];
      	 }
      }
    for (int i = 0; i < s1.length(); ++i)
      {
      	 if (s1[i]!='0')
      	 {
      	 	ss1 += s1[i];
      	 }
      }
      for (int i = 0; i < z.length(); ++i)
      {
      	 if (z[i]!='0')
      	 {
      	 	z1 += z[i];
      	 }
      }
    
     int a1 = convert(ss);
     int b1 = convert(ss1);
     int c1 = convert(z1);
     int sum1 = a1 + b1 ;
     if (c1==sum1)
      {
      	cout<<"YES";

      } 
      else{
      	cout<<"NO";
      }

	return 0;
}