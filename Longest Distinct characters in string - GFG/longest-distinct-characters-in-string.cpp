//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
      vector<int>v(26,0) ;
        int i = 0 ;
        int j = 0 ;
        int ans  = 0 ;
        int n = s.size();
        while(j<n){
            v[s[j]-'a']++ ;
            if(v[s[j]-'a'] ==1){
                ans = max(ans ,j-i+1);
                j++;
            }
            else{
                while(v[s[j]-'a'] >1){
                    v[s[i]-'a']-- ;
                    i++ ;
                }
                ans = max(ans ,j-i+1);
                j++ ;
            }
        }
        return ans  ;
}