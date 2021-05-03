// Code : BFS Traversal
// Send Feedback
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.
// Note:
// 1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
// 2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 3. E is the number of edges present in graph G.
// 4. Take graph input in the adjacency matrix.
// 5. Handle for Disconnected Graphs as well
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print the BFS Traversal, as described in the task.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// 0 1 3 2

#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;
 
void bfs(vector<int> ar[],int N,int vis[],int k) 
{
   //int vis[N+1];
   //for(int i=0;i<=N;i++) vis[i]=0;
   queue<int> q;
   int c=k;
   q.push(c);
   //cout<<c-1<<" ";
   vis[c]=1;
   while(!q.empty())
   {
   	  int v=q.front();
   	  q.pop();
   	  cout<<v-1<<" ";
   	  for(int x:ar[v])
   	  {
   	  	if(vis[x]==0)
   	  	{
   	  		vis[x]=1;
   	  		q.push(x);
   	  	}
   	  }
   }

}
 
int main()
{
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int N,M;
    cin>>N>>M;
    if(N==0) return 0;
    vector<int> ar[N+1];
    int a,b;
    for(int i=1;i<=M;i++)
    {  
    	cin>>a>>b;
    	a++;
    	b++;
       ar[a].push_back(b);
       ar[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        sort(ar[i].begin(),ar[i].end());
    }
    int vis[N+1];
    for(int i=1;i<=N;i++) vis[i]=0;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==0)
        {
          bfs(ar,N,vis,i);
        }
    }

    return 0;
}
