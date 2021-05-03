// Pair sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
// Input format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.
// Output format :
// The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
// Constraints :
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 2 1 -2 2 3
// Sample Output 1:
// 2


#include<algorithm>
int pairSum(int *arr, int n) {
	// Write your code here
    int pos=-1;
    int zero=0;
    int ans=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {   
        if(arr[i]==0) zero++;
        else if(arr[i]>0) {pos=i;break;}
    }
    int neg=pos-1-zero;
    //cout<<pos<<" "<<neg<<endl;
    int j=pos;
    int check;
    int check1;
    int al;
    int k;
    for(int i=0;i<=neg;i++)
    {   
        al=0;
        for(k=i+1;k<=neg;k++)
        {
            if(arr[i]==arr[k])al++;
            else break;
        }
        i=k;
        cout<<"*"<<al;
        check1=j;
         check=ans;
        for(;j<n;j++)
        {
            if(arr[j]==-arr[i]) ans++;
            else if(arr[j]<-arr[i]);
            else break;
        }
        j=check1;
        cout<<" "<<check<<" "<<ans<<endl;
        ans+=al*(ans-check);
    }
    ans+=zero*(zero-1)/2;
    return ans;

}
