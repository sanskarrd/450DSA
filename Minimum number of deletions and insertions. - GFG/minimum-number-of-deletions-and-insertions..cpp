//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s1, string s2) 
	{ 
	    int n = s1.size() ;
	    int m = s2.size() ;
	     vector<vector<int>>dp(n+1,vector<int>(m+1,-1)) ;
        for(int i = 0 ; i<=n ; i++) dp[i][0] = 0 ;
        for(int j = 0 ; j<=m ; j++) dp[0][j] = 0 ;
        
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<=m ; j++){
                  if(s1[i-1] == s2[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1] ;
                   }
            else
            dp[i][j] =  max(dp[i-1][j] , dp[i][j-1]) ;
            }
        }
        int cnt = dp[n][m] ;
        int ans = (n-cnt)+(m-cnt) ;
        return ans ;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends