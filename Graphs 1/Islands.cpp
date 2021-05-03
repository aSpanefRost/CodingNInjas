// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
// Output Format :
// Print the count the number of connected groups of islands
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V-1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 5 8
// 0 1
// 0 4
// 1 2
// 2 0
// 2 4
// 3 0
// 3 2
// 4 3
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

void bfs(vector<vector<int> > v,int g,int vis[],int i)
{
     //vector<int> ans; 
     queue<int> q;
     int cur=i;
     q.push(cur);
     //ans.push_back(cur);
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
                //ans.push_back(x);
            }
        }

     }
    // return ans;

}

int main() {

    
    
    int g,e;
    cin>>g>>e;
    vector<vector<int> > v(g);
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
   // for(int i=0;i<g;i++) sort(v[i].begin(),v[i].end());
    
    int vis[g];
    for(int i=0;i<g;i++) vis[i]=0;
    int ans=0;
    for(int i=0;i<g;i++)
    {    
       if(vis[i]==0) 
        {
            bfs(v,g,vis,i);
            //sort(ans.begin(),ans.end());
            // for(int x: ans)
            // {
            //     cout<<x<<" ";
            // }
            ans++;
           
        }    

    } 
    cout<<ans;
  
 
    return 0;  
    
}



