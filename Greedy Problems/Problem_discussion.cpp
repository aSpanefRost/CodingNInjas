// Problem discussion
// Send Feedback
// Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
// It seems difficult for Aahad so he asked for your help
// Input Format
// The First line contains two space-separated integers: N,K
// Next lines contain N space-separated integers denoting elements of the array
// Output Format
// The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
// Constraints
// 1 =< N <= 10^5 
// 1 <= Ai,K <= 10^9
// Sample Input1:
// 3 6
// 1 15 10
// Sample Output1:
// 5
// Explaination
// We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.


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
    
    int n,k;
    cin>>n>>k;
    vector<int> v;
    int tem;
    for(int i=0;i<n;i++)
    {
        cin>>tem;
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    auto it=lower_bound(v.begin(),v.end(),k);
    // for(int x:v) cout<<x<<" ";
    // 	cout<<endl;
    for(auto ip=v.begin();ip!=it;ip++)
    {
        *ip=*ip+k;
    }
    for(auto ip=it+1;ip!=v.end();ip++)
    {
        *ip=*ip-k;
    }
    // for(int x:v) cout<<x<<" ";
    // 	cout<<endl;
    int one=*it;
    v.erase(it);
    // for(int x:v) cout<<x<<" ";
    // 	cout<<endl;
    vector<int> ans;
    ans.push_back(v[0]);
    ans.push_back(*(v.end()-1));
    ans.push_back(one-k);
  //  ans.push_back(one+k);
    sort(ans.begin(),ans.end());
    int ans11=ans[2]-ans[0];
    ans.clear();
    ans.push_back(v[0]);
    ans.push_back(*(v.end()-1));
    ans.push_back(one+k);
    sort(ans.begin(),ans.end());
    int ans22=ans[2]-ans[0];
    cout<<min(ans11,ans22);
    

  
  
   
}
