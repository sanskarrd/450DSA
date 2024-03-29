//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
     
        unordered_set<char>s;
        for(int i=0;i<str.length();i++) {
            s.insert(str[i]);
        }
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=str.size();
        while(i<str.size()) {
            mp[str[i]]++;
            if(mp.size()==s.size()) {
                while(mp[str[j]]>1) {
                    mp[str[j]]--;
                    j++;
                }
                ans=min(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends