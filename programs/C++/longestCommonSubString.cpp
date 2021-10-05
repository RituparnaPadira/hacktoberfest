// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1], result=0; // this question is same as longest common subsequence. But here when a characters goes out of
        // sequence then it can no longer be substring thus we have to start again from 0.

        // so our values will be coming in diagonals only... any diagonal... not only the main one.
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0) // if [no elts in s1 and all in s2] or [no elts in s2 and all in s1] = there is no common substring
                // so ans is 0.
                    dp[i][j]=0;

                else if(S1[i-1]==S2[j-1]) // if both the characters are same then add +1 to its diagonal elt as we get our
                // ans only along the diagonal.
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends