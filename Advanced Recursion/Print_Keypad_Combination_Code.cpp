// Print Keypad Combinations Code
// Send Feedback
// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf


#include <iostream>
#include <string>
#include<string.h>
using namespace std;

const char hashTable[10][5]
    = { "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz" };
 
// A recursive function to print all possible words that can
// be obtained by input number[] of size n.  The output
// words are one by one stored in output[]
void printWordsUtil(int number[], int curr_digit,
                    char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (curr_digit == n) {
        printf("%s \n", output);
        return;
    }
 
    // Try all 3 possible characters for current digir in
    // number[] and recur for remaining digits
    for (i = 0; i < strlen(hashTable[number[curr_digit]]);
         i++) {
        output[curr_digit]
            = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit + 1, output, n);
        if (number[curr_digit] == 0
            || number[curr_digit] == 1)
            return;
    }
}
 
// A wrapper over printWordsUtil().  It creates an output
// array and calls printWordsUtil()
void printWords(int number[], int n)
{
    char result[n + 1];
    result[n] = '\0';
    printWordsUtil(number, 0, result, n);
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    int number1[10];
    int number[10];
    int i=0;
    while(1)
    {
        if(num==0)break;
        number1[i]=num%10;
        num/=10;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        number[j]=number1[i-j-1];
    }
   // int n = sizeof(number) / sizeof(number[0]);
    printWords(number, i);
}
