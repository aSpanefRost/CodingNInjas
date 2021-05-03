// Miser Man
// Send Feedback
// Jack is a wise and miser man. Always tries to save his money.
// One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
// 1. At every city, he has to change the bus.
// 2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
// You are to help Jack to go from A to B by spending the minimum amount of money.
// N, M, K <= 100.
// Input
// Line 1:    N M

// Line 2:    NxM Grid

// Each row lists the fares the M busses to go form the current city to the next city.
// Output
// Single Line containing the minimum amount of fare that Jack has to give.
// Sample Input
// 5 5
// 1  3  1  2  6
// 10 2  5  4  15
// 10 9  6  7  1
// 2  7  1  5  3
// 8  2  6  1  9
// Sample Output
// 10
// Explanation:
// 1 -> 4 -> 1 -> 3 -> 1: 10
// This is marked and shown in the following image: 


#include<bits/stdc++.h>
using namespace std;

int save[105][105];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&save[i][j]);
	int res[n][m];
	for(i=0;i<m;i++)
		res[0][i]=save[0][i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int l,u,r;
			l=(j>0)?(res[i-1][j-1]):INT_MAX;
			u=res[i-1][j];
			r=(j<m-1)?res[i-1][j+1]:INT_MAX;
			res[i][j]=save[i][j]+min(u,min(l,r));
		}
	}
	int ans=INT_MAX;
	for(i=0;i<m;i++)
		if(res[n-1][i]<ans)
			ans=res[n-1][i];
	printf("%d",ans);
	return 0;
}
