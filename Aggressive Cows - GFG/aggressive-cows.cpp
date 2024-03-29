//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPlace(int n ,int k, int mid , vector<int>&stalls){
        int cow = stalls[0];
        int cnt = 1 ;
        
        for(int i = 1; i<n ; i++){
            if(stalls[i]-cow >= mid){
                cnt++ ;
                cow = stalls[i];
            }
            
            if(cnt == k){
                return true ;
            }
        }
        return false ;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
           int low = 1 ;
           int high = stalls[n-1] - stalls[0];
           int ans = INT_MIN;
           while(low<=high){
               int mid = low +(high-low)/2;
               
               if(canPlace(n,k,mid,stalls)){
                   ans = max(ans , mid);
                   low = mid+1 ;
               }
               else{
                   high = mid-1 ;
               }
           }
           
           return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends