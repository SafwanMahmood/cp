#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct node
{
    int x,y;
};
node a[101];
node b[101];
bool cmp(node aa,node bb)
{
    return aa.x<bb.x;
}
int main()
{
    int n;
    scanf("%d",&n);
    int num1=0,num2=0;
    for(int i=0;i<n;i++)
    {
        int c,d;
        cin>>c>>d;
        if(c<0){
            a[num1].x=-c;
            a[num1++].y=d;
         }   
        else
        {    
            b[num2].x=c;
            b[num2++].y=d;
        }    
    }
    sort(a,a+num1,cmp);
    sort(b,b+num2,cmp);

    int num=min(num1,num2);
    int ans=0;
    for(int i=0;i<num;i++)
        ans+=(a[i].y+b[i].y);
    if(num1>num2)
        ans+=a[num2].y;
    else if(num2>num1)
        ans+=b[num1].y;
    cout<<ans<<endl;

}