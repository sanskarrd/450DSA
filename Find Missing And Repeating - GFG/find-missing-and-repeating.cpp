//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       unordered_map<int,int> m ;
       int repeat = 0 ;
       for(int i=0 ; i<n;i++){
           m[arr[i]]++ ;
         if(m[arr[i]]==2){
           repeat =arr[i] ;
       }
       }
       int missing = 0;
     for(int i = 1 ;i<=n;i++){
         if(m[i]==0){
             missing =i;
             break ;
         }
     }
       int ans[2] ={repeat,missing} ;
       int *answer = ans ;
       return answer ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends