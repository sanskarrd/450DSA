//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> leftSmaller(int n, long long a[]){
        // code here
        stack<long long> s ;
        vector<long long> ans(n) ;
        s.push(-1) ;
        for(int i = 0 ; i<n ; i++){
            
            while( s.top()!= -1 && a[s.top()]>=a[i]){
                s.pop() ;
            }
            if(s.empty()){
                ans[i] = -1 ;
            }
            else{
                ans[i] = s.top()  ;
                s.push(i) ;
            }
        }
        return ans ;
    }
    
    
     vector<long long> rightSmaller(int n, long long a[]){
        // code here
        stack<long long> s ;
        vector<long long> ans2(n) ;
        s.push(-1) ;
        for(int i = n-1; i>=0 ; i--){
            
            while( s.top() != -1 && a[s.top()]>=a[i]){
                s.pop() ;
            }
            if(s.empty()){
                ans2[i] = -1 ;
            }
            else{
                ans2[i] = s.top() ;
                s.push(i) ;
            }
        }
        return ans2 ;
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here 
        long long area ;
        area = INT_MIN ;
        vector<long long>l = leftSmaller(n,arr) ;
        
        vector<long long>r = rightSmaller(n,arr);
        
        for(int i = 0 ; i < n ; i++){
            long long len  = arr[i] ;
            
           
            if(r[i] == -1){
                r[i] = n;
            }
            long long width = r[i] - l[i] - 1  ;
            long long currArea = len * width ;
            
            area = max(area,currArea) ;
        }
        
        return area ;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends