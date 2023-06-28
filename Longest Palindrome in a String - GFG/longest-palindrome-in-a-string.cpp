//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n = s.length() ;
         if (n<=1)
           return s  ;
        int maxLen = 1 ;
        int st = 0 ;
        for(int i = 0 ; i<n-1 ; i++){
            int l = i ;
            int r = i ;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l-- ;
                    r++ ;
                }
                else{
                    break ;
                }
            }
           int len = r-l-1 ;
         if(len>maxLen)
         {
             maxLen = len ;
             st =l+1 ;
         }
        }
        
        for(int i = 0 ; i< n-1 ; i++){
            int l = i ;
            int r = i+1 ;
            
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l-- ;
                    r++ ;
                }
                else
                break ;
            }
            int len = r-l-1 ;
            if(len>maxLen){
                maxLen = len ;
                st = l+1 ;
            }
        }
        
        return s.substr(st, maxLen) ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends