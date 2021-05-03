// Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
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
// 1 2 1
// 0 1 3
// 0 3 5

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

typedef struct 
{
    int src;
    int des;
    int weight;
}Edge;
 
bool func(Edge a,Edge b)
{
    return a.weight<b.weight;
}
//what is parent of ith element
int find(int i,int parent[])
{
    while(1)
    {
       if(i==parent[i]) 
       {
          return i;
       }
       else 
       {
         i=parent[i];
       }
    }
}
//here we
void union1(int a,int b,int parent[])
{
    int x=find(a,parent);
    int y=find(b,parent);
    if(x==y) return;
    else parent[x]=y;
}  


int main()
{

   
    int v,e;
    cin>>v>>e;
    Edge arr[e];
    int a,b,c;
    for(int i=0;i<e;i++)
    {
      cin>>a>>b>>c;
      arr[i].src=a;
      arr[i].des=b;
      arr[i].weight=c;
    }
    sort(arr,arr+e,func);
    // for(int i=0;i<e;i++)
    // {
    //     cout<<arr[i].weight<<endl;
    // }
    int parent[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    //Kruskal's algorithm
    int count=0;
    int i=0;
    while(count!=v-1)
    {
        if(find(arr[i].src,parent)!=find(arr[i].des,parent))
        {
            union1(arr[i].src,arr[i].des,parent);
            count++;
            if(arr[i].src>arr[i].des) cout<<arr[i].des<<" "<<arr[i].src<<" "<<arr[i].weight<<endl;
            else cout<<arr[i].src<<" "<<arr[i].des<<" "<<arr[i].weight<<endl;
        }
        i++;
    }

    return 0;

}
