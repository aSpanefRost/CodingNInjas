// Code : Get Path - BFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// Print the path from v1 to v2 in reverse order.
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :


#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

int src,des;
map<int,int> m; 
vector<int> bfs(vector<vector<int> > graph,int v)
{
    int cur=src;
    queue<int> q;
    int visited[v];
    mem(visited,0);
    q.push(cur);
    visited[cur]=1;
   // cout<<1;
    while(!q.empty())
    {    
        cur=q.front();
      
        q.pop();
        //cout<<cur<<" ";
        if(cur==des) break;
        for(int x:graph[cur])
        {
           if(visited[x]==0)
           {
              visited[x]=1;
              q.push(x);
              m[x]=cur;
           }
        }
    }
    vector<int> ans;
    cur=des;
    while(1)
    {
        if(m.find(cur)!=m.end())
        {
            ans.push_back(m[cur]);
            cur=m[cur];
        }
        else break;
    }
    return ans;

}

int main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int v,e;
    cin>>v>>e;
    vector<vector<int> > graph(v);
    int a,b;
    
    for(int i=0;i<e;i++)
    {
       cin>>a>>b;
       graph[a].push_back(b);
       graph[b].push_back(a);
    }
    for(int i=0;i<v;i++) sort(graph[i].begin(),graph[i].end());
   // int src,des;
    cin>>src>>des;     
    //cout<<1;
    vector<int> ans=bfs(graph,v);  
    if(ans.size()>0) 
    {
        cout<<des<<" ";
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            cout<<*it<<" ";
        }

    }  
 
    return 0;  
    
}



