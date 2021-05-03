// Code : Is Connected ?
// Send Feedback
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
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
// true
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// false 
// Sample Output 2 Explanation
// The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 



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

vector<int> bfs(vector<vector<int> > v,int g)
{
     vector<int> vis(g);
     for(int i=0;i<g;i++) vis[i]=0;
     queue<int> q;
     int cur=0;
     q.push(0);
     vis[cur]=1;
     while(!q.empty())
     {
        int cur=q.front();
        q.pop();
        for(int x: v[cur])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                q.push(x);
            }
        }

     }
     return vis;

}

int main() {

   
    
    int g,e;
    cin>>g>>e;
    if(g==0) {cout<<"true";return 0;}
    vector<vector<int> > v(g);
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> vis=bfs(v,g);
    bool check=true;
    for(int i=0;i<g;i++)
    {
        if(vis[i]==0)
        {
            cout<<"false";
            check=false;
            break;
        }
    }
    if(check) cout<<"true";
 
    return 0;  
    
}



