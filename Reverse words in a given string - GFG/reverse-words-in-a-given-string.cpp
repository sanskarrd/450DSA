//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
          
        int end = s.length()-1;
    string ans = "" ;
    for(int i = s.length()-1 ; i>=0 ; i--)
    {
        if(s[i] == '.')
        {
            ans+= s.substr(i+1, end - (i + 1) + 1);
            ans+= '.';
            end = i-1 ;
        }
    }
    if (ans.empty()) return s; 
    ans += s.substr(0,end+1) ;
    return ans ;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends