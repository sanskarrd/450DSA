//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        int i = 0 ;
        int j = 0 ;
        int cnt  = 0 ;
        int n = s.size() ;
        unordered_map<char,int>mp ;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==3){
                while(mp.size() ==3){
                    mp[s[i]]-- ;
                    cnt += (n-j);
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]) ;
                    }
                    i++;
                }
            }
            j++;
        }
        return cnt ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends