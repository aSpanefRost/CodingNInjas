// Collecting the balls
// Send Feedback
// There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container.
// Input Format:
// The Only line of input contains a single integer ‘n’.

// Output Format:
// Print a single integer denoting the minimal value of ‘k’.
// Constraints:
// 1 <= n <= 10^18
// Time Limit: 1 second
// Sample Input:
// 68
// Sample Output:
// 3
// Explanation:
// 68-3 = 65; 65/10 = 6; 65-6 = 59
// 59-3 = 56; 56/10 = 5; 56-5 = 51
// 51-3 = 48; 48/10 = 4; 48-4 = 44
// 44-3 = 41; 41/10 = 4; 41-4 = 37
// …..
// …..
// …..
// 6-3 = 3; 3/10 = 0; 3-0 = 3
// 3-3 = 0; 0/10 = 0; 0-0 = 0


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

bool is_possible(lli n,lli mid)
{
   int a=0;
   int b=0;
   int temp;
     //
   while(1)
   {
       if(n<=0) break;
       a+=min(n,mid);
       //out<<min(n,mid)<<" ";
       n-=min(mid,n);
       if(n<=0) break;
       b+=n/10;
       //cout<<n/10<<" ";
       n-=n/10;
       //cout<<n<<endl;
   }
  //cout<<mid<<" "<<a<<" "<<b<<" "<<endl;
   if(a>=b) return true;
   else return false; 
}

lli collecting_the_balls(lli n,lli s,lli f)
{  
   //cout<<n<<" "<<s<<" "<<f<<endl;
   if(s>f) return -1;
   lli mid=(f+s)/2;
   if(is_possible(n,mid))
   {
      lli a=collecting_the_balls(n,s,mid-1);
      //cout<<a<<endl;
      if(a==-1) return mid;
      return a;
   }
   else
   {
       return collecting_the_balls(n,mid+1,f);
   }
}


int main()
{
 
    
    
    lli n;
    cin>>n;
    cout<<collecting_the_balls(n,1,n);

   // cout<<is_possible(42,1);
    
}
