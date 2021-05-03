// Largest Piece
// Send Feedback
// It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
// Input Format :
// The first line of input contains an integer, that denotes the value of N. 
// Each of the following N lines contain N space separated integers.
// Output Format :
// Print the count of '1's in the biggest piece of '1's, according to the description in the task.
// Constraints :
// 1 <= N <= 1000
// Time Limit: 1 sec
// Sample Input 1:
// 2
// 1 1
// 0 1
// Sample Output 1:
// 3

#include<queue>
using namespace std;
const int N=1000;
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int bfs(vector<vector<int>> &cake,int n,int x,int y,int visited[][N])
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    int ans=1;
    int i;
    int j;
    while(!q.empty())
    {
        pair<int,int>  cur=q.front();
        q.pop();
        i=cur.first;
        j=cur.second;
        if(visited[i][j-1]==0&&j-1>=0&&cake[i][j-1]==1)
        {
           visited[i][j-1]=1;
            ans++;
            q.push(make_pair(i,j-1));
        }
         if(visited[i][j+1]==0&&j+1<=n-1&&cake[i][j+1]==1)
        {
            visited[i][j+1]=1;
            ans++;
            q.push(make_pair(i,j+1));
        }
        if(visited[i+1][j]==0&&i+1<=n-1&&cake[i+1][j]==1)
        {
            visited[i+1][j]=1;
            ans++;
            q.push(make_pair(i+1,j));
        }
        if(visited[i-1][j]==0&&i-1>=0&&cake[i-1][j]==1)
        {
            visited[i-1][j]=1;
            ans++;
            q.push(make_pair(i-1,j));
        }
        
    }
   // cout<<ans<<" *";
    return ans;
}



int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int visited[N][N];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) visited[i][j]=0;
        int ans=0;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {    
        if(visited[i][j]==0&&cake[i][j]==1)
        {
           int tem=bfs(cake,n,i,j,visited);
              // cout<<ans<<" "<<tem;
           ans=max(ans,tem);
        }
       }    
    }  
    return ans;
}
