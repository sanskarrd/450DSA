//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int i = 0 ;
void solve(int arr[], int N ,int mini ,int maxi){
    if(i>=N  || arr[i] < mini || arr[i] > maxi ){
        return ;
    }
    
    int temp = i;
    i++ ;
    solve(arr,N,mini,arr[temp]);
    solve(arr,N,arr[temp],maxi);
}
    int canRepresentBST(int arr[], int N) {
        
       int mini = INT_MIN ;
       int maxi = INT_MAX ;
       
       solve(arr,N,mini,maxi) ;
       if(i<N){
           return 0 ;
       }
       return 1 ;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends