// N-Queen Problem
// Send Feedback
// You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Input Format :
// Line 1 : Integer N
// Output Format :
// One Line for every board configuration. 
// Every line will have N*N board elements printed row wise and are separated by space
// Note : Don't print anything if there isn't any valid configuration.
// Constraints :
// 1<=N<=10
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 



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
int board[11][11];  

bool is_Possible(int n,int row,int col)
{
    //check in the column
    for(int i=0;i<row;i++)
    {
      if(board[i][col]==1) return false;
    }
    //check in the upper left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
      if(board[i][j]==1) return false;
    }
    //Check in the upper- right diagonal
    
   for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++)
   {
    if(board[i][j] == 1)
    {
      return false;
    }
   }
  
  return true;

}

void nQueenHelper(int n,int row)
{
  if(n==row)
  {
    fo(i,n) 
      fo(j,n) cout<<board[i][j]<<" ";
    cout<<endl; 
    return; 
  }
  for(int i=0;i<n;i++)
  {
     if(is_Possible(n,row,i))
     {
        board[row][i]=1;
        nQueenHelper(n,row+1);  //going next row
        board[row][i]=0; //going to the next column in the same row
     }
  }
  
}

void placeNQueens(int n)
{
    memset(board,0,sizeof(board));
    nQueenHelper(n,0);
}

