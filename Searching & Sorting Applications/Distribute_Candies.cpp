// Distribute Candies
// Send Feedback
// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
// 1. All students get equal number of candies.
// 2. All the candies which a student get must be from a single box only.
// As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
// Input
// First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
// Output
// For each test case print the required answer in a seperate line.
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9



#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<sstream>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

bool check(int arr[],int n,lli mid,int k)
{
    lli sum=0;
    fo(i,n) sum+=(arr[i]/mid);
    if(sum>=k) return true;
    else return false;
}

int Max_candie(int arr[],int n,lli s,lli e,int k)
{
   if(s>e) return -1;
   lli mid=(s+e)/2;
   if(s==e)
   {
      if(check(arr,n,s,k)) return s;
      else return -1;
   }
   if(check(arr,n,mid,k))
   {  
      int a= Max_candie(arr,n,mid+1,e,k);
      if(a==-1) return mid;
      else return a;
   }
   else
   {
      int a=Max_candie(arr,n,s,mid,k);
      return a;
   } 

}

int main()
{
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t;
    cin>>t;
    while(t--)
    {
      int n,k;
      cin>>n>>k;
      int arr[n];
      fo(i,n) cin>>arr[i];
      //sort(arr,arr+n);
      lli a=*max_element(arr,arr+n);
      //cout<<a<<endl;
      cout<<Max_candie(arr,n,0,a,k)<<endl;
    }
 
    
    return 0;
    
}
