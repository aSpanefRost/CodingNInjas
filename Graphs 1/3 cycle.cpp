// 3 Cycle
// Send Feedback
// Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
// Input Format :
// The first line of input contains two space separated integers, that denotes the value of N and M.
// Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
// Output Format :
// Print the count the number of 3-cycles in the given graph
// Constraints :
// 0 <= N <= 100
// 0 <= M <= (N*(N-1))/2
// 0 <= u <= N - 1
// 0 <= v <= N - 1
// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 0 1
// 1 2
// 2 0
// Sample Output 1:
// 1


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
 
int countt;

void dfs(vector<vector<int> > v,int g,int i)
{
    
    for(int x:v[i])
    {
        for(int y:v[x])
        {
            if(y!=i)
            {
                for(int z:v[y])
                {
                    if(z==i)
                    {
                        countt++;
                    }
                }
            }
        }
    }
} 
 
int main()
{
 

 
    int g,e;
    cin>>g>>e;
    vector<vector<int> > v(g);
    int a,b;
    for(int i=0;i<e;i++)
    {
       cin>>a>>b;
       v[b].push_back(a);
       v[a].push_back(b);
    }
    countt=0;
    for(int i=0;i<g;i++)
    {
        
        dfs(v,g,i);
        //cout<<countt<<endl;
    }
    cout<<countt/6;
   
  return 0;
}
