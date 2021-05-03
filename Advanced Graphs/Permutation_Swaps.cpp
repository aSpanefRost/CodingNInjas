// Permutation Swaps
// Send Feedback
// Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

// Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

// Swap Px and Py only if (x, y) is a good pair.
// Help him and tell if Kevin can obtain permutation Q using such operations.
// Input format:
// The first line of input will contain an integer T, denoting the number of test cases.

// Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
// Output format:
// For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
// Constraints:
// 1 ≤ T ≤ 10
// 2 ≤ N ≤ 100000
// 1 ≤ M ≤ 100000
// 1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
// 1 ≤ ai < bi ≤ N
// SAMPLE INPUT
// 2
// 4 1
// 1 3 2 4
// 1 4 2 3
// 3 4
// 4 1
// 1 3 2 4
// 1 4 2 3
// 2 4
// SAMPLE OUTPUT
// NO 
// YES


//https://codeforces.com/problemset/page/2?tags=1500-1600
#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<queue>
using namespace std;
 
#define fo(i,l,r) for(int i=l;i<r;i++)
#define vi vector<int>
#define lli long long int
#define int long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

const int maxn=150005;

vector<vector<int> > connected_components;
vector<int> temp;
void dfs(vector<int> v[],int n,int ver,bool visited[])
{
  visited[ver]=true;
  temp.push_back(ver);
  for(auto x: v[ver])
  {
      
      if(!visited[x])
      {
        dfs(v,n,x,visited);
        //temp.push_back(x);
      }
  }
  return;
  // connected_components.push_back(temp);
  // temp.clear();

}

void solve()
{
    int n,q;
    cin>>n>>q;
    int arr1[n];
    int arr2[n];
    for(int i=1;i<=n;i++) cin>>arr1[i];
    for(int i=1;i<=n;i++) cin>>arr2[i];
    vector<int> v[n+1];
    int a,b;
    while(q--)
    {
       cin>>a>>b;
       v[a].push_back(b);
       v[b].push_back(a);
    }
    bool visited[n+1];
    mem(visited,false);
    for(int i=1;i<=n;i++)  {if(!visited[i])   
      {
        dfs(v,n,i,visited);
        connected_components.push_back(temp);
        temp.clear();
      }
    }
     
    set<int> s1;
    set<int> s2;
    bool check=false;
    for(auto x:connected_components)
    {
       s1.clear();
       s2.clear();
       for(auto y:x)
       {
         // cout<<y<<" ";
          s1.insert(arr1[y]);
          s2.insert(arr2[y]);
       }
       auto ip=s2.begin();
       for(auto it=s1.begin();it!=s1.end();it++,ip++)
        {
           if(*it!=*ip)
           {
             check=true;
           }
          // cout<<*it<<" "<<*ip<<endl;
        }
       if(check) {cout<<"NO"<<endl;connected_components.clear();return;}

       //cout<<endl;

     }
     cout<<"YES"<<endl;
     connected_components.clear();
     return;
    
  
}  

 
signed main()
{
    
   
    
    int t;
    t=1;
    cin>>t;
     while(t--)
     {
        connected_components.clear();
        temp.clear();
        solve();
     }
    
  return 0;
}
