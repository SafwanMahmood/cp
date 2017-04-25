/*
***************************************************************************************************************
 
                          Author : SAFWAN 
 
**************************************************************************************************************
*/
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#define FOR(i,start,end) for(size_t i=start;i<end;i++)
#define rFOR(i,end,start) for(size_t i=end,i>=start;i--)

using namespace std;

string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}

int main() {
    
    int t;
    cin>>t;
    while(t--){

    	string s;
        cin>>s;
        if (s.length()<=10)
        {
        	cout<<s<<endl;
        }
        else
        {
        	string a;
        	a = s[0] + IntToString(s.length()-2) + s[s.length()-1]; 
        	cout<<a<<endl;
        }	


    }
    return 0;
}