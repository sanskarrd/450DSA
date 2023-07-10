//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string A){
        int n = A.size() ; 
        string B  = A;
        reverse(B.begin(),B.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
        
        
        for(int i = 0 ; i<=n ; i++) dp[i][0] = 0 ;
        for(int j = 0 ; j<=n ; j++) dp[0][j] = 0 ; 
        
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<= n ; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j]  = 1 + dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        int cnt  =  dp[n][n] ;
        
        return n-cnt  ;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends