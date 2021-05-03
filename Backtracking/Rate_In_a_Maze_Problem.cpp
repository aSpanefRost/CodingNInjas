// Rat In A Maze Problem
// Send Feedback
// You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
// Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
// Input Format
// The first line of input contains an integer 'N' representing 
// the dimension of the maze.
// The next N lines of input contain N space-separated 
// integers representing the type of the cell.
// Output Format :
// For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

// Output for every test case will be printed in a separate line.
// Constraints:
// 0 < N < 11 0 <= Maze[i][j] <=1

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 
// Sample Output 1 Explanation :
// Only 1 path is possible

// 1 0 0
// 1 0 0
// 1 1 1
// Which is printed from left to right and then top to bottom in one line.

// Sample Input 2 :
// 3
// 1 0 1
// 1 1 1
// 1 1 1
// Sample Output 2 :
// 1 0 0 1 1 1 1 1 1 
// 1 0 0 1 0 0 1 1 1 
// 1 0 0 1 1 0 0 1 1 
// 1 0 0 1 1 1 0 0 1 
// Sample Output 2 Explanation :
// 4 paths are possible which are printed in the required format.



#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<sstream>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

int ans[20][20];

void print(int n)
{
  fo(i,n) fo(j,n) cout<<ans[i][j]<<" ";
  cout<<endl;
}

void path(int maze[][20],int n,int row,int col)
{
    
    if(row==n-1&&col==n-1) {ans[row][col]=1;print(n);ans[row][col]=0;return;}
    if((maze[row][col]==0)||(ans[row][col]==1)||row<0||col<0||row>=n||col>=n) return;
    
    ans[row][col]=1;
    path(maze,n,row,col+1);
    // if(row<0||col+1<0||row>=n||col+1>=n) ;
    // else ans[row][col+1]=0;
    path(maze,n,row+1,col);
    // if(row+1<0||col<0||row+1>=n||col>=n) ;
    // else ans[row+1][col]=0;
    path(maze,n,row,col-1);
    // if(row<0||col-1<0||row>=n||col-1>=n) ;
    // else ans[row][col-1]=0;
    path(maze,n,row-1,col);
    // if(row-1<0||col<0||row-1>=n||col>=n) ;
    // else ans[row-1][col]=0;
    ans[row][col]=0;

}

void ratInAMaze(int maze[][20],int n)
{
    memset(ans,0,sizeof(ans));
    path(maze,n,0,0);
}
