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
  string s;
  string b;
  string c="";
  cin>>s;
  cin>>b;
  int flag=0; 
  // c = s;
  // d = s;
  // for (int i = 0; i < s.length()-1; ++i)
  // {
  //   int x  = int(s[i]-48);
  //   int y  = int(s[i+1]-48);
  //   int k  = x^y;
  //   int k1 = x|y;
  //   s[i]   =  char(k+48);
  //   s[i+1] = char(k1+48);
  //   c[i]   = s[i+1];
  //   c[i+1] = s[i]; 
  // }
  // string sf = s;
  // int x1 = s[0];
  // int y1 = s[0];
  // for (int i = 1; i < s.length()-1; ++i)
  // {
  //   x1  = int(s[i-1]-48);
  //   y1  = int(s[i]-48);
  //   int q  = x1^y1;
  //   int q1 = x1|y1;
  //   s[i-1]   =  char(q+48);
  //   s[i] = char(q1+48);
  //   d[i-1]   = s[i];
  //   d[i] = s[i-1]; 
  // }
  // if (s.length()!=b.length())
  // {
  //   flag = 1;
  // }
   for (int i = 0; i < s.length(); ++i)
  {
     if (s[i]!=b[i])
     {
        c += '1';
     }
     else{
      c += '0';
     }
  }
  
  //  if (b==sf || c==b ||s==b||b==d)
  //  {
  //   cout<<"YES"<<endl;
  //  }
  // else{
  //   cout<<"NO"<<endl;
  // }
  cout<<c<<endl;
   return 0;
}