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
#define FORV1(i, x)                                                             \
  for (std::vector<ii>::iterator i = (x.begin()); i != (x.end()); ++i)

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

stack<int> s;
std::vector<ii> p;
int n;
bool *visited = new bool[n];

stack<int> la;
void topo(std::vector<int> *v, int st,bool *visited)
{
  // s.push(st);
  // while(!s.empty())
  // {
  // 	int count = 0 ;
  //    int t = s.top();
    visited[st] = true;
     // s.pop(); 
     FORV(i,v[st])
     {
         if (!visited[*i])
            {
            	 // s.push(*i);
               topo(v,*i,visited);
            	 // count++;
            }   
     }
     // p.push_back(mp(t,count));
     

  // }
  la.push(st);
  
}
queue<int> q;
stack<int> o;
int *k = new int[n];

void topo1(std::vector<int> *v,queue<int> q)
{
  while(!q.empty())
  {
      int count = 0 ;
      int t = q.front();
      visited[t] = true;
      q.pop();
      o.push(t); 
      // cout<<t<<" ";
      FORV(i,v[t])
      {
               if (--(k[*i])==0)
                {
                  q.push(*i);/* code */
               }
                     // /topo(v,*i,visited);
               // count++;
     }   
}
     // p.push_back(mp(t,count));
     // o.push(t);

 
  // la.push(st);
  
}
// struct less_X_j
// {
//     bool operator()(ii const &l, ii const &r) const { return l.second > r.second; }
// };

int main() {
	cin>>n;
	int a[n],b[n];
	int m;
	cin>>m;
  
  FOR(i,0,n){
    a[i] = 0;
  }
	std::vector<int> *v = new vector<int>[n];
    FOR(i,0,m)
    {
    	cin>>a[i]>>b[i];
    	v[a[i]].push_back(b[i]);
    }

    FOR(i,0,n){
    	visited[i] = false;
      // cout<<k[i]<<endl;
      

    }
    for (int u=0; u<n; u++)
    {
        std::vector<int>::iterator itr;
        for (itr = v[u].begin(); itr != v[u].end(); itr++)
             k[*itr]++;
    }
    // int start = a[0] ;
   
    FOR(i,0,n)
    {
      if (k[i]==0)
      {
           q.push(i);
      }
    
   }
   topo1(v,q);
    // for (int i = 0; i < n; ++i)
    // {
    // 	if (!visited[i])
    // 	{
    // 		topo(v,i,visited);
    // 	}
    // }
    // // sort(p.begin(),p.end(),less_X_j{});
    // FORV1(i,p){
    //  	cout<<(*i).first<<" "<<(*i).second<<endl;
    // //  }
    // while(!la.empty()){
    // 	cout<<la.top()<<" ";
    // 	la.pop();
    // }
    while(!o.empty()){
      cout<<o.top()<<" ";
      o.pop();
    }
    return 0;
}