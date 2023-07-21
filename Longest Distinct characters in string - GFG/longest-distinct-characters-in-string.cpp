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
      int n = s.size();
        unordered_map <char,int> mp;
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]] == 2){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    mp.erase(s[j]);
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
}