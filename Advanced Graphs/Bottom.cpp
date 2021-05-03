// BOTTOM
// Send Feedback
// We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

// Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

// Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
// Input Specification
// The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
// Output Specification
// For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
// Sample Input
// 3 3
// 1 3 2 3 3 1
// 2 1
// 1 2
// 0
// Sample Output
// 1 3
// 2


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

vector<int> ar[5001];
vector<int> tr[5001];

int visited[5001];
vector<int> order;
vector<int> SSC;
int Connected_component[5001];
vector<vector<int> > all;
void dfs(int node)
{
   visited[node]=1;
   for(auto x: ar[node])
   {
       if(visited[x]==0)
       {
         dfs(x);
       }
   }
   order.push_back(node);
}

void dfs1(int node)
{
  visited[node]=1;
  SSC.push_back(node);
  for(auto x: tr[node])
  {
     if(visited[x]==0)
     {
       dfs1(x);
     }
  }
}


void solve()
{
   int n,m;
   while(1)
   {
     cin>>n;
     if(n==0) break;
     cin>>m;
     int a,b;
     for(int i=1;i<=n;i++) 
      {
        visited[i]=0;
        ar[i].clear();
        tr[i].clear();
      }
     //vector<int> arr[n+1];
     for(int i=0;i<m;i++)
     {
         cin>>a>>b;
         ar[a].push_back(b);
         tr[b].push_back(a);
     }
     
     for(int i=1;i<=n;i++)
     {
       if(visited[i]==0)
       {
          dfs(i);
       }
     }
     for(int i=1;i<=n;i++) visited[i]=0;
     int aaaa=1;
     for(int i=1;i<=n;i++)
     {
       if(visited[order[n-i]]==0)
       {
          dfs1(order[n-i]);
          for(auto x: SSC)
          {
             Connected_component[x]=aaaa;
          }
          aaaa++;
          all.push_back(SSC);
          SSC.clear();
       }
     }
     vector<int> anss;
     bool check=false;
     aaaa=1;
     // for(auto x:all)
     // {
     //     for(auto y:x)
     //     {
     //       cout<<y<<" ";
     //     }
     //     cout<<endl;
     // }    
     // for(int i=1;i<=n;i++)
     // {
     //   cout<<Connected_component[i]<<" ";
     // }
     // cout<<endl;
     for(auto x:all)
     {
         for(auto y:x)
         {
           for(auto z:ar[y])
           {
             if(check) break;
             if(Connected_component[z]!=aaaa)
             {
                check=true;
                //de(1);
             }
           }
         }
         if(!check)
         {
            for(auto y:x)
            {
               anss.push_back(y);
            }
         }
         check=false;
         aaaa++;
     }
     sort(anss.begin(),anss.end());
     for(auto x: anss) cout<<x<<" ";
      cout<<endl;
      all.clear();
      order.clear();
   }
}  

 
signed main()
{
    
    
    int t;
    t=1;
    // cin>>t;
     //while(t--)
     {
        solve();
     }
    
  return 0;
}
