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
bool compareLen(const std::string& a, const std::string& b)
    {
    return (a.size() < b.size()); 
     }  
signed main()
{
    int n,k;
    cin>>n>>k;
    string a[n+1];
    int tries = 0;
    int count =0;
    for (int i = 0; i <= n; ++i)
    {
        cin>>a[i];
    }
    int t = 0 ;
    string d = a[n]; 
    int ans = a[n].length();
    sort(a,a+n+1,compareLen);
    for (int i = 0; i <= n; ++i)
    {
        if (a[i].length() == ans )
        {
            count++;
        }
    }
    cout<<count<<endl;
    int max =0;
    int min=0;
    for (int i = 0; i < n; ++i)
    {
        if(a[i].length() < ans && tries < k )
        {
            t++;
            tries++;   
        }
        if (tries==k)
        {
                t = t + 5;
                tries =0; 
        }
        if (a[i].length() == ans )
        {
            t++;
            min = t;
            break; 
        }


    }
    cout<<min<<endl;
    return 0;
}
