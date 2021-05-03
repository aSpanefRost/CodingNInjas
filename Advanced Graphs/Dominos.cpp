// Dominos
// Send Feedback
// Domino
// Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
// However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
// Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
// Input
// The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
// Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
// Output
// For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
// Sample Input
// 1
// 3 2
// 1 2
// 2 3
// Sample Output
// 1


//https://codeforces.com/problemset/page/2?tags=1500-1600
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

//Kosaraju's algorithm (Code inspired from the CodeNcode Yt channel)

vector<int> ar[100001];  //adjacency list to store the graph
//vector<int> tr[100001];  //adjacency list to store the transpose graph

vector<int> order;     //To store the nodes of condensation graph and they are in 
                       // order of DFS traversal 
//vector<int> SSC;       // To store a strongly connected component

int vis[100001];

void dfs(int node)     //dfs to sort the nodes in increasing order of their "out-time"
{
     vis[node]=1;
     for(auto x:ar[node])
     {
        if(vis[x]==0)
        {
           dfs(x);
        }
     }
    // cout<<node<<endl;
     order.push_back(node);
}

void dfs1(int node)    //dfs to traverse the nodes of transpose graph
{
   // SSC.push_back(node);
    vis[node]=1;
    for(auto x:ar[node])
    {
       if(vis[x]==0)
       {
        dfs1(x);
       }
    }
}


void solve()
{
    int n;   //no. of nodes
    int m;  // no. of edges
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) {ar[i].clear();}
    order.clear();
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       ar[a].push_back(b);
     //  tr[b].push_back(a);
    } 
    int ans1=0;
    for(int i=1;i<=n;i++)
    {
       if(vis[i]==0) dfs(i);
    }
    for(int i=1;i<=n;i++) vis[i]=0;
      int ans=0;
    for(int i=1;i<=n;i++)
    {
       if(vis[order[n-i]]==0)
       {
        // SSC.clear();
         dfs1(order[n-i]);
          ans++;
         // cout<<"dfs1() called from"<<order[n-i]<<"and Printing SSC"<<endl;
         // for(auto x: SSC)
         // {
         //  cout<<x<<" ";
         // }
         //  cout<<endl;
       }
    }
    
    // for(int x:order) cout<<x<<" ";
    //   cout<<endl;
    cout<<ans<<endl;
    //cout<<min(ans,ans1)<<endl;

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
