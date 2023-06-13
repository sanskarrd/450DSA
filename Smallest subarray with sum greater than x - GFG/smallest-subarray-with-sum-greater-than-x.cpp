//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        
        int i = 0 ;
        int j = 1 ;
        int sum = arr[0] ; 
        int len = INT_MAX ;
        
        while(j<=n){
            if(sum>x){
                int c1 = j-i ;
                len = min(len ,c1) ;
                sum-=arr[i] ;
                i++ ;
            }
            
            
            if(sum<=x){
                sum+=arr[j] ;
                j++ ;
            }
        }
        
        return len ;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends