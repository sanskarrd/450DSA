//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int n) {
        
        int dest = n-1 ;
        for(int i = n-2 ; i>=0 ; i--){
            if(A[i] + i >=dest){
                dest = i ;
            }
        }
        if(dest ==0){
            return 1 ;
        }
        else{
            return 0 ;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends