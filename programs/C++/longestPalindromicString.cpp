// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=jCOJk4UyO8w

 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here

        /* 
        
here the palindrome can be of even length or odd length.

if it is of even length then we have to find 2 same chars which are side-side and from there we move 1 pointer towards right
and other pointer towards left - to expand this palindrome if possible. also we keep track of start of longest palindromic substring
and its length to print the string.
low=i-1
high=i


if it is of odd length then we will have 1 extra char in the middle of 2 same characters. like aca
same as above case we move 1 ptr to left and other to right to expand this palindrome. also we keep track of start of longest palindromic substring
and its length to print the string.
low=i-1
high=i+1
so at ith position we have extra character.


        */
        
        int len = S.length(), low, high, start, maxLength=1; 
        // maxLength: stores maximum length of palindrome seen till now.
    
        for(int i=1;i<len;i++) // for each length of string we have to check both even and odd length palindromes.
        // max length palindrome can be of even or odd length.
        {
            low=i-1; // even length case.
            high=i; // low+1 = high... for even case.
            while(low>=0 && high<len && S[low]==S[high])
            {
                if(maxLength<high-low+1) // for finding max length.
                {
                    maxLength=high-low+1; // length = high-low+1
                    start=low; // find the start of longest palindromic string.
                }
                --low; // move low ptr to left.
                ++high; // move high ptr to right.
            }
            
            // in string we may have even lg and odd lg palindromes, but in those we want max length one. so we first consider
            // even case and then odd case for each character and consider maxLength one.
            
            low=i-1; // odd length case.
            high=i+1; // low+2 = high ... for odd case.
            while(low>=0 && high<len && S[low]==S[high])
            {
                if(maxLength<high-low+1)// for finding max length.
                {
                    maxLength=high-low+1;// length = high-low+1
                    start=low;// find the start of longest palindromic string.
                }
                --low; // move low ptr to left.
                ++high;// move high ptr to right.
            }
            
        }
        
        string res="";
        for(int i=start;i<start+maxLength;i++)
            res+=S[i];
        
        return res;
    }
};
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}