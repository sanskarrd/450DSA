//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int low = 0 ;
        int high = n-1 ;
        if(arr[low]<=arr[high]){
            return arr[low] ;
        }
        while(low<=high){
            int mid = low+ ((high-low)/2) ;
            if(arr[mid-1] > arr[mid]){
                return arr[mid] ;
            }
            else if(arr[mid] > arr[high]) {
                low = mid+1 ;
            }
            else {
                high =mid-1 ;
            }
        }
        return -1 ;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends