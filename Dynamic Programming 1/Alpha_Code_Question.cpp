// AlphaCode-Question
// Send Feedback
// Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
// Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

// Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

// Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

// Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

// Alice: “How many different decodings?”

// Bob: “Jillions!”
// For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
// Input
// Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
// Output
// For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
// Sample Input:
// 25114
// 1111111111
// 3333333333
// 0
// Sample Output:
// 6
// 89
// 1

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
//#include<cstdlib>
using namespace std;
 
// #define fo(i,n) for(int i=0;i<n;i++)
// #define vi vector<int>
// #define lli long long int
// #define mem(a,n) memset(a,n,sizeof(a))
// #define de(x) cout<<"*"<<x<<"*"<<endl
const int mod=1000000007;

// lli rec(string s,int size,lli arr[])
// {
//     if(size==1) return 1;
//     if(size==0) return 1;
    
//     if(arr[size]>0) return arr[size];
//    if((s[size-1]-'0'!=0)) arr[size]=rec(s,size-1,arr)%mod;
//     if(((s[size-2]-'0')!=0)&&(s[size-2]-'0')*10+(s[size-1]-'0')<=26) 
//       arr[size]+=rec(s,size-2,arr)%mod;
//     return arr[size];

// }

// int main()
// {
 
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif
    
//     while(1)
//     {
//     string s;
//     cin>>s;
//     lli arr[s.size()+1];
//     //fo(i,2) arr[i]=1;
//     mem(arr,0);
//     if((s.size()==1)&&(s[0]=='0')) return 0;
//     else {cout<<rec(s,s.size(),arr)<<endl;}
//     //else cout<<s<<endl;

//     }
//     return 0;
  
// }
int main(){
	int L;
	char d[5001];
	long long dp[5001];
	
	while(true){
		scanf("%s",d);
		if(d[0]=='0') break;
		
		L = strlen(d);
		
		dp[0] = dp[1] = 1;
		
		for(int i = 2;i<=L;++i){
			dp[i] = 0;
			
			char c1 = d[i-2]-'0', c2 = d[i-1]-'0';
			
			if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2]%mod;
			if(c2!=0) dp[i] += dp[i-1]%mod;
		}
		
		printf("%lld\n",dp[L]);
	}
	
	return 0;
}


//Original Solution

#include<bits/stdc++.h> #define mod 1000000007 using namespace std; int main() { //freopen("input6.txt", "r", stdin); //freopen("output6.txt", "w", stdout); string s; int n, i, x; long long int A[5001]; while(1) { cin>>s; if(s=="0") break; n=s.size(); for(i=0;i<5000;i++) A[i]=0; A[0]=1; for(i=1;i<n;i++) { x=(s[i-1]-'0')*10+s[i]-'0'; if(s[i]!='0') A[i]=A[i-1]; if(x>=10&&x<=26&&i>1) A[i]+=A[i-2]; else if(x>=10&&x<=26) A[i]++; A[i]=A[i]%mod; } cout<<A[n-1]<<endl; } return 0; }
