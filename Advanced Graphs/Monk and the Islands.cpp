// Monk and the Islands
// Send Feedback
// MONK AND THE ISLAND
// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
// Input:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
// Output:
// Print the answer to each test case in a new line.
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ 100000
// 1 ≤ X, Y ≤ N
// SAMPLE INPUT
// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2
// SAMPLE OUTPUT
// 2
// 2


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

void bfs(vector<int> arr[],int n)
{
    queue<int> q;
    q.push(1);
    int visited[n+1];
    mem(visited,0);
    int level[n+1];
    level[1]=0;
    visited[1]=1;
    while(!q.empty())
    {
       int node=q.front();
       //cout<<node<<" ";
       q.pop();
       for(auto x: arr[node])
       {
          if(visited[x]==0)
          {
             if(x==n) { cout<<level[node]+1<<endl;return;}
             q.push(x);
              visited[x]=1;
             level[x]=level[node]+1;
          }
       }
    }
   // cout<<endl;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    int a,b;
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       arr[a].push_back(b);
       arr[b].push_back(a);
    }
    bfs(arr,n);
     
}  

 
signed main()
{
    

    int t;
    t=1;
    cin>>t;
     while(t--)
     {
        solve();
     }
    
  return 0;
}
