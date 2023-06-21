//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i = 0 ;
        int j = 0 ;
        long long prod = 1 ;
        int count = 0 ;

        while(j<n){
            prod = prod* a[j];

            if (prod >= k){
                while (prod >= k && j>=i){
                prod= prod/a[i] ;
                i++;
                }
            }

            if (prod< k){
                count= count + j-i+1;
            }
            j++ ;
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends