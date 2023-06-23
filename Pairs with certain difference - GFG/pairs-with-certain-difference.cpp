//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
         sort(arr,arr+n,greater<int>());
         int sum=0;
         int i=0;
         while(i<n-1)
         {
             if(abs(arr[i]-arr[i+1])<k)
             {
                 sum=sum+arr[i]+arr[i+1];
                 i=i+2;
             }
             else
             {
                 i++ ;
             }
         }
         
         return sum ;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends