// Remove Duplicates Recursively
// Send Feedback
// Given a string S, remove consecutive duplicates from it recursively.
// Input Format :
// String S
// Output Format :
// Output string
// Constraints :
// 1 <= |S| <= 10^3
// where |S| represents the length of string
// Sample Input 1 :
// aabccba
// Sample Output 1 :
// abcba
// Sample Input 2 :
// xxxyyyzwwzzz
// Sample Output 2 :
// xyzwz


void removeConsecutiveDuplicates(char *S) {
     
        // When string is empty, return 
    if (S[0] == '\0') 
        return; 
  
    // if the adjacent characters are same 
    if (S[0] == S[1]) { 
          
        // Shift character by one to left 
        int i = 0;  
        while (S[i] != '\0') { 
            S[i] = S[i + 1]; 
            i++; 
        } 
  
        // Check on Updated String S 
        removeConsecutiveDuplicates(S); 
    } 
  
    // If the adjacent characters are not same 
    // Check from S+1 string address 
    removeConsecutiveDuplicates(S + 1);
}
