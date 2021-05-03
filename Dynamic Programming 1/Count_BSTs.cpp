// Count BSTs
// Send Feedback
// Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
// Output count can be very large, so return the count modulo 10^9+7.
// Input Format :
// Integer n 
// Output Format :
// Count of BSTs
// Contraints :
// 1<= N <=1000
// Sample Input 1:
// 8
// Sample Output 1:
// 1430
// Sample Input 2:
// 3
// Sample Output 2:
// 5


const int mod=1000000007;
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    long long int ans[n+1];
    if(n==1) return 1;
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=n;i++) ans[i]=0;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ans[i]+=((ans[j-1]%mod)*(ans[i-j]%mod))%mod;
        }
    }
    //for(int i=1;i<n;i++)  cout<<ans[i]<<" ";
    
    return ans[n]%mod;
}


