// Code : Has Path
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= 1000
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
// true
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false


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
int start,finish;
bool check=false;
void dfs(vector<int> ar[],int N,int s,int visited[])
{
	visited[s]=1;
	if(s==finish) check=true;
	for(int x:ar[s])
	{
		if(visited[x]==0)
		{
			visited[x]=0;
			dfs(ar,N,x,visited);
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
    vector<int> ar[N];
    int a,b;
    for(int i=0;i<M;i++)
    {
       cin>>a>>b;
       ar[a].push_back(b);
       ar[b].push_back(a);
    }
    cin>>start>>finish;
    int visited[N+1];
	for(int i=0;i<N;i++) visited[i]=0;
    dfs(ar,N,start,visited);
    if(check) cout<<"true";
    else cout<<"false";
    return 0;
}
