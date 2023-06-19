//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        long long sum = 0 ;
        for(int i = 0 ; i< k ; i++){
            sum += cardPoints[i] ;
        }
        
        int i  = k-1 ;
        int j = n-1 ;
        long long ans = sum ;
        while(i>= 0){
            sum = sum -cardPoints[i] +cardPoints[j] ;
            ans  = max(sum,ans) ;
            i --;
            j-- ;
        }
        
        return ans  ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends