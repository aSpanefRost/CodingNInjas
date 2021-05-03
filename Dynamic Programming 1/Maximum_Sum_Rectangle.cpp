// Maximum Sum Rectangle
// Send Feedback
// Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
// Input
// First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
// Output
// Output a single integer, maximum sum rectangle.
// Constraints
// 1<=n,m<=100
// Sample Input
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6
// Sample Output
// 29


#include<iostream> #include<cmath> #include<climits> #include<vector> #include<string> #include<cstring> #include<set> #include<algorithm> #include<utility> #include<map> #include<unordered_map> #include<sstream> //#include<cstdlib> using namespace std; #define fo(i,n) for(int i=0;i<n;i++) #define vi vector<int> #define lli long long int #define mem(a,n) memset(a,n,sizeof(a)) #define de(x) cout<<"*"<<x<<"*"<<endl const int mod=1000000007; int kadane(int arr[],int n) { int local_maximum=arr[0]; int gloabl_maximum=arr[0]; int temp; for(int i=1;i<n;i++) { temp=local_maximum+arr[i]; local_maximum=max(arr[i],temp); if(local_maximum>gloabl_maximum) gloabl_maximum=local_maximum; } return gloabl_maximum; } int main() { // #ifndef ONLINE_JUDGE // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout); // #endif int col,row; cin>>row>>col; int arr[row][col]; for(int i=0;i<row;i++) for(int j=0;j<col;j++) cin>>arr[i][j]; int sum[row]; int max=INT_MIN; for(int i=0;i<col;i++) { memset(sum,0,sizeof(sum)); for(int j=i;j<col;j++) { for(int k=0;k<row;k++) sum[k]+=arr[k][j]; //de(arr[1][0]); // fo(k,row) cout<<sum[k]<<" "; // cout<<endl; if(max<kadane(sum,row)) max=kadane(sum,row); // cout<<max<<" "; } //cout<<endl; } cout<<max; return 0; }
