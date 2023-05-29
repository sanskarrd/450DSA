//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        // code here
        int pos ;
        int k = n ;
        while(k!=0){
            pos++ ;
            if(k&1 == 1){
                break ;
                        }
            k = k>>1 ;
        }
        int cnt = 0 ;
        while(n!=0){
            if(n&1 ==1 ){
                cnt ++ ;
            }
            n = n>> 1 ;
        }
        
        if(cnt ==1){
            return pos ;
        }
        else
        return -1 ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends