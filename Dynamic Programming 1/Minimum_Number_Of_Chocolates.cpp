// Minimum Number of Chocolates
// Send Feedback
// Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.
// Note :
// When two students have an equal score, they are allowed to have a different number of chocolates. 
// Input Format:
// The first line of the input contains an integer value of N. It denotes the total number of students in Noor's class.

// The second line of the input contains N integer values denoting the score of each of the students. A single space will separate them.
// Output Format:
// Print the minimum number of chocolates Noor must give.
// Constraints
// 1 <= N <= 10^5
// 1 <= score <= 10^5

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 1 4 4 6
// Sample Output 1 :
// 6
// Explanation:
// One of the ways in which the chocolates can be distributed, such Noor has to give minimum number of chocolates, are: The first student can be given one chocolate, second student can be given two chocolates, third student can be one chocolate and fourth can be given two chocolates.  
// Sample Input 2 :
// 3
// 8 7 5
// Sample Output 2 :
// 6


int getMin(int *arr, int n)
{
	int ans[n];
   for(int i=0;i<n;i++) ans[i]=0;
   	int j;
   
   for(int i=1;i<n;)
   { 
   	 //cout<<"*"<<i<<"*"<<endl;
     if(arr[i]>arr[i-1])
     {  
     	j=1;
     	j++;
     	i++;
     	while(arr[i-1]<arr[i]&&i<n){i++;j++;}
     	//cout<<i<<"a"<<j<<endl<<endl;
     	int tem=j;
     	//j//--;
     	// i=5, j=3,
     	for(int k=i-1;k>=i-j;k--){ans[k]=tem;tem--;}
     	//i--;
     }
     
     else if(arr[i]==arr[i-1])
     {
         j=0;
         j++;
         i++;
         while(arr[i-1]==arr[i]&&i<n){i++;j++;}
         //cout<<i<<"b"<<j<<endl<<endl;
         if(ans[i-j-1]==0) ans[i-j-1]=1;
         for(int k=i-1;k>=i-j;k--){ans[k]=1;}
     }
     
     else
     {   
     	 j=1;
     	 int tem=1;
     	 j++;
         i++;
         while(arr[i-1]>arr[i]&&i<n){i++;j++;}
         //cout<<i<<"c"<<j<<endl<<endl;
         ans[i-j]=max(ans[i-j],j);
         for(int k=i-1;k>i-j;k--){ans[k]=tem;tem++;}
         //i--;
     }
   }
   int out=0;
   for(int i=0;i<n;i++)
   {
   	  out+=ans[i];
   	  //cout<<ans[i]<<" ";
   }
   //cout<<endl;
   return out;
}
