//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
 
	int minDifference(int arr[], int n)  { 
	    int sum = 0 ;
	    for(int i = 0 ; i< n ; i++){
	        sum+=arr[i] ;
	    }
	   
	   vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
	   
	   for(int i = 0 ; i< n ; i++){
	       dp[i][0] = 1 ;
	       if(arr[0] <=sum)
	       dp[0][arr[0]] = 1 ;
	   }
	  
	    for(int ind  = 1 ; ind< n ;ind++){
	       for(int target = 1 ; target<=sum ; target++){
	               bool notTake  = dp[ind-1][target];
                   bool take = false;
                   if(arr[ind]<=target)
                   take =  dp[ind-1][target- arr[ind]];
                   dp[ind][target]  = take | notTake ;
	           }
	       }
	   
	   
	   int mini = 1e9 ;
	   for(int p = 0 ; p <= sum/2 ; p++){
	       if(dp[n-1][p]){
	           mini = min(mini,abs((sum-p) - p)) ;
	       }
	   }
	   return mini ;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends