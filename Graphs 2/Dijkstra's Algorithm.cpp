// Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
// Note : Order of vertices in output doesn't matter.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5



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
 
#define fo(i,n) for(lli i=0;i<n;i++)
#define vi vector<lli>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const lli mod=1000000007;
const lli INF=1000000000;


int main()
{
 
    
  
    lli n,m;
    cin>>n>>m;
    vector<pair<lli,lli> > adj[n+1];
    lli a,b,w;
    for(lli i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        a++;b++;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    priority_queue<pair<lli,lli> ,vector<pair<lli,lli> > ,greater<pair<lli,lli > > > pq;

    vector<lli> dist (n+1,INF);

    pq.push(make_pair(0,1));
    dist[1]=0;

    while(!pq.empty())
    {
        lli curr=pq.top().second;
        lli curr_dis=pq.top().first;
        pq.pop();
        for(pair<lli,lli> edge: adj[curr])
        {
            if(curr_dis+edge.second<dist[edge.first])
            {
                dist[edge.first]=curr_dis+edge.second;
                pq.push(make_pair(dist[edge.first],edge.first));
            }
        }
    }
    for(lli i=1;i<=n;i++)
    {
        cout<<i-1<<" "<<dist[i]<<endl;
    }

}
