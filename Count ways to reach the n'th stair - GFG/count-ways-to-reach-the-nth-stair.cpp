//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int n,vector<int>&dp){
        int mod = (1e9+7) ;
        if(n<0){
            return 0 ;
        }
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return n ;
        }
        if(dp[n]!=-1){
            return dp[n] ;
        }
        
       return dp[n] = (solve(n-1,dp)%mod + solve(n-2,dp)%mod)%mod;
    }
    int countWays(int n)
    {
       vector<int>dp(n+1,-1) ;
       int ans = solve(n,dp) ;
       return ans ;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends