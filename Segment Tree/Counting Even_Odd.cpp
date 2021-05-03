// Counting Even/Odd
// Send Feedback
// Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0 :- modify the element present at index i to x.
// Query 1:- count the number of even numbers in range l to r inclusive.
// Query 2:- count the number of odd numbers in range l to r inclusive.
// Input:
// First line of the input contains the number N. Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.

// 0 x y - modify the number at index x to y. 

// 1 x y - count the number of even numbers in range l to r inclusive.

// 2 x y - count the number of odd numbers in range l to r inclusive.
// Constraints:
// 1<=N,Q<=10^5

// 1<=l<=r<=N 

// 0<=Ai<=10^9

// 1<=x<=N

// 0<=y<=10^9
// Note:-
// indexing starts from 1.
// Sample Input
// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6
// Sample Output
// 2
// 2
// 4


#include<bits/stdc++.h>
using namespace std;

int arr[100001];  
int st[400001];     //Array to store the segment tree
int lazy[400001];   //Array to store the lazy tree

//Function to buid the tree-- Complexity=O(n)
void buildTree(int si, int ss,int se)
{
   if(ss==se)
   {
     st[si]=arr[ss]%2;
     return;
   }

   int mid=(ss+se)/2;
   buildTree(2*si,ss,mid);
   buildTree(2*si+1,mid+1,se);

   st[si]=st[2*si]+st[2*si+1];
}

//Funtion to find the min value in a given range-- Complexity=O(logn)
int query(int si,int ss,int se,int qs,int qe)
{   

    //Extra code fore Lazy propagation-  When range query is not needed
    //remove the following code 
    /*
     if(lazy[si]!=0)
     {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx;
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
     }

     */
    if(qe<ss||qs>se)
    {
      return 0;           //No Overlap
    }
    if(qs<=ss&&qe>=se)
    {
      return st[si];       //Complete Overlap
    }
                           
                           //Partial Overlap
    int mid=(ss+se)/2;
    int l=query(2*si , ss, mid, qs,qe);
    int r=query(2*si+1, mid+1, se, qs , qe);
    return (l+r);
}


//Funtion to update at a particular position-- Complexity=O(logn)
void point_update(int si, int ss,int se, int qi)
{
  if(ss==se)
  {
    st[si]=arr[ss]%2;  //Update the leaf node 
    return;
  }

  int mid=(ss+se)/2;
  if(qi<=mid) point_update(2*si,ss,mid,qi);
  else point_update(2*si+1,mid+1,se,qi);

  st[si]=st[2*si]+st[2*si+1];

}

//Range_update using lazy propagation
//Complexity=O(logn)
void range_update(int si, int ss, int se, int qs, int qe, int val)
{
    //handling pending updates
     

    if(lazy[si]!=0)
     {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx;
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
     }
    //No Overlap
    if(qe<ss||qs>se) return;
    
    //Complete Overlap
    if(qs<=ss&&qe>=se)
    {
       int dx=val;
       st[si]+=dx;
       if(ss!=se)
       {
        lazy[2*si]+=val;
        lazy[2*si+1]+=val;
       }
       return;

    }
     
     //partial overlap
    int mid=(ss+se)/2;
    range_update(2*si,ss,mid,qs,qe,val);
    range_update(2*si+1,mid+1,se,qs,qe,val);

    st[si]=min(st[2*si],st[2*si+1]);

}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int q;
    cin>>q;
    int a,b,c;
    buildTree(1, 1,n);
    //for(int i=1;i<=13;i++) cout<<st[i]<<" ";
   // cout<<endl;
    while(q--)
    {
        cin>>a>>b>>c;
        if(a==0)
        {
            arr[b]=c;
            point_update(1, 1,n, b);
        }
        else if(a==1)
        {
           
             cout<<(c-b+1)-query(1,1,n,b,c)<<endl;
        }
        else
        {
           cout<<query(1,1,n,b,c)<<endl;
        }
    }
    return 0;
}
