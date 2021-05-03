// Boredom
// Send Feedback
// Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
// He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
// Input Format :
// Line 1 : Integer N 
// Line 2 : A list of N integers
// Output Format :
// Maximum points Gary can recieve from the Game setup
// Constraints :
// 1<=N<=10^5
// 1<=A[i]<=1000
// Sample Input :
// 2
// 1 2
// Sample Output :
// 2

#include<algorithm>
#include<vector>
int solve(int n,vector<int>A){
    long long int ans[1001];
    for(int i=0;i<=1000;i++)
    {
        ans[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        ans[A[i]]+=A[i];
    }
    long long int an=0;
    int i;
    for(i=1000;i>=4;)
    {
        if(ans[i-1]>ans[i-2]+ans[i]) 
        {
            an+=ans[i-1];
            i=i-3;
        }
        else
        {
            an+=ans[i];
            i=i-2;
        }
    }
    if(i==1) return an+ans[1];
    else return an+max(ans[1],ans[2]);
    
}
