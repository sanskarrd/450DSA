//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
 bool isValid(int arr[], int n, int k, long long time) {
    int painter = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > time) {
            painter++;
            sum = arr[i];
        }
    }
    return (painter <= k);
}

long long minTime(int arr[], int n, int k) {
    if (k >= n) {
        return *max_element(arr, arr + n);
    }
    long long ans = 0;
    long long low = *max_element(arr, arr + n);
    long long high = 0 ;
    for(int i= 0 ; i< n ; i++){
        high+=arr[i];
    }

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(arr, n, k, mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends