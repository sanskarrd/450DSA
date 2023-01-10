//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long ans = arr[0] ;
	    long long maxPro =arr [0]  ;
	    long long minPro = arr[0] ;
	    for(int i = 1 ; i< n ; i++) 
	    {
	       if (arr[i] <0)
	       {
	           swap(maxPro,minPro) ;
	       }
	       minPro = min(minPro *arr[i] ,(long long)arr[i]) ;
	       maxPro = max(maxPro *arr[i] ,(long long)arr[i]) ;
	       ans = max(ans , maxPro) ;
	    }
	    return ans ;
	} 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends