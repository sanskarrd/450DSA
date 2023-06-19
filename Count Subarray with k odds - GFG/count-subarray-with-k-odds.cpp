//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
       unordered_map<int,int>mp ;
      
       for(int i = 0 ; i< n ; i++){
           if(nums[i]%2 == 1){
               nums[i] = 1 ;
           }
           else{
               nums[i] = 0 ;
           }
       }
       int j = 0 ;
       int cnt = 0;
       int sum = 0 ;
       while(j<n){
           sum+=nums[j] ;
           
           if(sum == k){
               cnt ++ ;
           }
           if(mp.find(sum-k) != mp.end()){
               cnt +=mp[sum-k] ;
               
           }
           mp[sum]++ ;
           j ++ ;
           
       }
       return cnt ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends