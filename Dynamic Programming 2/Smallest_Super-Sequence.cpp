// Smallest Super-Sequence
// Send Feedback
//  Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
//  The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
// Note :
// If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
// Input Format:
// The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
// Output Format:
// Length of the smallest super-sequence of given two strings. 
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1 sec
// Sample Input 1 :
// ab
// ac
// Sample Output 1 :
// 3
// Explanation of Sample Output 1 :
// Their smallest super sequence can be "abc" which has length = 3.
// Sample Input 2 :
// pqqrpt
// qerepct
// Sample Output 2 :
// 9



int smallestSuperSequence(string str1, string str2)
{
	//Write your code here
    int m=str2.size();
    int n=str1.size();
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][m];
}
