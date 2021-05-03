// Kingdom Of Monkeys
// Send Feedback
// This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

// You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
// Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

// You are given an array A where Ai is the number of bananas i'th monkey gathers.

// Find out the number of gold coins that our Monk should set aside for the prize.
// Input:
// First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.
// Output:
// Print the answer to each test case in a new line.
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10^5
// 0 ≤ M ≤ 10^5
// 0 ≤ Ai ≤ 10^12
// SAMPLE INPUT
// 1
// 4 3
// 1 2
// 2 3
// 3 1
// 1 2 3 5
// SAMPLE OUTPUT
// 6
// Explanation
// Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
// Monkey 4 is a team. It gathers 5 bananas.
// Therefore, number of gold coins (highest number of bananas by a team) = 6.

//https://codeforces.com/problemset/page/2?tags=1500-1600
//https://leetcode.com/tag/dynamic-programming/
#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<queue>
using namespace std;
 
#define fo(i,l,r) for(int i=l;i<r;i++)
#define vi vector<int>
//#define lli long long int
#define int long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

int visited[100005];

int bfs(vector<int> arr[],int i,vector<int> banana)
{
    queue<int> q;
    q.push(i);
    visited[i]=1;
    int ans=0;
    ans+=banana[i];
   // cout<<i<<" "<<ans<<endl;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto y:arr[x])
        {
           if(visited[y]==0)
           {
              q.push(y);
              visited[y]=1;
              ans+=banana[y];
             // de(ans);
           }
        }
    }
    return ans;
}
void solve()
{ 
    int n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    int a,b;
    fo(i,0,m) 
    {
       cin>>a>>b;
       arr[a].push_back(b);
       arr[b].push_back(a);
    }
    vector<int> banana(n+1);
    for(int i=1;i<=n;i++) cin>>banana[i];
    //int visited[n+1];
    for(int i=0;i<=n;i++) visited[i]=0;
    int val=INT_MIN;
    int temp;
    fo(i,1,n+1)
    {
        if(visited[i]==0)
        {
           temp=bfs(arr,i,banana);
          // cout<<temp<<endl;
           val=max(val,temp);
          // de(i);
        }
    }
    cout<<val<<endl;
}  

   
signed main()
{
 
    int t;
    t=1;

     cin>>t;
    // int n;
    // cin>>n;
    // vector<int> arr;
    // int x;
    // fo(i,0,n) 
    // {
    //    cin>>x;
    //    arr.push_back(x);
    // }
    //for(auto x:arr)cout<<x;
    
     while(t--)
     {
        solve();
       
     }
    
  return 0;
}
