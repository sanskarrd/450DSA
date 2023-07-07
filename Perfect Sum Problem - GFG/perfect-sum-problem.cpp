//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int ind ,int target,int arr[],vector<vector<int>>&dp){
       if(ind ==0){
          if(target==0 && arr[0] ==0){
              return 2 ;
          }
          if(target ==0 || target ==arr[0]){
               return 1 ;
           }
           else{
               return 0 ;
           }
       }
   
       if(dp[ind][target] != -1){
           return dp[ind][target] ;
       }
       int notTake  = solve(ind-1,target,arr,dp);
       int take = 0;
       if(arr[ind]<=target)
       take =  solve(ind-1 , target- arr[ind],arr,dp);
       
       return dp[ind][target]  = (take + notTake)%(int)(1e9+7) ;
       
   }
   
	int perfectSum(int arr[], int n, int sum)
	{
        
        vector<vector<int>>dp(n+1 ,vector<int>(sum+1,-1)) ;
        return  solve(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends