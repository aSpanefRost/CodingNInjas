// Coin Change Problem
// Send Feedback
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
// Return 0 if the change isn't possible.
// Input Format
// The first line of the input contains an integer value N, which denotes the total number of denominations.

// The second line of input contains N values, separated by a single space. These values denote the value of denomination.

// The third line of the input contains an integer value, that denotes the value of V.
// Output Format
// Print the total total number of ways i.e. W.
// Constraints :
// 1 <= n <= 10
// 1 <= V <= 1000

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output 1 :
// 4
// Explanation to Sample Input 1 :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// 250
// Sample Output 2 :
// 13868903

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
//#include<cstdlib>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

int dp(int arr[],int c,int n)
{
   int tab[c+1][n+1];
   fo(i,c+1) fo(j,n+1) tab[i][j]=-1;
   for(int i=0;i<=n;i++)
   {
     tab[0][i]=0;
   }
   for(int i=0;i<=c;i++)
   {
     tab[i][0]=1;
   }
   for(int i=1;i<=c;i++)
   {
      for(int j=1;j<=n;j++)
      {
            tab[i][j]=tab[i-1][j];
            if(j-arr[i-1]>=0) tab[i][j]+=tab[i][j-arr[i-1]];
      }
   }
   // for(int i=0;i<=c;i++)
   // {
   //    for(int j=0;j<=n;j++)
   //    {

   //       cout<<tab[i][j]<<" ";
   //    }
   //    cout<<endl;
   // }
   return tab[c][n];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
  return dp(denominations,numDenominations,value);
    
}
