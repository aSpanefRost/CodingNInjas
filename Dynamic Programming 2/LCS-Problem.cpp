// LCS - Problem
// Send Feedback
// Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
// For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
// Example :
// Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
// Input format :
// The first line of input contains the string S of length M.

// The second line of the input contains the String T of length N.
// Output format :
// Print the length of the 'Longest Common Subsequence'.
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1sec
// Sample Input 1 :
// adebc
// dcadb
// Sample Output 1 :
// 3
// Explanation of the Sample Input 1 :
// Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
// Sample Input 2 :
// ab
// defg
// Sample Output 2 :
// 0
// Explanation of the Sample Input 2 :
// The only subsequence that is common to both the given strings is an empty string("") of length 0.


int lcs(string s, string t)
{
	//Write your code here
    int n=s.length();
    int m=t.length();
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
                
        }
    }
    
    return dp[n][m];
}
