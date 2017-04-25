#include <algorithm>
#include <iostream>
#include <vector>
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
// #define int long long int
vector<int> v;
void recurse(int num)
{
    v.push_back(num);
    if (num > ((int)10e10))
        return;
    recurse(num * 10 + 4);
    recurse(num * 10 + 7);
}
string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int main()
{
    recurse(0);
    sort(v.begin(), v.end());
    int n;
    cin >> n;
    string a = IntToString(n);
    int  k = a.length();
    cout << find(v.begin(),v.end(),k)-v.begin()<< endl;
    return 0;
}