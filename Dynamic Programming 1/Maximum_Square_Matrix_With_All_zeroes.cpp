// Maximum Square Matrix With All Zeros
// Send Feedback
// Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
// Input format :
// The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

// Second-line onwards, the next 'N' lines or rows represent the ith row values.

// Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
// Output Format:
// Print the size of maximum square sub-matrix.
//  Constraints :
// 0 <= N <= 10^4
// 0 <= M <= 10^4

// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 1 1 0
// 1 1 1
// 1 1 1
// Sample Output 1:
// 1
// Sample Input 2:
// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// Sample Output 2:
// 4


int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    int ans[n][m];
    int an=0;
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]==1) ans[0][i]=0;
        else ans[0][i]=1;
        if(ans[0][i]>an) an=ans[0][i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==1) ans[i][0]=0;
        else ans[i][0]=1;
        if(ans[i][0]>an) an=ans[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==1) ans[i][j]=0;
            else ans[i][j]=min(min(ans[i-1][j-1],ans[i][j-1]),ans[i-1][j])+1;
            if(ans[i][j]>an) an=ans[i][j];
        }
    }
    
    return an;
    
    
}
