// Activity Selection
// Send Feedback
// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

// Output
// Output one integer, the maximum number of activities that can be performed
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Sample Input
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output
// 4

#include<bits/stdc++.h>
using namespace std;

bool func(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    int a,b;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),func);
    pair<int,int>p;
    p.first=v[0].first;
    p.second=v[0].second;
    
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>=p.second)
        {
            ans++;
            p.first=v[i].first;
            p.second=v[i].second;
        }
    }
    cout<<ans;  
    return 0;
}
