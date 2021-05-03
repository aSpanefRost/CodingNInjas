// Min. Absolute Difference In Array
// Send Feedback
// Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
// We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
// Input format :
// Line 1 : Integer N, Array Size
// Line 2 : Array elements (separated by space)
// Output Format :
// Minimum difference
// Constraints :
// 1 <= N <= 10^6
// Sample Input :
// 5
// 2 9 0 4 5
// Sample Input :
// 1

// arr - input array
// n - size of array
#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
   int ans=INT_MAX;
     sort(arr,arr+n);
     int x;
     for(int i=0;i<n-1;i++)
     {   x=abs(arr[i+1]-arr[i]);
         if(x<ans) ans=x;
     }
     
     return ans;
}
