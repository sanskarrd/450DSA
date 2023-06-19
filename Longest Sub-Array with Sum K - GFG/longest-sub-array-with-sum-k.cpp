//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> sumMap;  // Map to store sum and its index
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        if (sum == K) {
            maxLength = i + 1;
        }

        if (sumMap.find(sum - K) != sumMap.end()) {
            maxLength = max(maxLength, i - sumMap[sum - K]);
        }

        if (sumMap.find(sum) == sumMap.end()) {
            sumMap[sum] = i;
        }
    }

    return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends