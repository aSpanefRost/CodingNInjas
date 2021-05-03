// Triplet sum
// Send Feedback
// You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'X'.
// Output format :
// For each test case, print the total number of triplets present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= X <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7 
// 12
// Sample Output 1:
// 5
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7 
// 19
// 9
// 2 -5 8 -6 0 5 10 11 -3
// 10
// Sample Output 2:
// 0
// 5


//  Explanation for Input 2:
// Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

// For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)


int tripletSum(int *arr, int n, int num)
{
  //Write your code here
    int temp;
    int ans=0;
    int t_sum;
    sort(arr,arr+n);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n-2;i++)
    {   
        int temp=num-arr[i];
        int x=i+1;
        int y=n-1;
        while(1)
        {
            if(x>=y) break;
            t_sum=arr[x]+arr[y];
            if(t_sum>temp) {y--;}
            else if(t_sum<temp) {x++;}
            else 
            {
               // ans++;
               
                int a=1;
                int b=1;
                int k=x;
               // bool chu=false;
                while(1)
                {  
                   
                   if(x<y-1) 
                   {
                    if(arr[++x]==arr[k])
                     {
                        a++;//cout<<arr[x];
                        //k++;
                     }
                    else break;
                   }
                   else break;
                    
                } 
                //cout<<y<<" "<<x<<endl;
                 k=y;
                while(1)
                {
                   if(y>x+1) 
                   { 
                    if(arr[--y]==arr[k])
                      {
                        b++;
                      }
                    else break;
                  }
                   else break;
                }
                // cout<<a<<endl;
                // cout<<b<<endl;
                ans+=a*b;
                //ans++;
                if(x==y-1) 
                {
                    if(arr[x-1]!=arr[x]&&(arr[y]!=arr[y+1]))if (arr[x]+arr[y]==num) ans++;
                    break;
                }               

            }
        }
    }
    //if(ans==0) return -1;
    return ans;
    
}


