// Loot Houses
// Send Feedback
// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input format :
// The first line of input contains an integer value of 'n'. It is the total number of houses.

// The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
// Output format :
// Print the the maximum money that can be looted.
// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec
// Sample Input 1 :
// 6
// 5 5 10 100 10 5
// Sample Output 1 :
// 110
// Sample Input 2 :
// 6
// 10 2 30 20 3 50
// Sample Output 2 :
// 90
// Explanation of Sample Output 2 :
// Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.


int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    //Can we choose the
    if(n==0) return 0;
    int ans[n];
    for(int i=0;i<3;i++)
    {
        ans[i]=arr[i];
        if(i==2) ans[i]+=arr[0];
    }
    for(int i=3;i<n;i++)
    {
        ans[i]=max(ans[i-2],ans[i-3]);
        ans[i]+=arr[i];
    }
    if(n>=2)return max(ans[n-1],ans[n-2]);
    return ans[0];
    
}
