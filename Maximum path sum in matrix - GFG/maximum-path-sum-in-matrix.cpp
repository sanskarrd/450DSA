//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solve(int i , int j ,vector<vector<int>> &matrix,vector<vector<int>>&dp){
       int n = matrix.size() ;
       if(i<0 || j<0 || j>=n){
           return 0 ;
       }
       if(i==0){
           return matrix[i][j] ;
       }
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       
       int up = matrix[i][j] + solve(i-1,j,matrix,dp) ;
       int diagLeft = matrix[i][j] + solve(i-1,j-1,matrix,dp);
       int diagRight = matrix[i][j] + solve(i-1,j+1,matrix,dp) ;
       
          dp[i][j] =  max(up,max(diagLeft,diagRight)) ;
          return dp[i][j] ;
       }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        int ans = -1 ;
        vector<vector<int>>dp(n,vector<int>(n,-1)) ;
        for(int i = 0 ; i<n ;i++){
            ans = max(ans,solve(n-1,i,matrix,dp));
        }
        return ans ;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends