// Subset Sum - Problem
// Send Feedback
// You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.
// Input Format
// The first line of the test case contains an integer 'N' representing the total elements in the set.

// The second line of the input contains N integers separated by a single space.    

// The third line of the input contains a single integer, denoting the value of K.
// Output Format
// Output Yes if there exists a subset whose sum is k, else output No.
// Constraints :
// 1 <= N <= 10^6
// 1 <= a[i] <= 10^3, where a[i] denotes an element of the set 
// 1 <= K <= 10^3

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 4 3 5 2
// 13
// Sample Output 1 :
// No
// Sample Input 2 :
// 5
// 4 2 5 6 7
// 14
// Sample Output 2 :
// Yes


bool isSubsetPresent(int *arr, int n, int sum)
{
    //Write your code here
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++) dp[i][0]=true;
    for(int j=1;j<=sum;j++) dp[0][j]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
             }
        }
    }
    return dp[n][sum];
}  
