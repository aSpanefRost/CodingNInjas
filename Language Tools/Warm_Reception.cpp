// Warm Reception
// Send Feedback
// There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
// She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.
// Input Format :
// First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.
// Constraints:
// 1<= N <= 100
// Arrival and departure timings lie in the range [0000 to 2359]
// Time Limit: 1 second
// Output Format :
// You have to print the minimum number of chairs required such that no customer has to wait standing. 
// Sample Test Cases:
// Sample Input 1 :
// 5
// 900 1000 1100 1030 1600
// 1900 1300 1130 1130 1800
// Sample Output 1:
// 4
// Explanation:
// 4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4. 


#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef struct T
{
  int s;
  int f;
} tim;

bool compare(tim a,tim b)
{
  if(a.s==b.s) return a.f<b.f;
  return a.s<b.s;
}
bool intersect(int a,int b,int c,int d)
{
  if(a<=c&&c<b) return true;
  return false;
}

int main()
{
    int n;
    cin>>n;

    tim arr[n];
    fo(i,n)
    {
      cin>>arr[i].s;
    }
    fo(i,n)
    {
      cin>>arr[i].f;
    }
    sort(arr,arr+n,compare);
    vector<tim> v;
    v.push_back(arr[0]);
    int ans=1;
    for(int i=1;i<n;i++)
    {  
       bool a=false;
       for(auto it=v.begin();it!=v.end();it++)
       {
         if(!intersect(it->s,it->f,arr[i].s,arr[i].f))
         {
            it->f=arr[i].f;
            a=true;
            break;
         }
        
       }
       if(!a) {ans++;v.push_back(arr[i]);}
    }
    cout<<ans;

    return 0;
    
}
