// Circular List of Students
// Send Feedback
// You are given a circular list of students as follows:
// 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
// This list is circular, means that 11 will follow 0 again. You will be given the student number ‘i’ and some position ‘p’. You will have to tell that if the list will start from (i+1)th student, then which student will be at pth position.
// Input Format:
// First line will have an integer ‘t’, denoting the number of test cases.
// Next line will have two space separated integers denoting the value of ‘i’ and ‘p’ respectively.
// Output Format:
// Print ‘t’ lines containing single integer denoting the student number.
// Constraints:
// 1 <= t <= 10^5
// 0 <= i <= 11
// 1 <= p <= 12
// Sample Input:
// 2
// 2 3
// 5 8
// Sample Output:
// 5
// 1
// Explanation:
// First, list will start at 3. 3 -> 4 -> 5. Hence, 5 will be at third position.
// Second, list will start at 6. 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 0 -> 1. Hence, 1 will be at 8th position.

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

int num=12;

int main()
{
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
     
    int t;
    cin>>t;
    while(t--)
    {
      int i,p;
      cin>>i>>p;
      int temp=p%num;
      if((i+temp)-12>=0) cout<<(i+temp)-12<<endl;
      else cout<<(i+temp)<<endl;  
    }
    
}
