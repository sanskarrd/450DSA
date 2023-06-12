//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        
        int i=0;
        int j=1;
        int s=arr[0];
        int c=INT_MAX;
        while(j<=n){
            if(s>x){
                int c1=j-i;
                if(c1<c){
                    c=c1;
                }
                
                s-=arr[i++];
                
            }
            else if(s<=x){
                s+=arr[j++];
            }
        }
        
        return c;
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