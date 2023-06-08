//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> final ;
        for(int i = 0 ; i< n; i++){
            final.push_back(arr1[i]) ;
        }
        
        for(int j = 0 ; j < m ; j++){
            final.push_back(arr2[j]) ;
        }
        sort(final.begin() , final.end()) ;
        int ans = -1 ;
        for(int i = 0 ; i< (n+ m ); i++){
            ans = final[k-1] ;
        }
        return ans  ;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends