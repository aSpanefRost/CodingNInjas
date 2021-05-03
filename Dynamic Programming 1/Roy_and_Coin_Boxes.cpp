// Roy and Coin Boxes
// Send Feedback
// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.

// After M days, Roy has a query: How many coin boxes have atleast X coins.
// He has Q such queries.
// Input
// First line contains N - number of coin boxes.
// Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.a
// Output
// For each query output the result in a new line.
// Constraints
// 1 ≤ N ≤ 1000000

// 1 ≤ M ≤ 1000000

// 1 ≤ L ≤ R ≤ N

// 1 ≤ Q ≤ 1000000

// 1 ≤ X ≤ N
// Sample Input
// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2
// Sample Output
// 6
// 0
// 0
// 4



#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
 
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;
 
 
 


int main()
{   
    
    
    
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=0;i<=n;i++)
    {
       v[i]=0;
    }
    int t;
    cin>>t;
    int a,b;
    while(t--)
    {
       cin>>a>>b;
       v[a]++;
       if(b<n) v[b+1]--;
    }
    //fo(i,n) cout<<v[i+1]<<" ";
    //cout<<endl;
    for(int i=2;i<=n;i++) v[i]+=v[i-1];
    //fo(i,n) cout<<v[i+1]<<" ";
    //cout<<endl;
    //sort(v.begin(),v.end());
    lli arr[1000002];
    mem(arr,0);
    for(int i=1;i<=n;i++)
    {
    	arr[v[i]]+=1;
    	//cout<<arr[v[i]]<<" ";
    	//cout<<v[i]<<" ";
    }
    //cout<<endl;
    //  for(int i=1;i<=1000001;i++)
    // {
    // 	cout<<arr[i]<<" ";
    // }
    //cout<<endl;
    for(int i=1000000;i>=1;i--)
    {
        arr[i]+=arr[i+1];
    }


    int q;
    cin>>q;
    int tem;
    //cout<<endl;
    while(q--)
    {
    	cin>>tem;
    	cout<<arr[tem]<<endl;
    }

}



#include <iostream> #include <cstdio> using namespace std; long int days[1000001]; long int strt[1000001], en[1000001], ans[1000001]; int main() { ios_base::sync_with_stdio(false); cin.tie(0); long int n, m, x, q, l, r, i, c=0; cin>>n>>m; for(i=0;i<m;i++) { cin>>l>>r; strt[l]++;//noting the times the starting box was kth box en[r]++;//noting the times the ending box was kth box } for(i=1;i<=n;i++) { c+=strt[i]; days[i]=c;//number of coins in a box is same as number of days the coin was put in the box c-=en[i]; } //now calculate how many boxes have exact i coins for(i=1;i<=n;i++) ans[days[i]]++; /*now calculate how many boxes have atleast i coins which is same as number of boxes having atleast i+1 coins + number of boxes having exact i coins Note: box with atleast max coins is same as box with exact k coins In other words we can take max as n and start iterating from n-1*/ for(i=n-1;i>0;i--) { ans[i]=ans[i]+ans[i+1]; } cin>>q; while(q--) { c=0; cin>>x; cout<<ans[x]<<endl; } return 0; }
