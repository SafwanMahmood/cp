#include<iostream>
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
using namespace std;
 
// A utility function to get maximum value in arr[]
long long int getMax(long long int arr[], long long int n)
{
    long long int mx = arr[0];
    for (long long int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(long long int arr[], long long int n, long long int exp)
{
    long long int output[n]; // output array
    long long int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(long long int arr[], long long int n)
{
    // Find the maximum number to know number of digits
    long long int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (long long int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(long long int arr[], long long int n)
{
    for (long long int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 long long int convert(string k)
{
    long long int a;
    istringstream ss(k);
    ss >> a;
    return a;
}
 
// Driver program to test above functions
 int main()
{
    long long int n;
    cin>>n;
    long  long int a[n];
    string s;
    for (long long int i = 0; i < n; ++i)
    {
    	cin>>s;
    	a[i] = convert(s);
    	/* code */
    }
    radixsort(a, n);
    print(a, n);
    return 0;
}