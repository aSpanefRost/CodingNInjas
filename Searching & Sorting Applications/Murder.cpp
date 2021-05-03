// Murder
// Send Feedback
// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input
// First line gives T, number of test cases.

// 2T lines follow.

// First line gives you the number of stairs N

// Next line gives you N numbers written on the stairs.
// Output
// For each test case output one line giving the final sum for each test case.
// Constraints
// T<=10

// 1<=N<=10^5

// All numbers will be between 0 and 10^6.
// Sample Input:
// 1
// 5
// 1 5 3 6 4
// Sample Output:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).


#include<bits/stdc++.h>

#define fo(i,n) for(int i=0;i<n;i++)
#define lli long long int
using namespace std;
lli ans;

void merge(lli arr[],int s,int mid,int e)
{
   int n1=mid-s+1;
   int n2=e-mid;
   lli L[n1];
   lli R[n2];
   fo(i,n1)
   {
     L[i]=arr[s+i];
   }
   fo(j,n2)
   {
     R[j]=arr[mid+1+j];
   }
   int i=0;
   int j=0;
   int k=s;
   while(i<n1&&j<n2)
   {
     if(L[i]<R[j]) {ans+=L[i]*(n2-j);arr[k]=L[i];k++;i++;}
     else
     {
        arr[k]=R[j];
        k++;
        j++;
     }

   }
   while(i<n1)
   {
      arr[k]=L[i];
      i++;
      k++;
   }
   while(j<n2)
   {
    arr[k]=R[j];
    j++;
    k++;
   }
   // for(i=s;i<=e;i++)
   // {
   //  cout<<arr[i]<<" ";
   // }
   // de(ans);
   // cout<<endl;
}

void Murder(lli arr[],int s,int e)
{
  if(e<=s) return;
  int mid=(e+s)/2;
  Murder(arr,s,mid);
  Murder(arr,mid+1,e);
  //de(54);
  merge(arr,s,mid,e);
}


int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      lli arr[n];
      fo(i,n) cin>>arr[i];
      ans=0;
      Murder(arr,0,n-1);
      cout<<ans<<endl;
      //fo(i,n) cout<<arr[i]<<" ";
    }
 
    
    return 0;
}
