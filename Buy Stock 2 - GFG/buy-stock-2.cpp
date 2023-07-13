//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // long long solve(vector<long long>&prices,long long ind,long long buy,int n,vector<vector<long long>>&dp){
    //     if(ind == n){
    //         return 0 ;
    //     }
    //     if(dp[ind][buy] != -1){
    //         return dp[ind][buy] ;
    //     }
    //     long long profit = 0 ;
    //     if(buy){
    //         profit = max((-prices[ind] + solve(prices,ind+1,0,n,dp)) , (solve(prices,ind+1,1,n,dp)));
    //     }
    //     else{
    //         profit = max((prices[ind]+solve(prices,ind+1,1,n,dp)) , solve(prices,ind+1,0,n,dp)) ;
    //     }
    //     return dp[ind][buy] = profit ;
    // }
    long long maximumProfit(vector<long long>&prices, int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        long long ind = 0 ;
        long long buy = 1 ;
        // return solve(prices,ind,buy,n,dp) ;
        
        dp[n][0] = 0 ;
        dp[n][1] = 0 ;
        for(int ind = n-1 ; ind>=0 ; ind--){
            for(int buy = 0 ; buy<=1 ; buy++){
                
               long long profit = 0 ;
        if(buy){
            profit = max(-prices[ind]+dp[ind+1][0] , dp[ind+1][1]);
        }
        else{
            profit = max(prices[ind]+dp[ind+1][1] , dp[ind+1][0]) ;
        }
         dp[ind][buy] = profit ;
            
        }
        }
        long long ans= dp[0][1] ;
        return ans ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends