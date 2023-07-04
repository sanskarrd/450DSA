//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int N,vector<int>&dp){
	    
    if (N == 1) {
        return 0;
    }
    if(dp[N]!=-1){
        return dp[N] ;
    }
    int step1 = INT_MAX;
    int step2 = INT_MAX;
    int step3 = INT_MAX;

    if (N % 2 == 0)
        step1 = 1 + solve(N / 2,dp);
    if (N % 3 == 0)
        step2 = 1 + solve(N / 3,dp);
    
    step3 = 1 + solve(N - 1,dp);

    dp[N] =min(step1, min(step2, step3));
    return dp[N] ;
	}
	int minSteps(int N) 
	{ 
	    vector<int>dp(N+1,-1) ;
	    return solve(N,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends