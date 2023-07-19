//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(int i , int j ,string s1,string s2,vector<vector<int>>&dp){
         if(i==0 || j==0){
             return 0 ;
         }
         if(dp[i][j] != -1){
             return dp[i][j] ;
         }
         if(s1[i-1] == s2[j-1]){
             return 1+ solve(i-1,j-1,s1,s2,dp) ;
         }
         
         return dp[i][j] = max(solve(i-1,j,s1,s2,dp) , solve(i,j-1,s1,s2,dp)) ;
     }
    int longestPalinSubseq(string A) {
        int n = A.size() ; 
        string B  = A;
        reverse(B.begin(),B.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
        return solve(n,n,A,B,dp) ;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends