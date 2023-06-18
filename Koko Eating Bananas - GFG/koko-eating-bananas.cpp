//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
 bool isValid(int mid, int n, int h, vector<int>& piles) {
    int times = 0;

    for (int i = 0; i < n; i++) {
        if (piles[i] <= mid) {
            times++;
        }
        else {
            int hours = piles[i] / mid;  // Number of complete hours needed for this pile
            int remaining = piles[i] % mid;  // Remaining bananas after complete hours

            times += hours;

            if (remaining > 0) {
                times++;
            }
        }
    }

    if (times <= h) {
        return true;
    }
    else {
        return false;
    }
}


    int Solve(int n, vector<int>& piles, int h) {
        sort(piles.begin(),piles.end()) ;
         if(n== h){
             return *max_element(piles.begin(),piles.end());
         }
         
         int low = 1;
         int high = *max_element(piles.begin(),piles.end());
         int ans = 0 ;
         while(low<=high){
             
             int mid = low+(high-low)/2 ;
             if(isValid(mid,n,h,piles)){
                 high = mid-1;
                 ans  = mid ;
             }
             else{
                 low = mid+1 ;
             }
         }
         return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends