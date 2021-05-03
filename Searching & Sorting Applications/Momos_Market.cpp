// Momos Market
// Send Feedback
// Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
// Input Format:
// First line will have an integer ‘n’ denoting the number of shops in market.
// Next line will have ‘n’ numbers denoting the price of one momo of each shop.
// Next line will have an integer ‘q’ denoting the number of days she will visit the market.
// Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
// Constraints:
// 1 <= n <= 10^5
// 1 <= q <= 10^5
// 1 <= X <= 10^9
// Output:
// There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
// Sample Input:
// 4
// 2 1 6 3
// 1
// 11
// Sample Output:
// 3 2
// Explanation:
// Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.


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



int main()
{
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int n;
    cin>>n;
    vi v(n);
    int x;

    cin>>x;
    v[0]=x;

    fo(i,n-1)
    {
      cin>>x;
      v[i+1]=v[i]+x;
    }
    
    int t,q;
    cin>>t;
    while(t--)
    {
       cin>>q;
       auto it=lower_bound(v.begin(),v.end(),q);
       if(*it!=q)
       cout<<it-v.begin()<<" "<<q-*(it-1)<<endl;
       else cout<<it-v.begin()+1<<" "<<q-*it<<endl;

    }
    
 
    
    return 0;
    
}
