//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private :
    int countZero(int mid){
        int count  = 0 ;
        int denom = 5 ;
        while(mid>=denom){
            count+=mid/denom ;
            denom*=5 ;
        }
        return count  ;
    }
    public:
        int findNum(int n)
        {
            int low = 0;
            int high = 5*n ;
            int ans  = 0 ;
            while(low<=high) {
                int mid = (low+high)/2 ;
                
                int zeroes = countZero(mid) ;
                if(zeroes>=n){
                    ans = mid ;
                    high = mid-1 ;
                }
                else {
                    low = mid+1 ;
                }
            }
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends