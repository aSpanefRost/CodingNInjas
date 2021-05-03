// Winning Lottery
// Send Feedback
// Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
// Input Format
// The Input line contains two space-separated integers: S,D
// Output Format
// The output contains a single integer denoting the winning lottery number
// Constraints
// 1 <= D <= 1000
// 1 <= S <= 9*D
// Time Limit: 1 second
// Sample Input1:
// 9 2
// Sample Output1:
// 18
// Explanation
// There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.


#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
 
#define fo(i,n) for(lli i=0;i<n;i++)
#define vi vector<lli>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const lli mod=1000000007;
 
using namespace std;




int main()
{   
    
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
    
  int s,d;
    cin>>s>>d;
    int arr[d];
    arr[0]=1;
    for(int i=1;i<d;i++)
    {
        arr[i]=0;
    }
    s-=1;
    int num=s/9;
    int extra=s%9;
    for(int i=d-1;i>d-1-num;i--)
    {
        arr[i]+=9;
    }
    arr[d-1-num]+=extra;
    for(int i=0;i<d;i++)
    {
        cout<<arr[i];
    }
  
  
   
}
