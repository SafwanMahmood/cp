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
class node
{
public:
	int data;
	node *next;
};

class link
{
public:
	node* sortinsert(int k,node *head)
	{
         if (head == NULL || head->data >= k)
         {
         	node *a = new node;
         	a->data = k;
         	a->next = head;
         	head = a;

         }
         else
         {
         	node *curr;
         	curr = head;
         	while(curr->next!=NULL && curr->next->data < k )
         	{
         		curr = curr->next;
         	}
         	node *a = new node;
         	a->data = k;
         	a->next = curr->next;
         	curr->next = a;

         }
         return head;
	}
	node* Delete(int k,node* head)
	{
		if(head == NULL)
		{
			cout<<"list empty"<<endl;
		}
		else{
			node *curr,*prev;
         	curr = head;
         	if (curr->data==k)
         	{
         		head = curr->next;
         		free(curr);
         		return NULL;
         	}
         	while(curr!=NULL && curr->data != k )
         	{
         		prev = curr;
         		curr = curr->next;
         	}
         	if (curr==NULL)
         	{
         		cout<<"lol"<<endl;
         	}
         	prev->next = curr->next;
		}	
         return head; 
	}

	void print(node *head)
{
	node *a = head;
	if (a==NULL)
	{
		cout<<"NULL";
	}
	while(a!=NULL)
	{
		cout<<a->data<<endl;
		a = a->next;
	}

}

}a,b;

int pivot(int a[],int low,int high)
{
	if (high<low) return -1;
	if (high==low)
	{
		return low;/* code */
	}
	int mid = (low+high)/2; 
	if(mid< high && a[mid] > a[mid+1])
	{
		return mid;
	}
	if(mid > low && a[mid] < a[mid-1])
	{
		return mid-1;
	}
	if (a[low]>= a[high])
	{
		return pivot(a,low,mid-1);
		/* code */
	}
	
 return pivot(a,mid+1,high);

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
node* search(node *head,int k)
{
	node *a = head;
	if (a==NULL)
	{
		cout<<"NULL";
	}
	while(a!=NULL)
	{
		if (a->data==k)
		{
		 cout<<a->data<<"found"<<endl;
		 return a;   	/* code */
		}
		a = a->next;
	}

}
void remloop(node* head,int l)
{
	node *a = head,*b = head;
	int k =1;
	while (a->next != b)
    {
        a = a->next;
        k++;
    }
   cout<<k;
	for (int i = 0; i < k; ++i)
	  {
	  	 b = b->next;
	  } 
	  while (b != a)
    {
        a = a->next;
        b = b->next;
    }
    b= b->next;
     while (b->next != a)
       b = b->next;
    b->next = NULL;
    return;
}
 
void detectAndRemoveLoop(node *head)
{
    node *slow = head;
    node *fast = head->next;
 
    // Search for loop using slow and fast pointers
    int k;
    while (fast && fast->next)
    {
        if (slow == fast)
        {	
            k = slow->data; 
            break;
        }    
        slow = slow->next;
        fast = fast->next->next;
    }
    node* curr;
     // = search(head,k);
    // cout<<curr->data<<endl;
    node* prev = curr;
    while(prev->next != curr)
    {
    	prev = prev->next;
    }
    prev->next =NULL;  
    // /* If loop exists */
    // if (slow == fast)
    // {
    //     slow = head;
    //     while (slow != fast->next)
    //     {
    //         slow = slow->next;
    //         fast = fast->next;
    //     }
 
    //     /* since fast->next is the looping point */
    //     fast->next = NULL; /* remove loop */
    // }
}
void loop(node* head)
{
	node *slow = head,*fast = head;
	int count=0;
	if (head==NULL)
	{
		cout<<"NULL";
	}
	while(slow!=NULL && fast!=NULL)
	{		
		fast = fast->next->next;
		slow = slow->next;
		if (fast==slow)
		{
			cout<<"looop ->"<< count<<endl;
			// remloop(head,count);
			return ;
		}
		count++;
	}  
}
int Min(int a,int b,int c)
{
	return min(a,min(c,b));
}
int binary(int a[],int l,int r,int x )
{
	if (r>=l)
	{
		int mid = 1 + (r-l)/2;
		if (a[mid]==x)
		{
			return x;
		}
		 if(a[mid] > x )
		{
			return binary(a,l,mid-1,x);
		}
		 return binary(a,mid+1,r,x);  	
		
	}
	return -1;
}
int edit(string a,string b, int n,int m)
{
     int dp[n+1][m+1];
     for (int i = 0; i <= n; ++i)
     {
     	for (int j = 0; j <= m; ++j)
     	{
     		if (i==0)
     		{
     			dp[i][j]=j;/* code */
     		}
     		else if (j==0)
     		{
     			dp[i][j]=i;/* code */
     		}
     		else if(a[i-1]==b[j-1])
     		{
     			dp[i][j] = dp[i-1][j-1];
     		}	
     		else
     		{
                 dp[i][j] = 1 + Min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
     		}

     		 
     	}
     }
     return dp[n][m];
}
int edit1(string a,string b, int n,int m)
{

	if (n==0)
	{
		return m;
		/* code */
	}
	else if (m==0)
	{
		return n;
		/* code */
	}
	else if (a[n-1]==b[m-1])
	{
		return edit1(a,b,n-1,m-1);
	}
	else{
		return 1 + Min(edit1(a,b,n-1,m),edit1(a,b,n,m-1),edit1(a,b,n-1,m-1));
	}
}
void print(node *head)
{
	node *a = head;
	if (a==NULL)
	{
		cout<<"NULL";
	}
	while(a!=NULL)
	{
		cout<<a->data<<endl;
		a = a->next;
	}

}
void printArray(int arr[] , int n){ FOR(i,0,n) cout << arr[i] << " " ; cout << endl;}


int main() {
	node *head=NULL,*head1=NULL;
	head= a.sortinsert(3,head);
	head= a.sortinsert(9,head);
	head=a.sortinsert(2,head);
	head=a.sortinsert(1,head);
	head=a.sortinsert(10,head);
	head=a.sortinsert(5,head);

	head1=a.sortinsert(3,head1);
	head1=a.sortinsert(9,head1);
	head1=a.sortinsert(2,head1);
	head1=a.sortinsert(1,head1);
	head1=a.sortinsert(10,head1);
	head1=a.sortinsert(55,head1);
	
	// a.sortinsert(4);
	// print(head);
	// // a.Delete(3);
	// print(head);
	// cout<<"lol"<<endl;
	// a.print(head1);
	// // a.Delete(2);
	// print(head);
 //    // search(head,9);
    // head->next->next->next->next->next->next = head->next;
    // loop(head);
    // // print(head);
    // detectAndRemoveLoop(head);
    // print(head);
    // string a,b;
    // cin>>a>>b;
    // int l = edit(a,b,a.length(),b.length());
    // cout<<l<<endl;
    // cout<<edit1(a,b,a.length(),b.length())<<endl;
    // int p[] ={3,4,5,1,2};
    // cout<<pivot(p,0,4)<<endl;
                    
    return 0;
}